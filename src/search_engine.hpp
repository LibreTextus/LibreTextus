#ifndef SEARCH_ENGINE_HPP
#define SEARCH_ENGINE_HPP

#include <yaml-cpp/yaml.h>
#include <string>
#include <iostream>
#include <boost/regex.hpp>
#include <boost/regex/icu.hpp>
#include <vector>
#include <algorithm>
#include <locale>

#include "source_handler.hpp"
#include <tsl/ordered_map.h>

class SearchEngine {
private:
	Libre::BookMap * file;
	Libre::NameMap * names;
	Libre::BookMap::iterator active_verse;
	int active_verse_index;
	SourceHandler source_handler;
	std::vector<std::string> last_search_results;
	std::string W;
	std::string search_argument;
	std::string raw_search_argument;
	std::string mark_argument;
	std::vector<std::array<Libre::BookMap::iterator, 2>> positions;

	void interpret_string();
	void interpret_argument(std::string * text);
	void mark_result(std::string * text);

public:
	SearchEngine (std::string path, std::string names);
	virtual ~SearchEngine() {}

	bool search(std::string * arg); // SEARCH FUNCTION FOR PUBLIC USE
	void set_search_argument(std::string arg);
	void set_mark_argument(std::string arg);
	void set_source(std::string path);
	float get_progress();
	std::string * get_verse(std::string p);

	std::vector<std::string> * get_last_search_results() {
		return &this->last_search_results;
	}

	void set_last_search_result(std::vector<std::string> & v) {
		this->last_search_results = v;
	}

	std::string & get_search_argument() {
		return this->raw_search_argument;
	}
};

#endif
