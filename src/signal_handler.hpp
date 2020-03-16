#ifndef SIGNAL_HANDLER_HPP
#define SIGNAL_HANDLER_HPP

#include <gtkmm.h>
#include <iostream>
#include <yaml-cpp/yaml.h>
#include <thread>
#include <mutex>
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

	void init() {
		this->search_engine.push_back(SearchEngine("data/BibleEditions/deu/schlachter-1951.yml",
																						"data/BibleEditions/biblebooks.yml"));

		Gdk::RGBA rgba;
		this->widgets->style->lookup_color("theme_highlight_color", rgba);

		std::string r, g, b;

		std::stringstream stream;
		stream << std::hex << static_cast<int>(rgba.get_red() * 255);
		r = stream.str();
		if (r.length() < 2) { r = "0" + r; }
		stream.str("");

		stream << std::hex << static_cast<int>(rgba.get_green() * 255);
		g += stream.str();
		if (g.length() < 2) { g = "0" + g; }
		stream.str("");

		stream << std::hex << static_cast<int>(rgba.get_blue() * 255);
		b += stream.str();
		if (b.length() < 2) { b = "0" + b; }

		this->mark_argument = "<span background=\"#" + r + g + b + "\">$&</span>";
		this->header_argument = "<span font_weight=\"ultralight\">$&</span>";

		this->search_engine[0].set_mark_argument(this->mark_argument);
		this->search_engine[0].set_header_argument(this->header_argument);
	}

	gboolean search_request(GdkEventKey * event);
	void do_search();
	void do_replacement(int id);

	void set_text();
	void delete_thread();

	void source_changed(int id);

	void quit();
	void toggle_fullscreen();
	void toggle_iconify();
	void toggle_search();
	void toggle_preferences();
	void zoom_in();
	void zoom_out();
	void zoom_reset();
	void add_source();

	void theme_changed();
	void default_font_size_changed();

	void set_widgets(LibreWidgets * w) {
		this->widgets = w;
	}
};

#endif
