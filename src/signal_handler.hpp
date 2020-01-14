#ifndef SIGNAL_HANDLER_HPP
#define SIGNAL_HANDLER_HPP

#include <gtkmm.h>
#include <iostream>
#include <SearchEngine/SearchEngine.hpp>
#include <yaml-cpp/yaml.h>

class SignalHandler {
private:
	Gtk::SearchEntry * search_entry;
	SearchEngine * search_engine;

public:
	SignalHandler() {
		search_engine = new SearchEngine("data/BibleEditions/deu/schlachter-1951.yml",
																		 "data/BibleEditions/biblebooks.yml");
	}

	virtual ~SignalHandler() {
		delete search_engine;
	}

	gboolean search_request(GdkEventKey * event);

	void set_search_entry(Gtk::SearchEntry * entry) {
		std::cout << "CONNECTED" << '\n';
		this->search_entry = entry;
	}

	void set_text_content(YAML::Node text);
};

#endif
