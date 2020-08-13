#include "rapid_textus.hpp"

Libre::RapidTextus::RapidTextus() {
	this->create_settings_file_and_home_if_missing();
	this->init_locales();
	package_manager.init(true);
	this->set_startup_file_if_not_already();
}

void Libre::RapidTextus::create_settings_file_and_home_if_missing() {
	if (!std::experimental::filesystem::exists(HOME())) {
		std::experimental::filesystem::create_directory(HOME());
	}

	if (!std::experimental::filesystem::exists(HOME("settings.xml"))) {
		std::experimental::filesystem::copy(DATA("settings.xml"), HOME("settings.xml"));
	}
}

void Libre::RapidTextus::init_locales() {
	if (settings.get_attribute("locale", "locale").empty()) {
		setlocale(LC_ALL, "");
		setenv("LANGUAGE", std::string(setlocale(LC_ALL, NULL)).substr(0, std::string(setlocale(LC_ALL, NULL)).find_last_of(".")).c_str(), 1);
	} else {
		setlocale(LC_ALL, (settings.get_attribute("locale", "locale") + ".utf8").c_str());
		setenv("LANGUAGE", settings.get_attribute("locale", "locale").c_str(), 1);
	}

	bindtextdomain(GETTEXT_PACKAGE, DATA("../locale").c_str());
	textdomain(GETTEXT_PACKAGE);
}

void Libre::RapidTextus::set_startup_file_if_not_already() {
	if (settings.get_attribute("startupfile", "file").empty()) {
		settings.set("startupfile", "file", package_manager.get_sources().front());
	}
}
