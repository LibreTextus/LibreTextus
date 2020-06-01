#ifndef SIGNAL_HANDLER_HPP
#define SIGNAL_HANDLER_HPP

#include <gtkmm.h>
#include <iostream>
#include <yaml-cpp/yaml.h>
#include <thread>
#include <algorithm>
#include "settings.hpp"
#include "path.hpp"
#include "widgets.hpp"
#include "log.hpp"

class SignalHandler {
private:
	Libre::Widgets * widgets;
	Settings settings;
	std::string mark_argument;
	std::string header_argument;

public:
	SignalHandler() {}

	virtual ~SignalHandler() {
	}

	void init(Libre::Widgets * w);

	gboolean search_request(GdkEventKey * event);
	void do_search();
	void do_replacement();

	void set_text();
	void delete_thread();

	void source_changed(Gtk::ComboBoxText * b);

	void quit();
	void toggle_fullscreen();
	void toggle_iconify();
	void toggle_search();
	void toggle_preferences();
	void zoom_in();
	void zoom_out();
	void zoom_reset();
	void add_source();
	void remove_source();
	void remove_source_by_reference(Gtk::Button * b);


	void add_source_dir();
	void remove_source_dir();

	void sync_enabled_sources();

	void theme_changed();
	void default_font_size_changed();

	void toggle_note(std::string position);
	void trigger_search(std::string text);
};

#endif
