#include "framework.hpp"

int Framework::init(int argc, char *argv[]) {
	LOG_RESET();
	LOG("--------------------- LOG BEGIN ---------------------");

	// ------------------------------------------
	// CREATE BUILDER AND APPLICATION
	// ------------------------------------------

	LOG("-- Create Application");

	this->widgets.app = Gtk::Application::create(argc, argv);

	// ------------------------------------------
	// CREATE WINDOW FOR THE PACKAGEMANAGER
	// ------------------------------------------

	LOG("-- Init SplashScreen");

	this->widgets.splash_screen.window = new Gtk::Window;
	this->widgets.splash_screen.window->set_default_size(640, 315);
	this->widgets.splash_screen.window->set_icon_from_file(DATA("Icon.svg"));
	this->widgets.splash_screen.window->set_type_hint(Gdk::WINDOW_TYPE_HINT_SPLASHSCREEN);
	this->widgets.splash_screen.window->set_name("splash_screen");

	Gtk::VBox * box = new Gtk::VBox;
	box->set_border_width(10);

	Gtk::Label * title = new Gtk::Label;
	title->set_markup("<span font='42'>LibreTextus</span>");
	this->widgets.splash_screen.header_label = new Gtk::Label("Test");
	this->widgets.splash_screen.info_label = new Gtk::Label("Test");
	this->widgets.splash_screen.spinner = new Gtk::Spinner;
	this->widgets.splash_screen.spinner->set_size_request(70, 70);

	box->pack_start(*title, Gtk::PACK_EXPAND_WIDGET, 0);
	box->pack_start(*this->widgets.splash_screen.header_label, Gtk::PACK_SHRINK, 5);
	box->pack_start(*this->widgets.splash_screen.info_label, Gtk::PACK_SHRINK, 0);
	box->pack_start(*this->widgets.splash_screen.spinner, Gtk::PACK_SHRINK, 10);

	this->widgets.splash_screen.window->add(*box);

	// ------------------------------------------
	// ADD CSS FILE AND LOAD IT
	// ------------------------------------------

	LOG("-- Load Css");

	this->widgets.style.css = Gtk::CssProvider::create();
	if(!this->widgets.style.css->load_from_path(DATA(this->settings.get<std::string>("theme-active") + ".css"))) {
			std::cerr << "Failed to load css\n";
			return 1;
	}

	this->widgets.style.font_size = this->settings.get<int>("font_size");
	this->widgets.style.font_size_css = Gtk::CssProvider::create();
	this->widgets.style.font_size_css->load_from_data(
		"* { font-size: " + std::to_string(this->widgets.style.font_size) + "px; }"
	);

	Glib::RefPtr<Gdk::Screen> screen = Gdk::Screen::get_default();
	this->widgets.style.style = this->widgets.splash_screen.window->get_style_context();
	this->widgets.style.style->add_provider_for_screen(screen, this->widgets.style.css, GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
	this->widgets.style.style->add_provider_for_screen(screen, this->widgets.style.font_size_css, GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

	// ------------------------------------------
	// CONNECT SIGNALS TO THE DISPATCHERS
	// ------------------------------------------

	LOG("-- Connect Signals");

	this->widgets.splash_screen.text_dispatcher.connect([this]() {
		this->widgets.splash_screen.mutex.lock();
		this->widgets.splash_screen.header_label->set_text(this->widgets.splash_screen.header_string);
		this->widgets.splash_screen.info_label->set_text(this->widgets.splash_screen.info_string);
		this->widgets.splash_screen.mutex.unlock();
	});

	this->widgets.package_manager.update_text.connect([this]() {
		this->widgets.package_manager.mtx.lock();
		this->widgets.splash_screen.header_label->set_text(this->widgets.package_manager.header_string);
		this->widgets.splash_screen.info_label->set_text(this->widgets.package_manager.info_string);
		this->widgets.package_manager.mtx.unlock();
	});

	// ------------------------------------------
	// THIS FOLLOWING SIGNAL WILL BE CALLED AFTER
	// THE APPLICATION STARTED IT WILL UPDATE
	// THE PACKAGES AND THEN EMIT A DISPATCHER
	// SIGNAL FOR OPENING A NEW SESSION
	// ------------------------------------------

	this->widgets.app->signal_startup().connect([this]() {

		this->widgets.app->add_window(*this->widgets.splash_screen.window);

		this->widgets.splash_screen.window->set_position(Gtk::WIN_POS_CENTER);
		this->widgets.splash_screen.spinner->start();
		this->widgets.splash_screen.window->show_all();

		LOG("--> \"startup\" emmited");
		this->widgets.processing.update_thread = Glib::Thread::create([this]() {

			// ------------------------------------------
			// CHECK FOR UPDATES
			// ------------------------------------------

			this->widgets.package_manager.init();

			// ------------------------------------------
			// INITIALIZE SIGNALHANDLER
			// ------------------------------------------

			this->signal_handler.init(&this->widgets);

			// ------------------------------------------
			// START SESSION
			// ------------------------------------------

			this->widgets.processing.start_session.emit();

		});
	});

	// ------------------------------------------
	// THIS DISPATCHER IS CALLED AFTER THE
	// UPDATE THREAD HAS DONE HIS WORK
	// ------------------------------------------

	this->widgets.processing.start_session.connect([this]() {

		if (this->widgets.processing.update_thread->joinable()) {
			this->widgets.processing.update_thread->join();
		}

		// ------------------------------------------
		// CREATING THE WINDOWS
		// ------------------------------------------

		LOG("-- Create Main Window");

		Libre::MainWindow::create(&this->widgets, &this->signal_handler);

		LOG("-- Create Properties Window");

		Libre::PreferencesWindow::create(&this->widgets, &this->signal_handler);

		this->widgets.dialog.window = nullptr;

		LOG("--> \"start_session\" emmited");

		// ------------------------------------------
		// LOAD NOTEBOOK FILE
		// ------------------------------------------

		if (!std::experimental::filesystem::exists(HOME(this->widgets.settings.get<std::string>("notebook")))) {
			std::ofstream fout(HOME(this->widgets.settings.get<std::string>("notebook")));
			fout << "# LibreTextus Notes\n---" << std::endl;
			fout.close();
		}

		YAML::Node n = YAML::LoadFile(HOME(this->widgets.settings.get<std::string>("notebook")));

		this->widgets.main.text_view->set_note_book(n);
		this->widgets.main.note_book->set_file(n,
			HOME(this->widgets.settings.get<std::string>("notebook"))
		);

		this->widgets.app->add_window(*this->widgets.main.window);
		this->widgets.app->remove_window(*this->widgets.splash_screen.window);
		this->widgets.main.window->show_all();

		this->widgets.splash_screen.window->hide();
		this->widgets.splash_screen.spinner->stop();

		this->widgets.main.text_view->show_information();
		this->signal_handler.sync_enabled_sources();
		this->widgets.main.search_entry->grab_focus();
	});

	// ------------------------------------------
	// CONNECT FOLLOWING DISPATCHERS:
	// * SET_TEXT_DISPACHER:
	//		- SET TEXT_BUFFER FROM NON-GUI-THREAD
	// * DELETE_THREAD_DISPATCHER:
	//		- DELETE FINISHED THREAD
	// ------------------------------------------

	this->widgets.processing.set_text_dispatcher.connect(sigc::mem_fun(this->signal_handler, &SignalHandler::set_text));
	this->widgets.processing.delete_thread_dispatcher.connect(sigc::mem_fun(this->signal_handler, &SignalHandler::delete_thread));
	this->widgets.processing.sync_sources_dispatcher.connect(sigc::mem_fun(this->signal_handler, &SignalHandler::sync_enabled_sources));


	return 0;
}

void Framework::run() {

	LOG("-- Run Application");

	if (this->widgets.main.window) {
		this->widgets.app->run();
	} else {
		std::cerr << "ERROR: UNABLE TO RUN APPLICATION" << '\n';
	}

	LOG("--------------------- LOG END ---------------------");
}
