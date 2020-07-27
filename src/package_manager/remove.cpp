#include "../package_manager.hpp"

void Libre::PackageManager::remove(std::string package) {

	this->show_message(_("Removing directory..."), "");

	std::experimental::filesystem::remove_all(HOME(package));

	this->show_message(_("Update sources.xml"), "");

	rapidxml::xml_node<> * source_node = this->sources_doc.first_node("sources");
	rapidxml::xml_node<> * i = source_node->first_node();
	for (; i;) {
		if (i->first_node("package")->value() == package) {
			rapidxml::xml_node<> * tmp = i->next_sibling();
			this->sources_doc.first_node("sources")->remove_node(i);
			this->show_message(_("Update sources.xml"), std::string(_("Removing")) + " " + i->name());
			i = tmp;
		} else {
			i = i->next_sibling();
		}
	}
	
	this->show_message("", "");

	this->write_to_file();	
	this->refresh_lists();
}
