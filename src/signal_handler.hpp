#ifndef SIGNAL_HANDLER_HPP
#define SIGNAL_HANDLER_HPP

#include <gtkmm.h>
#include <iostream>
#include <SearchEngine/SearchEngine.hpp>
#include <yaml-cpp/yaml.h>

#include "widgets.hpp"

class SignalHandler {
private:
	SearchEngine * search_engine;
	LibreWidgets * widgets;

public:
	SignalHandler() {
		this->search_engine = new SearchEngine("data/BibleEditions/deu/schlachter-1951.yml",
																		 			 "data/BibleEditions/biblebooks.yml");
	}

	virtual ~SignalHandler() {};

	gboolean search_request(GdkEventKey * event);

	void update_text_content();

	void set_widgets(LibreWidgets * w) {
		widgets = w;
	}
};

#endif
