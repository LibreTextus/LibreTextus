#include "search_section.hpp"

Libre::SearchSection::SearchSection() : Gtk::HBox() {
	this->search_entry.set_placeholder_text(_("Search"));
	
	this->pack_start(this->history_button, Gtk::PACK_SHRINK, 0);
	this->pack_start(this->search_entry, Gtk::PACK_EXPAND_WIDGET, 0);
	this->pack_start(this->number_results, Gtk::PACK_SHRINK, 10);

	this->set_name("search_entry");
}
