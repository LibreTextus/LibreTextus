#include "../notebook.hpp"

void Libre::NoteBook::pack_children() {
	this->scrolled_window.add(this->text_view);
	this->header.pack_end(this->close_button, Gtk::PACK_SHRINK, 0);
	this->header.pack_start(this->title, Gtk::PACK_SHRINK, 0);
	this->pack_start(this->header, Gtk::PACK_SHRINK, 0);
	this->pack_start(this->scrolled_window, Gtk::PACK_EXPAND_WIDGET, 0);
}
