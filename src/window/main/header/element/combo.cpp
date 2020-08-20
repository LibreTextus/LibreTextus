#include "element.hpp"

#include <iostream>

void Libre::HeaderElement::refresh_combo() {
	
	std::string active = this->combo.get_active_text();
	this->combo.remove_all();

	for (std::vector<std::string>::iterator i = this->combo_content.begin(); i != this->combo_content.end(); i++) {
		this->combo.append(*i);
	}

	this->combo.set_active_text(active);

	if (this->combo.get_active_text().empty()) {
		this->combo.set_active_text(this->settings.get_attribute("startupfile", "file"));
	}
}

