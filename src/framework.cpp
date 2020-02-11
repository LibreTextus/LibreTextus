#include "framework.hpp"

int Framework::init(int argc, char *argv[]) {

	// CREATE BUILDER AND APP ----------------------------------------------------

	this->widgets.app = Gtk::Application::create(argc, argv);	// CREATE APP

	this->signal_handler.set_widgets(&this->widgets);	// PASS WIDGETS TO SIGNAL_HANDLER

	// CREATING WIDGETS ----------------------------------------------------------

	this->widgets.window = new Gtk::Window;						// CREATE NEW WINDOW
	this->widgets.window->set_default_size(1000, 800);	// SET WINDOW SIZE
	this->widgets.window->set_title("LibreTextus");			// SET WINDOW TITLE

	Gtk::VBox * h_box = new Gtk::VBox(false, 0);					// CREATE VBOX
	this->widgets.window->add(*h_box);										// ADD VBOX TO WINDOW

	this->widgets.search_entry = new Gtk::SearchEntry;	// CREATE NEW SEARCHENTRY
	this->widgets.text_views = new Gtk::TextView;
	Gtk::ScrolledWindow * scrolled_window = new Gtk::ScrolledWindow;

	this->widgets.search_result = Gtk::TextBuffer::create();
	this->widgets.text_views->set_buffer(this->widgets.search_result);
	this->widgets.text_views->set_editable(false);
	this->widgets.text_views->set_cursor_visible(false);
	this->widgets.text_views->set_wrap_mode(Gtk::WRAP_WORD);

	h_box->pack_start(*this->widgets.search_entry, Gtk::PACK_SHRINK, 0);	// ADD SEARCH_ENTRY WITH SHRINKABLE FLAG
	h_box->pack_end(*scrolled_window, Gtk::PACK_EXPAND_WIDGET, 0);				// ADD SCROLLED_WINDOW

	scrolled_window->add(*this->widgets.text_views);

	h_box->show_all();


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
		std::cerr << "ERROR: UNABLE TO RUN APPLICATION" << '\n';
	}
}