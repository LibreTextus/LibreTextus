#ifndef WIDGETS_HPP
#define WIDGETS_HPP

#include <string>
#include <vector>
#include <gtkmm.h>
#include <iostream>
#include <yaml-cpp/yaml.h>

class LibreWidgets {
public:
	Gtk::Window * window;
	Glib::RefPtr<Gtk::Application> app;
	Gtk::SearchEntry * search_entry;
	Gtk::TextView * text_views;
	Gtk::ComboBoxText * combo_boxes;
	Glib::RefPtr<Gtk::TextBuffer> search_result;

	YAML::Node sources;

	LibreWidgets() {
		sources = YAML::LoadFile("data/sources.yml");		
	}

	~LibreWidgets() {
		delete window;
	}

	void append_sources(Gtk::ComboBoxText * combo_box) {
		for (YAML::const_iterator i = this->sources.begin(); i != this->sources.end(); i++) {
			combo_box->append(i->first.as<std::string>());
		}

		combo_box->set_active(0);
	}
};

#endif
