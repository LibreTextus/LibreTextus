#include "package_manager.hpp"

void Libre::PackageManager::disable(std::string name) {
	rapidxml::xml_node<> * n;
	n = this->get_source_by_name(name);
	n->first_node("enabled")->value("false");

	this->write_to_file();
}

void Libre::PackageManager::enable(std::string name) {
	rapidxml::xml_node<> * n;
	n = this->get_source_by_name(name);
	n->first_node("enabled")->value("true");

	this->write_to_file();
}

rapidxml::xml_node<> * Libre::PackageManager::get_source_by_name(const std::string & name) {
	rapidxml::xml_node<> * n = this->sources_doc.first_node("sources")->first_node();
	for (;n && std::string(n->first_attribute("name")->value()) != name; n = n->next_sibling()) {}

	return n;
}
