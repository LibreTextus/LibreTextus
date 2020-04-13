#include "framework.hpp"

int Framework::init(int argc, char *argv[]) {


	// CREATE BUILDER AND APP ----------------------------------------------------

	this->widgets.app = Gtk::Application::create(argc, argv);

	// CHECK FOR UPDATES ---------------------------------------------------------

	this->widgets.package_manager.init();

	// CREATING THE WINDOWS ------------------------------------------------------

	Libre::MainWindow::create(&this->widgets, &this->signal_handler);	// CREATE MAIN WINDOW
	this->widgets.window->show_all();																	// SHOW WINDOW

	Libre::PreferencesWindow::create(&this->widgets, &this->signal_handler); // CREATE PREFERENCES WINDOW


	// ADD CSS -------------------------------------------------------------------

	this->widgets.css = Gtk::CssProvider::create();	// CREATE CSSPROVIDER
	if(!this->widgets.css->load_from_path("data/" + this->settings.get<std::string>("theme-active") + ".css")) {
			std::cerr << "Failed to load css\n";				// LOAD CSS FILE AND IF LOADING FAILD RETURN ERROR
			return 1;
	}

	this->widgets.font_size = this->settings.get<int>("font_size");	// GET FONT SIZE FOR BEING ABLE TO CHANGE IT WHILE RUNTIME
	this->widgets.font_size_css = Gtk::CssProvider::create();				// CREATE FONT_SIZE_CSS PROVIDER
	this->widgets.font_size_css->load_from_data(										// LOAD CSS FROM STRING FOR FONT SIZE
		"* { font-size: " + std::to_string(this->widgets.font_size) + "px; }"
	);

	Glib::RefPtr<Gdk::Screen> screen = Gdk::Screen::get_default();		// GET SCREEN FOR ADDING CSS
	this->widgets.style = this->widgets.window->get_style_context();	// GET STYLE CONTEXT FOR ADDING CSS
	this->widgets.style->add_provider_for_screen(screen, this->widgets.css, GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
	this->widgets.style->add_provider_for_screen(screen, this->widgets.font_size_css, GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

	// INIT SIGNALHANDLER --------------------------------------------------------

	this->signal_handler.init(&this->widgets);

	// SET TEXT ON STARTUP -------------------------------------------------------

	this->widgets.search_entry->set_text("GEN, 1, 1-20");	// SET SEARCH TEXT
	this->widgets.search_entry->set_position(-1);					// SET CURSOR POSITION TO THE END

	// ------------------------------------------
	// DISABLE EVERYTHING WHICH COULD INTERRUPT
	// THE SEARCHENGINE WHILE SEARCHING THE
	// RESULT TO AVOID A SEGMATION FAULT
	// ------------------------------------------

	for (int i = 0; i < this->widgets.combo_boxes.size(); i++) {
		this->widgets.combo_boxes[i]->set_button_sensitivity(Gtk::SENSITIVITY_OFF);
		this->widgets.close_buttons[i]->set_sensitive(false);
	}

	this->widgets.search_entry->set_editable(false);
	this->widgets.action_group->set_sensitive(false);

	// ------------------------------------------
	// SET REPLACE_ID TO -1 -> EVERY TEXT_BUFFER
	// WILL BE UPDATED IF IT IS >= 0 JUST THIS
	// SPECIFIC TEXT_BUFFER WILL BE UPDATED
	// ------------------------------------------

	this->widgets.replace_id = -1;

	// ------------------------------------------
	// CREATE A NEW THREAD FOR SEARCHING
	// THE RESULTS
	// ------------------------------------------

	this->widgets.process_thread = Glib::Thread::create(sigc::mem_fun(this->signal_handler, &SignalHandler::do_search), true);


	// CONNECT SIGNALS -----------------------------------------------------------

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


	return 0;
}

void Framework::run() {
	if (this->widgets.window) {
		this->widgets.app->run(*this->widgets.window);
	} else {
		std::cerr << "ERROR: UNABLE TO RUN APPLICATION" << '\n';
	}
}
