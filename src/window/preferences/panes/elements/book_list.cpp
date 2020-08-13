#include "book_list.hpp"

Libre::BookManagerElements::BookList::BookList() : Gtk::ScrolledWindow() {
	this->add(this->container);
}

void Libre::BookManagerElements::BookList::append(const std::string & name) {
	Gtk::CheckButton * item = new Gtk::CheckButton(name);
	this->items.push_back(item);
	this->container.pack_start(*this->items.back(), Gtk::PACK_SHRINK, 0);
}

Gtk::VBox * Libre::BookManagerElements::BookList::get_container() {
	return &this->container;
}

std::vector<Gtk::CheckButton *> * Libre::BookManagerElements::BookList::get_items() {
	return &this->items;
}

