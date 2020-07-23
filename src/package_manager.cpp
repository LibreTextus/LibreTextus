#include "package_manager.hpp"

// LIBRE::PACKAGEMANAGER::INIT -------------------------------------------------
// THIS FUNCTION INITIALIZES THE PACKAGEMANAGER. IF THERE IS NO PACKAGE
// INSTALLED IN THE PACKAGE_DIRECTORY IT WILL INSTALL THE DEFAULT
// -----------------------------------------------------------------------------

void Libre::PackageManager::init(bool without_update) {
	// ------------------------------------------
	// CHECK IF THE ROOT DIRECTORY IS EMPTY
	// ------------------------------------------

	if (!std::experimental::filesystem::exists(HOME("sources.xml"))) {
		rapidxml::xml_node<> * root = this->sources_doc.allocate_node(rapidxml::node_element, "sources");
		this->sources_doc.append_node(root);

		this->install("git://github.com/LibreTextus/BibleEditions");
	} else {
		rapidxml::file<> xml_file(HOME("sources.xml").c_str());
		char * content = this->sources_doc.allocate_string(xml_file.data());
		this->sources_doc.parse<rapidxml::parse_no_data_nodes>(content);
	}

	if (!std::experimental::filesystem::exists(HOME("biblebooks.xml"))) {
		std::experimental::filesystem::copy(DATA("biblebooks.xml"), HOME("biblebooks.xml"));
	}

	this->refresh_lists();

	if (!without_update) {
		this->update();
	}
}

// LIBRE::PACKAGEMANAGER::INSTALL ----------------------------------------------
// THIS FUNCTION INSTALLES A NEW SOURCE PACKAGES OVER GIT
// -----------------------------------------------------------------------------

void Libre::PackageManager::install(std::string url) {

	// ------------------------------------------
	// GET THE NAME OF THE PACKAGE
	// ------------------------------------------

	std::string name;
	name = url.substr(url.find_last_of("/") + 1);

	// ------------------------------------------
	// DISPLAY FOLLOWING INFORMATION:
	// 			Install ${name}
	//	This could take a while...
	// ------------------------------------------

	this->mtx.lock();
	this->header_string = std::string(_("Install")) + " " + name;
	this->info_string = _("This could take a while...");
	this->mtx.unlock();
	this->update_text.emit();

	// ------------------------------------------
	// CLONE SOURCE-REPOSITORY
	// ------------------------------------------

	system(("git clone " + url + " " + HOME(name)).c_str());

	this->refresh_db(name);

	// ------------------------------------------
	// DISPLAY FOLLOWING INFORMATION:
	// 		Looking for sources...
	//		Found ${source name}
	// ------------------------------------------

	this->mtx.lock();
	this->header_string = _("Looking for sources...");
	this->info_string = "";
	this->mtx.unlock();
	this->update_text.emit();

	// ------------------------------------------
	// DISPLAY FOLLOWING INFORMATION:
	// 		Update sources.xml
	// ------------------------------------------

	this->mtx.lock();
	this->header_string = _("Update sources.xml");
	this->info_string = "";
	this->mtx.unlock();
	this->update_text.emit();

	// ------------------------------------------
	// WRITE EVERYTHING TO THE SOURCES FILE
	// ------------------------------------------

	std::ofstream fout(HOME("sources.xml"));
	if (fout.is_open()) {
		fout << this->sources_doc;
		fout.close();
	} 

	this->refresh_lists();
}

// LIBRE::PACKAGEMANAGER::REMOVE -----------------------------------------------
// THIS FUNCTION REMOVES A SOURCE FROM THE ROOT DIRECTORY AND THE SOURCES LIST
// -----------------------------------------------------------------------------

void Libre::PackageManager::remove(std::string package) {

	// ------------------------------------------
	// OPEN WINDOW AND DISPLAY INFORMATION
	// ------------------------------------------

	this->mtx.lock();
	this->header_string = _("Removing directory...");
	this->info_string = "";
	this->mtx.unlock();
	this->update_text.emit();

	// ------------------------------------------
	// REMOVE PACKAGE DIRECTORY
	// ------------------------------------------

	std::experimental::filesystem::remove_all(HOME(package));

	// ------------------------------------------
	// SET INFORMATION
	// ------------------------------------------

	this->mtx.lock();
	this->header_string = _("Update sources.xml");
	this->info_string = "";
	this->mtx.unlock();
	this->update_text.emit();

	// ------------------------------------------
	// REMOVE EVERY SOURCE OF THE PACKAGE FROM
	// YAML NODE
	// ------------------------------------------

	for (rapidxml::xml_node<> * i = this->sources_doc.first_node("sources")->first_node(); i;) {
		if (i->first_node("package")->value() == package) {
			this->sources_doc.first_node("sources")->remove_node(i);
			this->mtx.lock();
			this->info_string = std::string(_("Removing")) + " " + i->name();
			this->mtx.unlock();
			this->update_text.emit();
			i = this->sources_doc.first_node("sources")->first_node();
			continue;
		}
		i = i->next_sibling();
	}

	// ------------------------------------------
	// WRITE THE NEW SOURCES LIST
	// ------------------------------------------

	this->mtx.lock();
	this->info_string = "";
	this->mtx.unlock();
	this->update_text.emit();


	std::ofstream fout(HOME("sources.xml"));
	if (fout.is_open()) {
		fout << this->sources_doc;
		fout.close();
	}

	this->refresh_lists();
}

