#include "framework.hpp"

int Framework::init(int argc, char *argv[]) {

	// CREATE BUILDER AND APP ----------------------------------------------------

	this->widgets.app = Gtk::Application::create(argc, argv);	// CREATE APP

	this->signal_handler.set_widgets(&this->widgets);	// PASS WIDGETS TO SIGNAL_HANDLER

	this->widgets.preferences_window = nullptr;

	// CREATING THE WINDOWS ------------------------------------------------------

	Window::Main::create(&this->widgets, &this->signal_handler);
	this->widgets.window->show_all();

	Window::Preferences::create(&this->widgets, &this->signal_handler);


	// ADD CSS -------------------------------------------------------------------

	Glib::RefPtr<Gtk::CssProvider> css = Gtk::CssProvider::create();
	if(!css->load_from_path("data/" + this->settings.get<std::string>("theme-active") + ".css")) {
			std::cerr << "Failed to load css\n";
			return 1;
	}
	Glib::RefPtr<Gdk::Screen> screen = Gdk::Screen::get_default();
	this->widgets.style = this->widgets.window->get_style_context();
	this->widgets.style->add_provider_for_screen(screen, css, GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

	this->signal_handler.init();


	// CONNECT SIGNALS -----------------------------------------------------------

	this->widgets.search_entry->signal_key_press_event().connect(	// SEARCH_ENTRY : WHEN KEY PRESSED
		sigc::mem_fun(this->signal_handler, &SignalHandler::search_request),
		false
	);

	this->widgets.combo_boxes->signal_changed().connect(	// SEARCH_ENTRY : WHEN KEY PRESSED
		sigc::mem_fun(this->signal_handler, &SignalHandler::source_changed),
		false
	);

	this->widgets.preferences_theme_combo->signal_changed().connect(	// SEARCH_ENTRY : WHEN KEY PRESSED
		sigc::mem_fun(this->signal_handler, &SignalHandler::theme_changed),
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
