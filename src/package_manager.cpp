#include "package_manager.hpp"

// LIBRE::PACKAGEMANAGER::INIT -------------------------------------------------
// THIS FUNCTION INITIALIZES THE PACKAGEMANAGER. IF THERE IS NO PACKAGE
// INSTALLED IN THE PACKAGE_DIRECTORY IT WILL INSTALL THE DEFAULT
// -----------------------------------------------------------------------------

void Libre::PackageManager::init() {

  this->root_path = this->settings.get<std::string>("root_dir");

	if (this->root_path.find("~") == 0) {
		this->root_path.erase(0, 1);
		this->root_path = getenv("HOME") + this->root_path;
	}

	if (!std::experimental::filesystem::exists(this->root_path)) {
		std::cout << "Create directory at: " << this->root_path << '\n';
		std::experimental::filesystem::create_directory(this->root_path);
	}

	if (std::experimental::filesystem::is_empty(this->root_path)) {
		system(("git clone http://hackernet.local:3000/LibreTextus/BibleEditions " + this->root_path + "BibleEditions/").c_str());
		std::experimental::filesystem::rename(this->root_path + "BibleEditions/biblebooks.yml",
																					this->root_path + "biblebooks.yml");
	}

}

void Libre::PackageManager::install() {

}

void Libre::PackageManager::remove() {

}

void Libre::PackageManager::disable() {

}

void Libre::PackageManager::enable() {

}
