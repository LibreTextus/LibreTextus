#include "../framework.hpp"

void Framework::create_home_directory_if_missing() {
	bool home_directory_not_existing = !std::experimental::filesystem::exists(HOME());
	if (home_directory_not_existing) {
		std::experimental::filesystem::create_directory(HOME());
	}
}

void Framework::create_settings_file_if_missing() {
	bool settings_file_not_existing = !std::experimental::filesystem::exists(HOME("settings.xml"));
	if (settings_file_not_existing) {
		std::experimental::filesystem::copy(DATA("settings.xml"), HOME("settings.xml"));
	}
}
