#include "framework.hpp"

void Framework::init_locales() {
	bool locale_is_set = this->widgets.settings.get_attribute("locale", "locale").empty();
	if (locale_is_set) {
		setlocale(LC_ALL, "");
		setenv("LANGUAGE", std::string(setlocale(LC_ALL, NULL)).substr(0, std::string(setlocale(LC_ALL, NULL)).find_last_of(".")).c_str(), 1);
	} else {
		setlocale(LC_ALL, (this->widgets.settings.get_attribute("locale", "locale") + ".utf8").c_str());
		setenv("LANGUAGE", this->widgets.settings.get_attribute("locale", "locale").c_str(), 1);
	}

	bindtextdomain(GETTEXT_PACKAGE, DATA("../locale").c_str());
	textdomain(GETTEXT_PACKAGE);
}
