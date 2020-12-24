#include "gtkmm/box.h"
#include "view_pane.hpp"

Libre::ViewPane::ViewPane(const std::string & path) : Gtk::Paned(), text_view(path) {
	this->view_container.pack_start(this->text_view);
	this->view_container.pack_end(this->grammar_view, Gtk::PACK_SHRINK);
	this->pack1(this->view_container, true, false);
	this->pack2(this->notebook, false, true);
	this->set_wide_handle(true);
	this->set_position(800);
	this->set_orientation(Gtk::ORIENTATION_VERTICAL);
}
