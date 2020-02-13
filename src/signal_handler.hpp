#ifndef SIGNAL_HANDLER_HPP
#define SIGNAL_HANDLER_HPP

#include <gtkmm.h>
#include <iostream>
#include <yaml-cpp/yaml.h>
#include "search_engine.hpp"

#include "widgets.hpp"

class SignalHandler {
private:
	SearchEngine * search_engine;
	LibreWidgets * widgets;

public:
	SignalHandler() {
		this->search_engine = new SearchEngine("data/BibleEditions/deu/schlachter-1951.yml",
																		 			 "data/BibleEditions/biblebooks.yml");

		this->search_engine->set_mark_argument("<span background=\"#db3131\">$&</span>");
		this->search_engine->set_header_argument("<span font_weight=\"ultralight\">$&</span>");
	}

	virtual ~SignalHandler() {};

	gboolean search_request(GdkEventKey * event);

	void set_widgets(LibreWidgets * w) {
		widgets = w;
	}
};

#endif
