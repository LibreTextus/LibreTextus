#include "book_manager_pane.hpp"

Libre::BookManagerPane::BookManagerPane() : Gtk::VBox(), default_source(_("Default")) {
	this->pack_start(this->default_source, Gtk::PACK_SHRINK, 0);
	this->pack_start(this->book_list, Gtk::PACK_EXPAND_WIDGET, 0);
	this->pack_start(this->manage_buttons, Gtk::PACK_SHRINK, 0);
}

Libre::PreferencesElement<Gtk::ComboBoxText> * Libre::BookManagerPane::get_default_source() { 
	return &this->default_source;
}

Libre::BookManagerElements::BookList * Libre::BookManagerPane::get_book_list() { 
	return &this->book_list;
}

Libre::BookManagerElements::ManageButtons * Libre::BookManagerPane::get_manage_butons() { 
	return &this->manage_buttons;
}
