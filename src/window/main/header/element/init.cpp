#include "element.hpp"
#include "window/main/header/element/element.hpp"

Libre::HeaderElement::HeaderElement() : Gtk::HBox() {
	this->close.set_name("close_button");
	this->pack_end(this->close, Gtk::PACK_SHRINK);
	this->pack_end(this->combo, Gtk::PACK_SHRINK);
}
