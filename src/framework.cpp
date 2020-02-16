#include "framework.hpp"

int Framework::init(int argc, char *argv[]) {

	// CREATE BUILDER AND APP ----------------------------------------------------

	this->widgets.app = Gtk::Application::create(argc, argv);	// CREATE APP

	this->signal_handler.set_widgets(&this->widgets);	// PASS WIDGETS TO SIGNAL_HANDLER

	// CREATING WIDGETS ----------------------------------------------------------

	this->widgets.window = new Gtk::Window;						// CREATE NEW WINDOW
	this->widgets.window->set_default_size(1000, 800);	// SET WINDOW SIZE
	this->widgets.window->set_title("LibreTextus");			// SET WINDOW TITLE
	this->widgets.window->set_icon_from_file("data/Icon.svg");

	Gtk::VBox * v_box = new Gtk::VBox(false, 0);					// CREATE VBOX
	this->widgets.window->add(*v_box);										// ADD VBOX TO WINDOW

	this->widgets.search_entry = new Gtk::SearchEntry;	// CREATE NEW SEARCHENTRY

	Gtk::VBox * scrl_container = new Gtk::VBox(false, 0);
	this->widgets.text_views = new Gtk::TextView;
	Gtk::ScrolledWindow * scrolled_window = new Gtk::ScrolledWindow;
	Gtk::HBox * header = new Gtk::HBox(false, 0);

	this->widgets.search_result = Gtk::TextBuffer::create();
	this->widgets.text_views->set_buffer(this->widgets.search_result);
	this->widgets.text_views->set_editable(false);
	this->widgets.text_views->set_cursor_visible(false);
	this->widgets.text_views->set_wrap_mode(Gtk::WRAP_WORD);

	v_box->pack_start(*this->widgets.search_entry, Gtk::PACK_SHRINK, 0);	// ADD SEARCH_ENTRY WITH SHRINKABLE FLAG
	v_box->pack_end(*scrl_container, Gtk::PACK_EXPAND_WIDGET, 0);

	scrl_container->pack_start(*header, Gtk::PACK_SHRINK, 0);
	scrl_container->pack_end(*scrolled_window, Gtk::PACK_EXPAND_WIDGET, 0);

	scrolled_window->add(*this->widgets.text_views);
	this->widgets.text_views->set_border_width(10);

	this->widgets.combo_boxes = new Gtk::ComboBoxText;

	this->widgets.append_sources(this->widgets.combo_boxes);

	header->pack_end(*this->widgets.combo_boxes, Gtk::PACK_SHRINK, 0);
	header->set_border_width(10);

	v_box->show_all();

	// ADD CSS -------------------------------------------------------------------

  Glib::RefPtr<Gtk::CssProvider> css = Gtk::CssProvider::create();
  if(!css->load_from_path("data/default.css")) {
      std::cerr << "Failed to load css\n";
			return 1;
  }
  auto screen = Gdk::Screen::get_default();
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
