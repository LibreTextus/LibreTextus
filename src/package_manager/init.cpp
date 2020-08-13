#include "package_manager.hpp"

void Libre::PackageManager::init(bool without_update) {
	bool source_file_not_exists = !std::experimental::filesystem::exists(HOME("sources.xml"));
	if (source_file_not_exists) {
		this->create_empty_node();
		this->install_default_sources();
	} else {
		this->read_sources_file();
	}

	bool books_file_not_exists = !std::experimental::filesystem::exists(HOME("biblebooks.xml"));
	if (books_file_not_exists) {
		this->install_books_file();
	}

	this->refresh_lists();

	if (!without_update) {
		this->update();
	}
}

void Libre::PackageManager::create_empty_node() {
	rapidxml::xml_node<> * root = this->sources_doc.allocate_node(rapidxml::node_element, "sources");
	this->sources_doc.append_node(root);
}

void Libre::PackageManager::install_default_sources() {
	this->install("git://github.com/LibreTextus/BibleEditions");
}

void Libre::PackageManager::read_sources_file() {
	rapidxml::file<> xml_file(HOME("sources.xml").c_str());
	char * content = this->sources_doc.allocate_string(xml_file.data());
	this->sources_doc.parse<rapidxml::parse_no_data_nodes>(content);
}

void Libre::PackageManager::install_books_file() {
	std::experimental::filesystem::copy(DATA("biblebooks.xml"), HOME("biblebooks.xml"));
}
