#include "source_handler.hpp"

std::map<std::string, Libre::BookMap> SourceHandler::sources;
Libre::NameMap SourceHandler::names;
std::vector<std::string> SourceHandler::compare_v;

// SOURCEHANDLER::GET_SOURCE ---------------------------------------------------
// THIS FUNCTION RETURNS THE SOURCE. THE SOURCE MAP HAS THE FOLLOWING CONTENTS:
// 		* "BOOK CHAPTER, VERSE" -> VERSE CONTENT
// -----------------------------------------------------------------------------


Libre::BookMap * SourceHandler::get_source(std::string s) {

	if (this->sources.find(s) == this->sources.end()) {
		auto start = std::chrono::high_resolution_clock::now();
		YAML::Node v = YAML::LoadFile(s);
		auto stop = std::chrono::high_resolution_clock::now();
		std::cout << "LOAD FILE: " << std::chrono::duration_cast<std::chrono::seconds>(stop - start).count() << '\n';

		start = std::chrono::high_resolution_clock::now();
		this->sources[s] = this->to_map(v);
		stop = std::chrono::high_resolution_clock::now();
		std::cout << "CONVERT TO MAP: " << std::chrono::duration_cast<std::chrono::seconds>(stop - start).count() << '\n';
	}

	return &this->sources[s];
}

// SOURCEHANDLER::TO_MAP -------------------------------------------------------
// THIS FUNCTION TURNS A SOURCE NODE INTO A LIBRE::BOOKMAP
// -----------------------------------------------------------------------------

Libre::BookMap SourceHandler::to_map(YAML::Node n) {
	Libre::BookMap output;

	for (int b = 0; b < n.size(); b++) {
		for (int c = 0; c < n[b].begin()->second.size(); c++) {
			for (int v = 0; v < n[b].begin()->second[c].begin()->second.size(); v++) {
				std::string v_pos = n[b].begin()->first.as<std::string>();
				v_pos += " " + n[b].begin()->second[c].begin()->first.as<std::string>();
				v_pos	+= "," + n[b].begin()->second[c].begin()->second[v].begin()->first.as<std::string>();
				output[v_pos] = n[b].begin()->second[c].begin()->second[v].begin()->second.as<std::string>();
			}
		}
	}

	return output;
}

// SOURCEHANDLER::GET_NAMES ----------------------------------------------------
// THIS FUNCTION RETURNS THE DEMANDED NAMES FILE
// -----------------------------------------------------------------------------

Libre::NameMap * SourceHandler::get_names(std::string s) {

	if (this->sources.find(s) == this->sources.end()) {
		YAML::Node v = YAML::LoadFile(s);
		this->names = this->to_names(v);
	}

	return &this->names;
}

// SOURCEHANDLER::TO_NAMES -----------------------------------------------------
// THIS FUNCTION TURNS A NAMES NODE TO A LIBRE::NAMEMAP
// -----------------------------------------------------------------------------

Libre::NameMap SourceHandler::to_names(YAML::Node n) {
	Libre::NameMap output;

	for (YAML::const_iterator b = n.begin(); b != n.end(); b++) {
		std::vector<std::string> v;

		for (YAML::const_iterator i = b->second.begin(); i != b->second.end(); i++) {
			v.push_back(i->as<std::string>());
		}

		output[b->first.as<std::string>()] = v;
	}

	return output;
}
