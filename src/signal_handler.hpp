#ifndef SIGNAL_HANDLER_HPP
#define SIGNAL_HANDLER_HPP

#include <gtkmm.h>
#include <iostream>
#include <yaml-cpp/yaml.h>
#include <thread>
#include <mutex>
#include <algorithm>
#include "search_engine.hpp"
#include "settings.hpp"

#include "widgets.hpp"

class SignalHandler {
private:
	std::vector<SearchEngine> search_engine;
	LibreWidgets * widgets;
	Settings settings;
	std::string mark_argument;
	std::string header_argument;

public:
	SignalHandler() {}

	virtual ~SignalHandler() {
	}

	void init(LibreWidgets * w);

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

	void theme_changed();
	void default_font_size_changed();
};

#endif
