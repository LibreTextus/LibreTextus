#ifndef WIDGETS_HPP
#define WIDGETS_HPP

#include <yaml-cpp/yaml.h>
#include <string>
#include <gtkmm.h>

struct LibreWidgets {
	Gtk::Window * window;
	Glib::RefPtr<Gtk::Application> app;
	Gtk::SearchEntry * search_entry;
	Gtk::ListBox * verse_box;
	Gtk::ListBoxRow * verse_containers;
	YAML::Node verse_content;

	~LibreWidgets() {
		delete window;
	}
};

#endif
