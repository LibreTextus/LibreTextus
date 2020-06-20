#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <rapidxml/rapidxml.hpp>
#include <rapidxml/rapidxml_print.hpp>
#include <rapidxml/rapidxml_utils.hpp>
#include <iostream>
#include <fstream>
#include <vector>

#include "path.hpp"

// -----------------------------------------------------------------------------
// THIS CLASS IS FOR READ AND WRITE THE SETTINGS STORED IN THE YAML FILE
// -----------------------------------------------------------------------------

class Settings {
public:
	Settings () = default;
	virtual ~Settings () = default;

	// SETTINGS::GET<T> ----------------------------------------------------------
	// THIS FUNCTION RETURNS THE VALUE STORED IN THE SETTINGS FILE IN THE DEMANDED
	// TYPE
	// ---------------------------------------------------------------------------

	std::string get_attribute(const std::string & arg, const std::string & attr) {
		rapidxml::file<> file(HOME("settings.xml").c_str());
		rapidxml::xml_document<> doc;
		doc.parse<0>(file.data());

		rapidxml::xml_node<> * n = doc.first_node("settings")->first_node(arg.c_str());

		return (n ? n->first_attribute(attr.c_str())->value() : "");
	}

	// SETTINGS::GET -------------------------------------------------------------
	// THIS FUNCTION RETURNS THE VALUE STORED IN THE SETTINGS AS YAML::NODE
	// ---------------------------------------------------------------------------

	std::vector<std::string> get_children(const std::string & arg, const std::string & attr) {
		rapidxml::file<> file(HOME("settings.xml").c_str());
		rapidxml::xml_document<> doc;
		doc.parse<0>(file.data());

		std::vector<std::string> output;

		for (rapidxml::xml_node<> * n = doc.first_node("settings")->first_node(arg.c_str())->first_node(); n; n = n->next_sibling()) { output.push_back(n->first_attribute(attr.c_str())->value()); }

		return output;
	}

	// SETTINGS::SET -------------------------------------------------------------
	// THIS FUNCTION SAVES THE SETTNGS IN THE SETTINGS FILE
	// ---------------------------------------------------------------------------

	void set(const std::string & tag, const std::string & attr, const std::string & value) {
		rapidxml::file<> file(HOME("settings.xml").c_str());
		rapidxml::xml_document<> doc;
		doc.parse<rapidxml::parse_no_element_values>(file.data());

		doc.first_node("settings")->first_node(tag.c_str())->first_attribute(attr.c_str())->value(value.c_str());
		
		std::ofstream fout(HOME("settings.xml"));
		if (fout.is_open()) {
			fout << doc;
			fout.close();
		}
	}
};

#endif
