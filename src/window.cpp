#include "window.hpp"

int GuiHandler::init(int argc, char *argv[], std::string xml_path) {

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
}

void GuiHandler::run() {
	if(window) {
		app->run(*window);
	}
}
