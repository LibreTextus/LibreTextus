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
	Gtk::ListBox * list_0;
	Gtk::ListBox * list_1;
	Gtk::ListBoxRow * list_0_rows;
	Gtk::ListBoxRow * list_1_rows;

public:
	GuiHandler() {}
	virtual ~GuiHandler() {
		delete window;
		delete search_bar;
		delete list_0;
		delete list_1;
		delete[] list_0_rows;
		delete[] list_1_rows;
	}

	int init(int argc, char *argv[]);

	void run();
};

#endif
