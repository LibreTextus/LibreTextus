#ifndef WIDGETS_HPP
#define WIDGETS_HPP

#include <yaml-cpp/yaml.h>
#include <string>
#include <gtkmm.h>

struct LibreWidgets {
	Gtk::Window * window;
	Glib::RefPtr<Gtk::Application> app;
	Gtk::SearchEntry * search_entry;
	Gtk::TextView * text_views;
	YAML::Node verse_content;
	Glib::RefPtr<Gtk::TextBuffer> search_result;

	~LibreWidgets() {
		delete window;
	}
};

#endif
