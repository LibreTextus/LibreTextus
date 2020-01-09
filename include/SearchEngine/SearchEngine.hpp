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
	std::string W;
	YAML::Node names;

	YAML::Node search_word(std::string arg);
	YAML::Node search_book(std::string arg);

public:
	SearchEngine (std::string path, std::string names);
	virtual ~SearchEngine () {}

	YAML::Node search(std::string arg); // SEARCH FUNCTION FOR PUBLIC USE
};

#endif
