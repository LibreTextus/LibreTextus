#include "../signal_handler.hpp"

void SignalHandler::theme_changed() {
	LOG("--> \"theme_changed\" emmited");
	this->settings.set("themes", "active", this->widgets->preferences.theme_combo->get_active_text());

	if(!this->widgets->style.css->load_from_path(DATA(this->widgets->preferences.theme_combo->get_active_text() + ".css"))) {
			std::cerr << "Failed to load css\n";
	}
}

void SignalHandler::default_font_size_changed() {
	LOG("--> \"default_font_size_changed\" emmited");
	this->widgets->style.font_size = this->widgets->preferences.font_size_spinbutton->get_value();
	this->settings.set("font", "size", std::to_string(this->widgets->style.font_size));
	this->widgets->style.font_size_css->load_from_data("* { font-size: " + std::to_string(this->widgets->style.font_size) + "px; }");
}

