#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <gtkmm.h>
#include <iostream>

#include "signal_handler.hpp"
#include "widgets.hpp"

class Framework {
private:
	Glib::RefPtr<Gtk::Builder> refBuilder;
	Gtk::Window * window;
	Glib::RefPtr<Gtk::Application> app;
	SignalHandler signal_handler;
	LibreWidgets widgets;

	// Gtk::ListBoxRow * verses;

public:
	Framework() {}
	virtual ~Framework() {
		delete window;
		// delete[] verses;
	}

	int init(int argc, char *argv[], std::string xml_path) ;
	void run();
};

#endif