// LIBRE::PACKAGEMANAGER::DISABLE ----------------------------------------------
// THIS FUNCTION DOES NOT REMOVE THE SOURCE IT JUST MAKES THAT THE SOURCE IS NOT
// LISTED ON THE COMBOBOXTEXT
// -----------------------------------------------------------------------------

void Libre::PackageManager::disable(std::string name) {
	rapidxml::xml_node<> * n = this->sources_doc.first_node("sources")->first_node();
	for (;n && std::string(n->first_attribute("name")->value()) != name; n = n->next_sibling()) {}

	n->first_node("enabled")->value("false");

	std::ofstream fout(HOME("sources.xml"));
	if (fout.is_open()) {
		fout << this->sources_doc;
		fout.close();
	}
}

// LIBRE::PACKAGEMANAGER::ENABLE -----------------------------------------------
// THIS FUNCTION ADDS THE SOURCE TO THE COMBOBOXTEXT SO YOU CAN SELECT IT
// -----------------------------------------------------------------------------

void Libre::PackageManager::enable(std::string name) {
	rapidxml::xml_node<> * n = this->sources_doc.first_node("sources")->first_node();
	for (;n && std::string(n->first_attribute("name")->value()) != name; n = n->next_sibling()) {}

	n->first_node("enabled")->value("true");

	std::ofstream fout(HOME("sources.xml"));
	if (fout.is_open()) {
		fout << this->sources_doc;
		fout.close();
	}
}

// LIBRE::PACKAGEMANAGER::UPDATE -----------------------------------------------
// THIS FUNCTION UPDATES THE PACKAGES
// -----------------------------------------------------------------------------

void Libre::PackageManager::update() {

	this->mtx.lock();
	this->header_string = _("Update Packages");
	this->info_string = "";
	this->mtx.unlock();
	this->update_text.emit();

	for (int i = 0; i < this->packages.size(); i++) {
		system(("git -C " + HOME(this->packages[i]) + " pull").c_str());
		this->mtx.lock();
		this->info_string = std::string(_("Updating")) + " " + this->packages[i];
		this->mtx.unlock();
		this->update_text.emit();
		this->refresh_db(this->packages[i]);
	}

	this->refresh_lists();
}

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

void Libre::PackageManager::refresh_db(const std::string & name) {

	for (rapidxml::xml_node<> * i = this->sources_doc.first_node("sources")->first_node("file"); i; i = i->next_sibling()) {
		if (!std::experimental::filesystem::exists(i->first_node("path")->value())) {
			rapidxml::xml_node<> * tmp = i->next_sibling();
			this->sources_doc.first_node("sources")->remove_node(i);
			i = tmp;
		}
	}

	for (auto & i : std::experimental::filesystem::directory_iterator(HOME(name))) {
		if (std::experimental::filesystem::is_directory(i.path())) {
			for (auto & f : std::experimental::filesystem::directory_iterator(i.path().string())) {
				if (f.path().extension() == ".xml") {
					rapidxml::file<> file(f.path().c_str());
					rapidxml::xml_document<> doc;
					doc.parse<0>(file.data());

					std::string f_name = doc.first_node("XMLBIBLE")->first_node("INFORMATION")->first_node("title")->value();

					int id = 0;
					rapidxml::xml_node<> * xf = this->sources_doc.first_node("sources")->first_node("file");
					while (xf) {
						if (std::string(xf->first_node("path")->value()) == f.path().string()) {
							break;
						}

						if (xf->first_attribute("name")->value() == f_name + (id ? " (" + std::to_string(id + 1) + ")" : "")) {
							id++;
							xf = this->sources_doc.first_node("sources")->first_node("file");
							continue;
						}

						xf = xf->next_sibling();
					}

					if (id != 0) {
						f_name += " (" + std::to_string(id + 1) + ")";
					}

					char * file_name = this->sources_doc.allocate_string(f_name.c_str());
					char * path = this->sources_doc.allocate_string(f.path().c_str());
					char * package = this->sources_doc.allocate_string(name.c_str());

					rapidxml::xml_node<> * f_info;
					rapidxml::xml_attribute<> * info_attr;
					rapidxml::xml_node<> * f_path;
					rapidxml::xml_node<> * f_package;
					rapidxml::xml_node<> * f_enabled;

					
					if (!xf) {
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
					
					this->mtx.lock();
					this->info_string = std::string(_("Found")) + " : " + file_name;
					this->mtx.unlock();
					this->update_text.emit();
				}
			}
		}
	}

	std::ofstream fout(HOME("sources.xml"));
	if (fout.is_open()) {
		fout << this->sources_doc;
		fout.close();
	}
}

void Libre::PackageManager::connect_dispatcher_signal(Gtk::Label * header, Gtk::Label * info) {
	this->update_text.connect([this, header, info]() {
		this->mtx.lock();
		header->set_text(this->header_string);
		info->set_text(this->info_string);
		this->mtx.unlock();
	});
}
