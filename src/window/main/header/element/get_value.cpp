#include "element.hpp"

Gtk::ComboBoxText * Libre::HeaderElement::get_combo() {
	return &this->combo;
}

Gtk::Button * Libre::HeaderElement::get_close() {
	return &this->close;
}

std::vector<std::string> * Libre::HeaderElement::get_combo_content() {
	return &this->combo_content;
}

