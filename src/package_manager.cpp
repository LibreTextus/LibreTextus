#include "package_manager.hpp"

// LIBRE::PACKAGEMANAGER::INIT -------------------------------------------------
// THIS FUNCTION INITIALIZES THE PACKAGEMANAGER. IF THERE IS NO PACKAGE
// INSTALLED IN THE PACKAGE_DIRECTORY IT WILL INSTALL THE DEFAULT
// -----------------------------------------------------------------------------

void Libre::PackageManager::init() {
	this->dummy_path = "data/dummy.yml";
	this->sources = YAML::LoadFile("data/sources.yml");

	// ------------------------------------------
	// GET ROOT DIR AND REPLACE THE *~* WTIH THE
	// HOME DIRECTORY PATH
	// ------------------------------------------

	this->root_path = this->settings.get<std::string>("root_dir");

	if (this->root_path.find("~") == 0) {
		this->root_path.erase(0, 1);
		this->root_path = getenv("HOME") + this->root_path;
	}

	// ------------------------------------------
	// CHECK IF THE ROOT DIRECTORY EXISTS
	// ------------------------------------------

	if (!std::experimental::filesystem::exists(this->root_path)) {
		std::cout << "Create directory at: " << this->root_path << '\n';
		std::experimental::filesystem::create_directory(this->root_path);
	}

	// ------------------------------------------
	// CHECK IF THE ROOT DIRECTORY IS EMPTY
	// ------------------------------------------

	if (std::experimental::filesystem::is_empty(this->root_path)) {
		this->install("http://hackernet.local:3000/LibreTextus/BibleEditions");
		std::experimental::filesystem::rename(this->root_path + "BibleEditions/biblebooks.yml",
																					this->root_path + "biblebooks.yml");
	}
}

// LIBRE::PACKAGEMANAGER::INSTALL ----------------------------------------------
// THIS FUNCTION INSTALLES A NEW SOURCE PACKAGES OVER GIT
// -----------------------------------------------------------------------------

void Libre::PackageManager::install(std::string url) {

	std::string name;

	name = url.substr(url.find_last_of("/") + 1);

	system(("git clone " + url + " " + this->root_path + name).c_str());

	for (auto & i : std::experimental::filesystem::directory_iterator(this->root_path + name)) {
		if (std::experimental::filesystem::is_directory(i.path())) {
			for (auto & f : std::experimental::filesystem::directory_iterator(i.path().string())) {
				if (f.path().extension() == ".yml" || f.path().extension() == ".yaml") {
					std::regex e("[_-]");
					std::string file = std::regex_replace(f.path().stem().string(), e, " ");
					YAML::Node f_info;
					f_info["path"] = f.path().string();
					f_info["package"] = name;
					f_info["enabled"] = true;

					this->sources[file] = f_info;
				}
			}
		}
	}

	YAML::Emitter emitter;
	emitter << this->sources;

	std::ofstream fout("data/sources.yml");
	if (fout.is_open()) {
		fout << emitter.c_str();
		fout.close();
	}

}

// LIBRE::PACKAGEMANAGER::REMOVE -----------------------------------------------
// THIS FUNCTION REMOVES A SOURCE FROM THE ROOT DIRECTORY AND THE SOURCES LIST
// -----------------------------------------------------------------------------

void Libre::PackageManager::remove(std::string package) {
	std::experimental::filesystem::remove_all(this->root_path + package);

	for (YAML::const_iterator i = this->sources.begin(); i != this->sources.end();) {
		if (i->second["package"].as<std::string>() == package) {
			this->sources.remove(i->first);
			continue;
		}
		i++;
	}

	YAML::Emitter emitter;
	emitter << this->sources;

	std::ofstream fout("data/sources.yml");
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

	std::ofstream fout("data/sources.yml");
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

	std::ofstream fout("data/sources.yml");
	if (fout.is_open()) {
		fout << emitter.c_str();
		fout.close();
	}
}

std::vector<std::string> Libre::PackageManager::get_packages() {
	std::vector<std::string> output;

	for (auto & i : std::experimental::filesystem::directory_iterator(this->root_path)) {
		if (std::experimental::filesystem::is_directory(i.path())) {
			output.push_back(i.path().filename().string());
		}
	}

	return output;
}
