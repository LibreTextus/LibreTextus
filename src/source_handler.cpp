#include "source_handler.hpp"
#include <rapidxml/rapidxml.hpp>
#include <rapidxml/rapidxml_utils.hpp>

std::map<std::string, Libre::BookMap> SourceHandler::sources;
Libre::NameMap SourceHandler::names;
std::string SourceHandler::names_path;

// SOURCEHANDLER::GET_SOURCE ---------------------------------------------------
// THIS FUNCTION RETURNS THE SOURCE. THE SOURCE MAP HAS THE FOLLOWING CONTENTS:
// 		* "BOOK CHAPTER, VERSE" -> VERSE CONTENT
// -----------------------------------------------------------------------------


Libre::BookMap * SourceHandler::get_source(std::string s) {

	if (this->sources.find(s) == this->sources.end()) {
		rapidxml::file<> file(s.c_str());
		rapidxml::xml_document<> doc;
		doc.parse<0>(file.data());

		this->sources[s] = this->to_map(&doc);
	}

	return &this->sources[s];
}

// SOURCEHANDLER::TO_MAP -------------------------------------------------------
// THIS FUNCTION TURNS A SOURCE NODE INTO A LIBRE::BOOKMAP
// -----------------------------------------------------------------------------

Libre::BookMap SourceHandler::to_map(rapidxml::xml_document<> * doc) {
	Libre::BookMap output;

	for (rapidxml::xml_node<> * b = doc->first_node("XMLBIBLE")->first_node("BIBLEBOOK"); b; b = b->next_sibling()) {
		for (rapidxml::xml_node<> * c = b->first_node("CHAPTER"); c; c = c->next_sibling()) {
			for (rapidxml::xml_node<> * v = c->first_node("VERS"); v; v = v->next_sibling()) {
				std::string v_pos = (this->names.begin() + std::stoi(b->first_attribute("bnumber")->value()) - 1)->first;

				v_pos += " " + std::string(c->first_attribute("cnumber")->value());
				v_pos	+= "," + std::string(v->first_attribute("vnumber")->value());
				output[v_pos] = "";

				for (rapidxml::xml_node<> * v_part = v->first_node(); v_part; v_part = v_part->next_sibling()) {
					output[v_pos] += (v_part->name() == "DIV" ? "" : v_part->value());
				}
			}
		}
	}

	return output;
}

// SOURCEHANDLER::GET_NAMES ----------------------------------------------------
// THIS FUNCTION RETURNS THE DEMANDED NAMES FILE
// -----------------------------------------------------------------------------

Libre::NameMap * SourceHandler::get_names() {
	return &this->names;
}

// SOURCEHANDLER::TO_NAMES -----------------------------------------------------
// THIS FUNCTION TURNS A NAMES NODE TO A LIBRE::NAMEMAP
// -----------------------------------------------------------------------------

Libre::NameMap SourceHandler::to_names(rapidxml::xml_document<> * doc) {
	Libre::NameMap output;

	for (rapidxml::xml_node<> * b = doc->first_node("BIBLEBOOKS")->first_node(); b; b = b->next_sibling()) {
		std::vector<std::string> v;

		for (rapidxml::xml_node<> * i = b->first_node(); i; i = i->next_sibling()) {
			v.push_back(i->first_attribute("name")->value());
		}

		output[b->first_attribute("name")->value()] = v;
	}

	return output;
}

void SourceHandler::set_names_path(std::string s) {
	rapidxml::file<> file(s.c_str());
	rapidxml::xml_document<> doc;
	doc.parse<0>(file.data());
	this->names = this->to_names(&doc);
}
