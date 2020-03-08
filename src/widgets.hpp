#ifndef WIDGETS_HPP
#define WIDGETS_HPP

#include <string>
#include <vector>
#include <gtkmm.h>
#include <iostream>
#include <yaml-cpp/yaml.h>

class LibreWidgets {
public:

	Glib::RefPtr<Gtk::UIManager> ui_manager;
	Glib::RefPtr<Gtk::ActionGroup> action_group;

	// USED BY GUI THREAD

	Gtk::Window * window;
	Glib::RefPtr<Gtk::Application> app;
	Glib::RefPtr<Gtk::StyleContext> style;
	Glib::RefPtr<Gtk::CssProvider> css;
	Glib::RefPtr<Gtk::CssProvider> font_size_css;
	int font_size;
	Gtk::SpinButton * font_size_spinbutton;
	Gtk::SearchEntry * search_entry;
	Gtk::TextView * text_views;
	Gtk::ComboBoxText * combo_boxes;
	Glib::RefPtr<Gtk::TextBuffer> search_result;
	bool is_fullscreen;
	Gtk::Window * preferences_window;
	Gtk::ComboBoxText * preferences_theme_combo;
	// USED BY SEARCH TRHEAD

	Glib::Thread * process_thread;
	Glib::Dispatcher set_text_dispatcher;
	Glib::Dispatcher delete_thread_dispatcher;
	std::string found_text;
	bool procress_finished;
	float search_progress;

	YAML::Node sources;

	LibreWidgets() {
		sources = YAML::LoadFile("data/sources.yml");
	}

	~LibreWidgets() {
		delete window;
		delete preferences_window;
	}

	void append_sources(Gtk::ComboBoxText * combo_box) {
		for (YAML::const_iterator i = this->sources.begin(); i != this->sources.end(); i++) {
			combo_box->append(i->first.as<std::string>());
		}

		combo_box->set_active(0);
	}
};

#endif
