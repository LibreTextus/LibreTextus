#ifndef SEARCH_ENGINE_HPP
#define SEARCH_ENGINE_HPP

#include <yaml-cpp/yaml.h>
#include <string>
#include <iostream>
#include <regex>
#include <vector>
#include <algorithm>

#include "source_handler.hpp"
#include <tsl/ordered_map.h>

class SearchEngine {
private:
	Libre::BookMap file;
	Libre::NameMap names;
	Libre::BookMap::iterator last_result;
	SourceHandler source_handler;
	std::vector<std::string> last_search_results;
	std::string W;
	std::string search_argument;
	std::string interpreted_argument;
	std::string mark_argument;
	std::string header_argument;
	std::string positions[2];
	bool is_book;

	bool search_word(std::string * text);
	bool search_book(std::string * text);
	bool search_position();
	void interpret_argument(std::string * text);
	void mark_result(std::string * text);

public:
	SearchEngine (std::string path, std::string names);
	virtual ~SearchEngine() {}

	bool search(std::string * arg); // SEARCH FUNCTION FOR PUBLIC USE
	void set_search_argument(std::string arg);
	void set_mark_argument(std::string arg);
	void set_header_argument(std::string arg);
	void set_source(std::string path);
	float get_progress();

	std::vector<std::string> * get_last_search_results() {
		return &this->last_search_results;
	}

	void set_last_search_result(std::vector<std::string> & v) {
		this->last_search_results = v;
	}

	std::string get_verse(std::string p);
};

#endif
