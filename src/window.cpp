#include "window.hpp"

int GuiHandler::init(int argc, char *argv[]) {

	// CREATE APP

	app = Gtk::Application::create(argc, argv);

	// CREATE BUILDER

	this->refBuilder = Gtk::Builder::create();

	// LOAD GLADE FILE

	try {
		this->refBuilder->add_from_file("data/interface.glade");
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

	this->refBuilder->get_widget("window", this->window);

	// ADD SEARCHBAR FUNCTION

	this->refBuilder->get_widget("search_bar", this->search_bar);
	this->search_bar->signal_search_changed().connect(sigc::ptr_fun(SignalHandler::search_input));

	// LOAD LISTS

	this->refBuilder->get_widget("list_0", this->list_0);
	this->refBuilder->get_widget("list_1", this->list_1);

	// CREATE ROWS

	this->list_0_rows = new Gtk::ListBoxRow();
	this->list_1_rows = new Gtk::ListBoxRow();
}

void GuiHandler::run() {
	if(window) {
		app->run(*window);
	}
}
