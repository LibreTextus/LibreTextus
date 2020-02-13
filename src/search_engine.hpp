#ifndef SEARCH_ENGINE_HPP
#define SEARCH_ENGINE_HPP

#include <yaml-cpp/yaml.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <regex>
#include <map>

class SearchEngine {
private:
	YAML::Node file;
	YAML::Node names;
	YAML::const_iterator * last_result;
	std::string W;
	std::string search_argument;
	std::string interpreted_argument;
	std::string mark_argument;
	std::string header_argument;
	bool is_book;


	bool search_word(std::string * text);
	bool search_book(std::string * text);
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
};

#endif
