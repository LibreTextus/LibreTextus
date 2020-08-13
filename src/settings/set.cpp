#include "settings.hpp"

void Libre::Settings::set(const std::string & tag, const std::string & attr, const std::string & value) {
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
