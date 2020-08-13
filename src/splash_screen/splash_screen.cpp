#include "splash_screen.hpp"
#include <iostream>

Libre::SplashScreen::SplashScreen() : Window() {
	this->container.set_border_width(10);
	this->title.set_markup("<span font='42'>LibreTextus</span>");
	this->spinner.set_size_request(70, 70);

	this->container.pack_start(this->title, Gtk::PACK_EXPAND_WIDGET, 0);
	this->container.pack_start(this->header, Gtk::PACK_SHRINK, 5);
	this->container.pack_start(this->info, Gtk::PACK_SHRINK, 10);
	this->container.pack_start(this->spinner, Gtk::PACK_SHRINK, 10);

	this->set_default_size(640, 315);
	this->set_default_icon_from_file(DATA("icon.svg"));
	this->set_type_hint(Gdk::WINDOW_TYPE_HINT_SPLASHSCREEN);
	this->set_resizable(false);
	this->set_name("splash_screen");

	this->add(this->container);

}

Gtk::Label * Libre::SplashScreen::get_header() {
	return &this->header;
}

Gtk::Label * Libre::SplashScreen::get_info() {
	return &this->info;
}

Gtk::Spinner * Libre::SplashScreen::get_spinner() {
	return &this->spinner;
}
