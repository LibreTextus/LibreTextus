#include "package_manager.hpp"

// LIBRE::PACKAGEMANAGER::INIT -------------------------------------------------
// THIS FUNCTION INITIALIZES THE PACKAGEMANAGER. IF THERE IS NO PACKAGE
// INSTALLED IN THE PACKAGE_DIRECTORY IT WILL INSTALL THE DEFAULT
// -----------------------------------------------------------------------------

void Libre::PackageManager::init() {
	this->dummy_path = DATA("dummy.yml");

	// ------------------------------------------
	// CHECK IF THE ROOT DIRECTORY EXISTS
	// ------------------------------------------

	if (!std::experimental::filesystem::exists(HOME())) {
		std::experimental::filesystem::create_directory(HOME());
	}

	// ------------------------------------------
	// CHECK IF THE ROOT DIRECTORY IS EMPTY
	// ------------------------------------------

	if (std::experimental::filesystem::is_empty(HOME())) {
		std::experimental::filesystem::copy(DATA("sources.yml"), HOME("sources.yml"));
		std::experimental::filesystem::copy(DATA("settings.yml"), HOME("settings.yml"));
		this->sources = YAML::LoadFile(DATA("sources.yml"));
		this->install("git://github.com/LibreTextus/BibleEditions");
		std::experimental::filesystem::rename(HOME("BibleEditions/biblebooks.yml"),
																					HOME("biblebooks.yml"));
	} else {
		this->sources = YAML::LoadFile(HOME("sources.yml"));
	}

	for (YAML::const_iterator i = this->sources.begin(); i != this->sources.end(); i++) {
		if (std::find(this->packages.begin(), this->packages.end(), i->second["package"].as<std::string>()) == this->packages.end()) {
			this->packages.push_back(i->second["package"].as<std::string>());
		}
	}

	this->update();
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
	// GO THROUGH EVERY DIRECTORY IN THE PACKAGE
	// ROOT DIRECTORY AND LOOK IF THERE ARE
	// SOURCE YAML FILES
	// ------------------------------------------

	for (auto & i : std::experimental::filesystem::directory_iterator(HOME(name))) {
		if (std::experimental::filesystem::is_directory(i.path())) {
			for (auto & f : std::experimental::filesystem::directory_iterator(i.path().string())) {
				if (f.path().extension() == ".yml" || f.path().extension() == ".yaml") {
					std::regex e("[_-]");
					std::string file = std::regex_replace(f.path().stem().string(), e, " ");
					YAML::Node f_info;
					f_info["path"] = f.path().string();
					f_info["package"] = name;
					f_info["enabled"] = true;

					this->mtx.lock();
					this->info_string = std::string(_("Found")) + " : " + file;
					this->mtx.unlock();
					this->update_text.emit();

					this->sources[file] = f_info;
				}
			}
		}
	}

	// ------------------------------------------
	// DISPLAY FOLLOWING INFORMATION:
	// 		Update sources.yml
	// ------------------------------------------

	this->mtx.lock();
	this->header_string = _("Update sources.yml");
	this->info_string = "";
	this->mtx.unlock();
	this->update_text.emit();

	// ------------------------------------------
	// WRITE EVERYTHING TO THE SOURCES FILE
	// ------------------------------------------

	YAML::Emitter emitter;
	emitter << this->sources;

	std::ofstream fout(HOME("sources.yml"));
	if (fout.is_open()) {
		fout << emitter.c_str();
		fout.close();
	}
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
	this->header_string = _("Update sources.yml");
	this->info_string = "";
	this->mtx.unlock();
	this->update_text.emit();

	// ------------------------------------------
	// REMOVE EVERY SOURCE OF THE PACKAGE FROM
	// YAML NODE
	// ------------------------------------------

	for (YAML::const_iterator i = this->sources.begin(); i != this->sources.end();) {
		if (i->second["package"].as<std::string>() == package) {
			this->sources.remove(i->first);
			this->mtx.lock();
			this->info_string = std::string(_("Removing")) + " " + i->first.as<std::string>();
			this->mtx.unlock();
			this->update_text.emit();
			continue;
		}
		i++;
	}

	// ------------------------------------------
	// WRITE THE NEW SOURCES LIST
	// ------------------------------------------

	this->mtx.lock();
	this->info_string = "";
	this->mtx.unlock();
	this->update_text.emit();

	YAML::Emitter emitter;
	emitter << this->sources;

	std::ofstream fout(HOME("sources.yml"));
	if (fout.is_open()) {
		fout << emitter.c_str();
		fout.close();
	}
}

// LIBRE::PACKAGEMANAGER::DISABLE ----------------------------------------------
// THIS FUNCTION DOES NOT REMOVE THE SOURCE IT JUST MAKES THAT THE SOURCE IS NOT
// LISTED ON THE COMBOBOXTEXT
// -----------------------------------------------------------------------------

void Libre::PackageManager::disable(std::string package) {
	this->sources[package]["enabled"] = false;

	YAML::Emitter emitter;
	emitter << this->sources;

	std::ofstream fout(HOME("sources.yml"));
	if (fout.is_open()) {
		fout << emitter.c_str();
		fout.close();
	}
}

// LIBRE::PACKAGEMANAGER::ENABLE -----------------------------------------------
// THIS FUNCTION ADDS THE SOURCE TO THE COMBOBOXTEXT SO YOU CAN SELECT IT
// -----------------------------------------------------------------------------

void Libre::PackageManager::enable(std::string package) {
	this->sources[package]["enabled"] = true;

	YAML::Emitter emitter;
	emitter << this->sources;

	std::ofstream fout(HOME("sources.yml"));
	if (fout.is_open()) {
		fout << emitter.c_str();
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
	}
}

// LIBRE::PACKAGEMANAGER::GET_PACKAGES -----------------------------------------
// RETURN NAMES OF THE INSTALLED PACKAGES
// -----------------------------------------------------------------------------

std::vector<std::string> & Libre::PackageManager::get_packages() {
	return this->packages;
}
