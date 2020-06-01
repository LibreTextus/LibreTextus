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
	// CREATING THE WINDOWS
	// ------------------------------------------

	LOG("-- Create Main Window");

	Libre::MainWindow::create(&this->widgets, &this->signal_handler);

	LOG("-- Create Properties Window");

	Libre::PreferencesWindow::create(&this->widgets, &this->signal_handler);

	this->widgets.dialog_window = nullptr;

	// ------------------------------------------
	// ADD CSS FILE AND LOAD IT
	// ------------------------------------------

	LOG("-- Load Css");

	this->widgets.css = Gtk::CssProvider::create();
	if(!this->widgets.css->load_from_path(DATA(this->settings.get<std::string>("theme-active") + ".css"))) {
			std::cerr << "Failed to load css\n";
			return 1;
	}

	this->widgets.font_size = this->settings.get<int>("font_size");
	this->widgets.font_size_css = Gtk::CssProvider::create();
	this->widgets.font_size_css->load_from_data(
		"* { font-size: " + std::to_string(this->widgets.font_size) + "px; }"
	);

	Glib::RefPtr<Gdk::Screen> screen = Gdk::Screen::get_default();
	this->widgets.style = this->widgets.window->get_style_context();
	this->widgets.style->add_provider_for_screen(screen, this->widgets.css, GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
	this->widgets.style->add_provider_for_screen(screen, this->widgets.font_size_css, GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

	this->widgets.window->show_all();

	// ------------------------------------------
	// CREATE WINDOW FOR THE PACKAGEMANAGER
	// ------------------------------------------

	LOG("-- Init PackageManager");

	this->widgets.package_manager.window = new Gtk::Window;
	this->widgets.package_manager.window->set_default_size(640, 315);
	this->widgets.package_manager.window->set_icon_from_file(DATA("Icon.svg"));
	this->widgets.package_manager.window->set_type_hint(Gdk::WINDOW_TYPE_HINT_SPLASHSCREEN);
	this->widgets.package_manager.window->set_name("splash_screen");

	Gtk::VBox * box = new Gtk::VBox;
	box->set_border_width(10);

	Gtk::Label * title = new Gtk::Label;
	title->set_markup("<span font='42'>LibreTextus</span>");
	this->widgets.package_manager.main_info = new Gtk::Label("Test");
	this->widgets.package_manager.subtitle = new Gtk::Label("Test");
	this->widgets.package_manager.spinner = new Gtk::Spinner;
	this->widgets.package_manager.spinner->set_size_request(70, 70);

	box->pack_start(*title, Gtk::PACK_EXPAND_WIDGET, 0);
	box->pack_start(*this->widgets.package_manager.main_info, Gtk::PACK_SHRINK, 0);
	box->pack_start(*this->widgets.package_manager.subtitle, Gtk::PACK_SHRINK, 0);
	box->pack_start(*this->widgets.package_manager.spinner, Gtk::PACK_SHRINK, 10);

	this->widgets.package_manager.window->add(*box);

	// ------------------------------------------
	// CONNECT SIGNALS TO THE DISPATCHERS
	// ------------------------------------------

	LOG("-- Connect Signals");

	this->widgets.package_manager.open_window.connect([this]() {
		this->widgets.package_manager.mtx.lock();
		this->widgets.package_manager.window->set_position(Gtk::WIN_POS_CENTER);
		this->widgets.package_manager.spinner->start();
		this->widgets.package_manager.mtx.unlock();
		this->widgets.package_manager.window->show_all();
	});

	this->widgets.package_manager.close_window.connect([this]() {
		this->widgets.package_manager.mtx.lock();
		this->widgets.package_manager.spinner->stop();
		this->widgets.package_manager.mtx.unlock();
		this->widgets.package_manager.window->hide();
	});

	this->widgets.package_manager.update_text.connect([this]() {
		this->widgets.package_manager.mtx.lock();
		this->widgets.package_manager.main_info->set_text(this->widgets.package_manager.info_string);
		this->widgets.package_manager.subtitle->set_text(this->widgets.package_manager.subtitle_string);
		this->widgets.package_manager.mtx.unlock();
	});

	// ------------------------------------------
	// THIS FOLLOWING SIGNAL WILL BE CALLED AFTER
	// THE APPLICATION STARTED IT WILL UPDATE
	// THE PACKAGES AND THEN EMIT A DISPATCHER
	// SIGNAL FOR OPENING A NEW SESSION
	// ------------------------------------------

	this->widgets.app->signal_startup().connect([this]() {
		LOG("--> \"startup\" emmited");
		this->widgets.update_thread = Glib::Thread::create([this]() {

			// ------------------------------------------
			// CHECK FOR UPDATES
			// ------------------------------------------

			this->widgets.window->set_opacity(0);

			this->widgets.package_manager.init();

			// ------------------------------------------
			// START SESSION
			// ------------------------------------------

			this->widgets.start_session.emit();

		});
	});

	// ------------------------------------------
	// THIS DISPATCHER IS CALLED AFTER THE
	// UPDATE THREAD HAS DONE HIS WORK
	// ------------------------------------------

	this->widgets.start_session.connect([this]() {

		if (this->widgets.update_thread->joinable()) {
			this->widgets.update_thread->join();
		}

		LOG("--> \"start_session\" emmited");

		this->widgets.window->set_opacity(1);

		// ------------------------------------------
		// LOAD NOTEBOOK FILE
		// ------------------------------------------

		if (!std::experimental::filesystem::exists(HOME(this->widgets.settings.get<std::string>("notebook")))) {
			std::ofstream fout(HOME(this->widgets.settings.get<std::string>("notebook")));
			fout << "# LibreTextus Notes\n---" << std::endl;
			fout.close();
		}

		YAML::Node n = YAML::LoadFile(HOME(this->widgets.settings.get<std::string>("notebook")));

		this->widgets.text_view->set_note_book(n);
		this->widgets.note_book->set_file(n,
			HOME(this->widgets.settings.get<std::string>("notebook"))
		);

		// ------------------------------------------
		// INITIALIZE SIGNALHANDLER
		// ------------------------------------------

		this->signal_handler.init(&this->widgets);

		this->widgets.text_view->show_information();

		this->signal_handler.sync_enabled_sources();

		this->widgets.search_entry->grab_focus();
	});


	// ------------------------------------------
	// CONNECT FOLLOWING SIGNALS:
	// * SEARCH_ENTRY: SEND SIGNAL ON KEYEVENT
	// * THEME_COMBO: WHEN PREFERENCES CHANGED
	// * FONT_SIZE_ENTRY: WHEN PREF. CHANGED
	// ------------------------------------------

	this->widgets.search_entry->signal_key_press_event().connect(
		sigc::mem_fun(this->signal_handler, &SignalHandler::search_request),
		false
	);

	this->widgets.preferences_theme_combo->signal_changed().connect(
		sigc::mem_fun(this->signal_handler, &SignalHandler::theme_changed),
		false
	);

	this->widgets.font_size_spinbutton->signal_value_changed().connect(
		sigc::mem_fun(this->signal_handler, &SignalHandler::default_font_size_changed),
		false
	);

	// ------------------------------------------
	// CONNECT FOLLOWING DISPATCHERS:
	// * SET_TEXT_DISPACHER:
	//		- SET TEXT_BUFFER FROM NON-GUI-THREAD
	// * DELETE_THREAD_DISPATCHER:
	//		- DELETE FINISHED THREAD
	// ------------------------------------------

	this->widgets.set_text_dispatcher.connect(sigc::mem_fun(this->signal_handler, &SignalHandler::set_text));
	this->widgets.delete_thread_dispatcher.connect(sigc::mem_fun(this->signal_handler, &SignalHandler::delete_thread));
	this->widgets.sync_sources_dispatcher.connect(sigc::mem_fun(this->signal_handler, &SignalHandler::sync_enabled_sources));


	return 0;
}

void Framework::run() {

	LOG("-- Run Application");

	if (this->widgets.window) {
		this->widgets.app->run(*this->widgets.window);
	} else {
		std::cerr << "ERROR: UNABLE TO RUN APPLICATION" << '\n';
	}

	LOG("--------------------- LOG END ---------------------");
}
