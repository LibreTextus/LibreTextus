#include "framework.hpp"

int Framework::init(int argc, char *argv[]) {

	// CREATE BUILDER AND APP ----------------------------------------------------

	this->widgets.app = Gtk::Application::create(argc, argv);	// CREATE APP

	this->signal_handler.set_widgets(&this->widgets);	// PASS WIDGETS TO SIGNAL_HANDLER

	// CREATING WIDGETS ----------------------------------------------------------

	this->widgets.window = new Gtk::Window();						// CREATE NEW WINDOW
	this->widgets.window->set_default_size(1000, 800);	// SET WINDOW SIZE
	this->widgets.window->set_title("LibreTextus");			// SET WINDOW TITLE

	Gtk::VBox * h_box = new Gtk::VBox(false, 0);					// CREATE VBOX
	this->widgets.window->add(*h_box);										// ADD VBOX TO WINDOW

	this->widgets.search_entry = new Gtk::SearchEntry();	// CREATE NEW SEARCHENTRY
	Gtk::ScrolledWindow * scrolled_window = new Gtk::ScrolledWindow();	// CREATE SCROLLED_WINDOW

	h_box->pack_start(*this->widgets.search_entry, Gtk::PACK_SHRINK, 0);	// ADD SEARCH_ENTRY WITH SHRINKABLE FLAG
	h_box->pack_end(*scrolled_window, Gtk::PACK_EXPAND_WIDGET, 0);				// ADD SCROLLED_WINDOW

	this->widgets.verse_box = new Gtk::ListBox();
	scrolled_window->add(*this->widgets.verse_box);

	this->widgets.verse_box->set_selection_mode(Gtk::SELECTION_NONE);

	h_box->show_all();

	this->widgets.verse_containers = new Gtk::ListBoxRow[1];



	// CONNECT SIGNALS -----------------------------------------------------------

	this->widgets.search_entry->signal_key_press_event().connect(	// SEARCH_ENTRY : WHEN KEY PRESSED
		sigc::mem_fun(this->signal_handler, &SignalHandler::search_request),
		false
	);

	return 0;
}

void Framework::run() {
	if (this->widgets.window) {
		this->widgets.app->run(*this->widgets.window);
	} else {
		std::cerr << "ERROR: COULD NOT RUN APPLICATION" << '\n';
	}
}
