#ifndef WINDOW_HPP
#define WINDOW_HPP value

#include <gtkmm.h>
#include <iostream>

#include "signal_handler.hpp"

class GuiHandler {
private:
	Glib::RefPtr<Gtk::Builder> refBuilder;
	Gtk::Window * window;
	Glib::RefPtr<Gtk::Application> app;
	Gtk::ListBoxRow * verses;

public:
	GuiHandler() {}
	virtual ~GuiHandler() {
		delete window;
		delete[] verses;
	}

	int init(int argc, char *argv[], std::string xml_path) ;
	void run();


};

#endif
