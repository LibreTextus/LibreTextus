#include "view_pane.hpp"

Libre::ViewPane::ViewPane(const std::string & path) : Gtk::Paned(), text_view(path) {
	this->pack1(this->text_view, true, false);
	this->pack2(this->notebook, false, true);
	this->set_wide_handle(true);
	this->set_position(800);
	this->set_orientation(Gtk::ORIENTATION_VERTICAL);
}
