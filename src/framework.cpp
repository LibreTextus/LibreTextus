#include "framework.hpp"

int Framework::init(int argc, char *argv[]) {

	// CREATE BUILDER AND APP ----------------------------------------------------

	this->widgets.app = Gtk::Application::create(argc, argv);	// CREATE APP

	this->signal_handler.set_widgets(&this->widgets);	// PASS WIDGETS TO SIGNAL_HANDLER

	this->widgets.preferences_window = nullptr;

	// CREATING THE WINDOWS ------------------------------------------------------

	LibreWindow::Main::create(&this->widgets, &this->signal_handler);
	this->widgets.window->show_all();

	LibreWindow::Preferences::create(&this->widgets, &this->signal_handler);


	// ADD CSS -------------------------------------------------------------------

	this->widgets.css = Gtk::CssProvider::create();
	if(!this->widgets.css->load_from_path("data/" + this->settings.get<std::string>("theme-active") + ".css")) {
			std::cerr << "Failed to load css\n";
			return 1;
	}

	this->widgets.font_size = this->settings.get<int>("font_size");
	this->widgets.font_size_css = Gtk::CssProvider::create();
	this->widgets.font_size_css->load_from_data("* { font-size: " + std::to_string(this->widgets.font_size) + "px; }");

	Glib::RefPtr<Gdk::Screen> screen = Gdk::Screen::get_default();
	this->widgets.style = this->widgets.window->get_style_context();
	this->widgets.style->add_provider_for_screen(screen, this->widgets.css, GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
	this->widgets.style->add_provider_for_screen(screen, this->widgets.font_size_css, GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

	this->signal_handler.init();

	// SET TEXT ON STARTUP -------------------------------------------------------

	this->widgets.search_entry->set_text("GEN, 1, 1-10");
	this->widgets.search_entry->set_position(-1);

	for (int i = 0; i < this->widgets.combo_boxes.size(); i++) {
		this->widgets.combo_boxes[i]->set_button_sensitivity(Gtk::SENSITIVITY_OFF);
	}

	this->widgets.search_entry->set_editable(false);
	this->widgets.action_group->set_sensitive(false);
	this->widgets.replace_id = -1;

	this->widgets.process_thread = Glib::Thread::create(sigc::mem_fun(this->signal_handler, &SignalHandler::do_search), true);


	// CONNECT SIGNALS -----------------------------------------------------------

	this->widgets.search_entry->signal_key_press_event().connect(	// SEARCH_ENTRY : WHEN KEY PRESSED
		sigc::mem_fun(this->signal_handler, &SignalHandler::search_request),
		false
	);

	this->widgets.preferences_theme_combo->signal_changed().connect(	// SEARCH_ENTRY : WHEN KEY PRESSED
		sigc::mem_fun(this->signal_handler, &SignalHandler::theme_changed),
		false
	);

	this->widgets.font_size_spinbutton->signal_value_changed().connect(	// SEARCH_ENTRY : WHEN KEY PRESSED
		sigc::mem_fun(this->signal_handler, &SignalHandler::default_font_size_changed),
		false
	);

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
