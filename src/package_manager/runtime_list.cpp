#include "../package_manager.hpp"

void Libre::PackageManager::refresh_lists() {
	this->sources.clear();
	this->packages.clear();
	
	for (rapidxml::xml_node<> * i = this->sources_doc.first_node("sources")->first_node("file"); i; i = i->next_sibling()) {
		this->sources.push_back(i->first_attribute("name")->value());

		if (std::find(this->packages.begin(), this->packages.end(), i->first_node("package")->value()) == this->packages.end()) {
			this->packages.push_back(i->first_node("package")->value());
		}
	}
}

