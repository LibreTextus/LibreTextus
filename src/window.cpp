#include "window.hpp"

int Framework::init(int argc, char *argv[], std::string xml_path) {

	// PASS WIDGETS TO SIGNAL_HANDLER

	this->signal_handler.set_widgets(&this->widgets);

	// CREATE APP

	app = Gtk::Application::create(argc, argv);

	// CREATE BUILDER

	this->refBuilder = Gtk::Builder::create();

	// LOAD GLADE FILE

	try {
		this->refBuilder->add_from_file(xml_path);
	}
	catch(const Glib::FileError& ex) {
		std::cerr << "FileError: " << ex.what() << std::endl;
		return 1;
	}
	catch(const Glib::MarkupError& ex) {
		std::cerr << "MarkupError: " << ex.what() << std::endl;
		return 1;
	}
	catch(const Gtk::BuilderError& ex) {
		std::cerr << "BuilderError: " << ex.what() << std::endl;
		return 1;
	}

	// LOAD WINDOW

	this->refBuilder->get_widget("main_window", this->window);

	// CONNECT SIGNALS

	// SEARCH_ENTRY

	this->refBuilder->get_widget("search_entry", this->widgets.search_entry);
	this->widgets.search_entry->signal_key_press_event().connect(sigc::mem_fun(this->signal_handler, &SignalHandler::search_request), false);
	// INIT SIGNAL HANDLER BY PASSING search_entry
}

void Framework::run() {
	if(window) {
		app->run(*window);
	}
}
