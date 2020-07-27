#include "../package_manager.hpp"

void Libre::PackageManager::refresh_db(const std::string & p_name) {
	this->remove_invalid_paths();
	this->add_new_sources(p_name);
	
	this->write_to_file();
}

void Libre::PackageManager::remove_invalid_paths() {
	rapidxml::xml_node<> * i = this->sources_doc.first_node("sources")->first_node("file");

	for (; i; i = i->next_sibling()) {
		bool source_not_exists = !std::experimental::filesystem::exists(i->first_node("path")->value());
		if (source_not_exists) {
			rapidxml::xml_node<> * tmp = i->next_sibling();
			this->sources_doc.first_node("sources")->remove_node(i);
			i = tmp;
		}
	}
}

void Libre::PackageManager::add_new_sources(const std::string & p_name) {
	for (auto & i : std::experimental::filesystem::directory_iterator(HOME(p_name))) {
		bool is_directory = std::experimental::filesystem::is_directory(i.path());
		if (is_directory) {
			for (auto & f : std::experimental::filesystem::directory_iterator(i.path().string())) {
				bool is_xml = f.path().extension() == ".xml";
				if (is_xml) {
					this->append_source_info_to_list(p_name, f.path().string());
				}
			}
		}
	}
}

void Libre::PackageManager::append_source_info_to_list(const std::string & p_name, const std::string & xml_file_path) {
	rapidxml::file<> file(xml_file_path.c_str());
	rapidxml::xml_document<> doc;
	doc.parse<0>(file.data());

	rapidxml::xml_node<> * xmlbible_node = doc.first_node("XMLBIBLE");
	rapidxml::xml_node<> * information_node = xmlbible_node->first_node("INFORMATION");
	rapidxml::xml_node<> * title_node = information_node->first_node("title");
	std::string f_name = title_node->value();

	int id = this->get_file_name_number(xml_file_path, f_name);

	if (id > 0) {
		f_name += " (" + std::to_string(id + 1) + ")";
	}

	bool source_not_already_added = id != -1;
	if (source_not_already_added) {
		this->add_source_to_source_list(p_name, xml_file_path, f_name);
	}

	this->show_message(std::string(_("Found")) + " : " + f_name, "");
}

int Libre::PackageManager::get_file_name_number(const std::string & f_path, const std::string & f_name) {

	rapidxml::xml_node<> * sources_list = this->sources_doc.first_node("sources");
	rapidxml::xml_node<> * xf = sources_list->first_node("file");

	int id = 0;
	while (xf) {
		bool path_already_exists = std::string(xf->first_node("path")->value()) == f_path;
		if (path_already_exists) {
			return -1;
		}

		std::string id_str = (id ? " (" + std::to_string(id + 1) + ")" : "");
		bool name_already_exists = std::string(xf->first_attribute("name")->value()) == f_name + id_str;
		if (name_already_exists) {
			id++;
			xf = this->sources_doc.first_node("sources")->first_node("file");
			continue;
		}

		xf = xf->next_sibling();
	}

	return id;
}

void Libre::PackageManager::add_source_to_source_list(const std::string & p_name, const std::string & xml_file_path, const std::string & f_name) {
	char * file_name = this->sources_doc.allocate_string(f_name.c_str());
	char * path = this->sources_doc.allocate_string(xml_file_path.c_str());
	char * package = this->sources_doc.allocate_string(p_name.c_str());

	rapidxml::xml_node<> * f_info;
	rapidxml::xml_attribute<> * info_attr;
	rapidxml::xml_node<> * f_path;
	rapidxml::xml_node<> * f_package;
	rapidxml::xml_node<> * f_enabled;

	f_info = this->sources_doc.allocate_node(rapidxml::node_element, "file");
	info_attr = this->sources_doc.allocate_attribute("name", file_name);
	f_info->append_attribute(info_attr);

	f_path = this->sources_doc.allocate_node(rapidxml::node_element, "path", path);
	f_package = this->sources_doc.allocate_node(rapidxml::node_element, "package", package);
	f_enabled = this->sources_doc.allocate_node(rapidxml::node_element, "enabled", "true");

	f_info->append_node(f_path);
	f_info->append_node(f_package);
	f_info->append_node(f_enabled);

	this->sources_doc.first_node("sources")->append_node(f_info);
}
