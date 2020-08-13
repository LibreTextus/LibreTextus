#include "rapid_textus.hpp"

void Libre::RapidTextus::list_sources() {
	std::vector<std::string> * v = &package_manager.get_sources();

	for (std::vector<std::string>::iterator i = v->begin(); i != v->end(); i++) {
		std::cout << *i << (settings.get_attribute("startupfile", "file") == *i ? std::string(" [ \033[1;31m") + _("default") + "\033[0m ]" : "") << '\n';
	}
}
