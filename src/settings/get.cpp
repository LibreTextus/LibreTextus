#include "settings.hpp"

std::string Libre::Settings::get_attribute(const std::string & arg, const std::string & attr) {
	rapidxml::file<> file(HOME("settings.xml").c_str());
	rapidxml::xml_document<> doc;
	doc.parse<0>(file.data());

	rapidxml::xml_node<> * n = doc.first_node("settings")->first_node(arg.c_str());

	return (n ? n->first_attribute(attr.c_str())->value() : "");
}

std::vector<std::string> Libre::Settings::get_children(const std::string & arg, const std::string & attr) {
	rapidxml::file<> file(HOME("settings.xml").c_str());
	rapidxml::xml_document<> doc;
	doc.parse<0>(file.data());

	std::vector<std::string> output;

	for (rapidxml::xml_node<> * n = doc.first_node("settings")->first_node(arg.c_str())->first_node(); n; n = n->next_sibling()) { output.push_back(n->first_attribute(attr.c_str())->value()); }

	return output;
}


