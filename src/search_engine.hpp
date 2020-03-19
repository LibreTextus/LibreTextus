#ifndef SEARCH_ENGINE_HPP
#define SEARCH_ENGINE_HPP

#include <yaml-cpp/yaml.h>
#include <string>
#include <iostream>
#include <regex>
#include <vector>

#include "source_handler.hpp"

class SearchEngine {
private:
	YAML::Node file;
	YAML::Node names;
	YAML::const_iterator * last_result;
	SourceHandler source_handler;
	std::vector<std::array<std::string, 3>> last_search_results;
	std::string W;
	std::string search_argument;
	std::string interpreted_argument;
	std::string mark_argument;
	std::string header_argument;
	std::string positions[3][2];
	bool is_book;

	bool search_word(std::string * text);
	bool search_book(std::string * text);
	bool search_position();
	void interpret_argument(std::string * text);
	void mark_result(std::string * text);
	void add_header(std::string * text);

public:
	SearchEngine (std::string path, std::string names);
	virtual ~SearchEngine () {}

	bool search(std::string * arg); // SEARCH FUNCTION FOR PUBLIC USE
	void set_search_argument(std::string arg);
	void set_mark_argument(std::string arg);
	void set_header_argument(std::string arg);
	void set_source(std::string path);
	float get_progress();

	std::vector<std::array<std::string, 3>> * get_last_search_results() {
		return &this->last_search_results;
	}

	void set_last_search_result(std::vector<std::array<std::string, 3>> & v) {
		this->last_search_results = v;
	}

	std::string get_verse(std::string book, std::string chapter, std::string verse);
};

#endif
