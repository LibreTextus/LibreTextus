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
	Gtk::SearchEntry * search_bar;
	Gtk::ListBox * list_1;
	Gtk::ListBox * list_2;

public:
	GuiHandler() {}
	virtual ~GuiHandler() {
		delete window;
	}

	int init(int argc, char *argv[]);

	void run();
};

#endif
