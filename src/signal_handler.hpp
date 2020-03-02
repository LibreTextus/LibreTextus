#ifndef SIGNAL_HANDLER_HPP
#define SIGNAL_HANDLER_HPP

#include <gtkmm.h>
#include <iostream>
#include <yaml-cpp/yaml.h>
#include <iomanip>
#include "search_engine.hpp"

#include "widgets.hpp"

class SignalHandler {
private:
	SearchEngine * search_engine;
	LibreWidgets * widgets;

public:
	SignalHandler() {}

	virtual ~SignalHandler() {
		delete search_engine;
	}

	bool init() {
		this->search_engine = new SearchEngine("data/BibleEditions/deu/schlachter-1951.yml",
																		 			 "data/BibleEditions/biblebooks.yml");

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

		this->search_engine->set_mark_argument("<span background=\"#" + r + g + b + "\">$&</span>");
		this->search_engine->set_header_argument("<span font_weight=\"ultralight\">$&</span>");
	}

	gboolean search_request(GdkEventKey * event);
	void do_search();
	void do_replacement();

	void set_text();
	void delete_thread();

	void source_changed();
	void quit();

	void set_widgets(LibreWidgets * w) {
		this->widgets = w;
	}
};

#endif
