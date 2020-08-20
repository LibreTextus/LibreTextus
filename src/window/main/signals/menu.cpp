#include "../main.hpp"

void Libre::MainWindow::toggle_fullscreen() {
	LOG("--> \"toggle_fullscreen\" emmited");
	if (this->is_fullscreen)
		this->unfullscreen();
	else
		this->fullscreen();

	this->is_fullscreen = !this->is_fullscreen;
}

void Libre::MainWindow::toggle_iconify() {
	LOG("--> \"toggle_iconify\" emmited");
	this->iconify();
}


void Libre::MainWindow::toggle_preferences() {
	LOG("--> \"toggle_preferences\" emmited");
	this->preferences_window->show_all();
	this->preferences_window->raise();
}

void Libre::MainWindow::zoom_in() {
	LOG("--> \"zoom_in\" emmited");
	this->preferences_window->increase_font_size(2);
}

void Libre::MainWindow::zoom_out() {
	LOG("--> \"zoom_out\" emmited");
	this->preferences_window->increase_font_size(-2);
}

void Libre::MainWindow::zoom_reset() {
	this->preferences_window->reset_font_size();
}

