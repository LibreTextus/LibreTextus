#ifndef WIDGETS_HPP
#define WIDGETS_HPP

#include <string>
#include <gtkmm.h>

struct LibreWidgets {
	Gtk::Window * window;
	Glib::RefPtr<Gtk::Application> app;
	Gtk::SearchEntry * search_entry;
	Gtk::TextView * text_views;
	Glib::RefPtr<Gtk::TextBuffer> search_result;

	~LibreWidgets() {
		delete window;
	}
};

#endif
