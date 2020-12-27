#include "settings.hpp"
#include <rapidxml/rapidxml.hpp>

void Libre::Settings::set(const std::string & tag, const std::string & attr, const std::string & value) {
	rapidxml::file<> file(HOME("settings.xml").c_str());
	rapidxml::xml_document<> doc;
	doc.parse<rapidxml::parse_no_element_values>(file.data());

	rapidxml::xml_node<> * node = doc.first_node("settings")->first_node(tag.c_str());
	if (node) {
		node->first_attribute(attr.c_str())->value(value.c_str());
	} else {
		char * ctag = doc.allocate_string(tag.c_str());
		char * cattr = doc.allocate_string(attr.c_str());
		char * cvalue = doc.allocate_string(value.c_str());

		node = doc.allocate_node(rapidxml::node_element, ctag);
		rapidxml::xml_attribute<> * attrib = doc.allocate_attribute(cattr, cvalue);
		node->append_attribute(attrib);
		doc.first_node("settings")->append_node(node);
	}
	std::ofstream fout(HOME("settings.xml"));
	if (fout.is_open()) {
		fout << doc;
		fout.close();
	}
}
