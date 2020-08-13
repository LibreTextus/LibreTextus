#include "manage_buttons.hpp"

Libre::BookManagerElements::ManageButtons::ManageButtons() : Gtk::HBox() {
	this->add.set_name("add_button");
	this->remove.set_name("remove_button");
	this->pack_end(this->add, Gtk::PACK_SHRINK, 0);
	this->pack_end(this->remove, Gtk::PACK_SHRINK, 0);
}

Gtk::Button * Libre::BookManagerElements::ManageButtons::get_add() {
	return &this->add;
}

Gtk::Button * Libre::BookManagerElements::ManageButtons::get_remove() {
	return &this->remove;
}
