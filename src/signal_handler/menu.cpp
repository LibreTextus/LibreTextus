#include "../signal_handler.hpp"

void SignalHandler::toggle_fullscreen() {
	LOG("--> \"toggle_fullscreen\" emmited");
	if (this->widgets->main.is_fullscreen)
		this->widgets->main.window->unfullscreen();
	else
		this->widgets->main.window->fullscreen();

	this->widgets->main.is_fullscreen = !this->widgets->main.is_fullscreen;
}

void SignalHandler::toggle_iconify() {
	LOG("--> \"toggle_iconify\" emmited");
	this->widgets->main.window->iconify();
}


void SignalHandler::toggle_preferences() {
	LOG("--> \"toggle_preferences\" emmited");
	this->widgets->preferences.window->show_all();
	this->widgets->preferences.window->raise();
}

void SignalHandler::zoom_in() {
	LOG("--> \"zoom_in\" emmited");
	this->widgets->style.font_size += 2;
	this->widgets->style.font_size_css->load_from_data("* { font-size: " + std::to_string(this->widgets->style.font_size) + "px; }");
}

void SignalHandler::zoom_out() {
	LOG("--> \"zoom_out\" emmited");
	this->widgets->style.font_size -= 2;
	if (this->widgets->style.font_size < 1) {
		this->widgets->style.font_size = 1;
	}
	this->widgets->style.font_size_css->load_from_data("* { font-size: " + std::to_string(this->widgets->style.font_size) + "px; }");
}

void SignalHandler::zoom_reset() {
	LOG("--> \"zoom_reset\" emmited");
	this->widgets->style.font_size = std::stoi(this->settings.get_attribute("font", "size"));
	this->widgets->style.font_size_css->load_from_data("* { font-size: " + std::to_string(this->widgets->style.font_size) + "px; }");
}

