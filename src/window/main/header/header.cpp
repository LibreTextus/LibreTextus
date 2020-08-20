#include "header.hpp"
#include "gtkmm/box.h"
#include <iostream>

Libre::Header::Header() : Gtk::HBox() {
	this->set_border_width(10);
	this->set_spacing(5);
	this->set_homogeneous(true);
	this->add.set_name("add_button");
}

void Libre::Header::remove_element(const int & i) {
	if (i == elements.size() - 1) {
		this->elements[i]->remove(this->add);
		this->elements[i - 1]->pack_end(this->add, Gtk::PACK_SHRINK);
		this->elements[i - 1]->reorder_child(this->add, 0);
	}
	this->remove(*this->elements[i]);
	delete this->elements[i];
	this->elements.erase(this->elements.begin() + i);
}

void Libre::Header::append() {
	Libre::HeaderElement * element = new Libre::HeaderElement;
	*element->get_combo_content() = this->combo_content;
	element->refresh_combo();

	if (!elements.empty()) {
		this->elements.back()->remove(this->add);
	}

	element->pack_end(this->add, Gtk::PACK_SHRINK);
	element->reorder_child(this->add, 0);

	this->elements.push_back(element);
	this->pack_start(*element);
}

std::vector<Libre::HeaderElement *> * Libre::Header::get_elements() {
	return &this->elements;
}

Gtk::Button * Libre::Header::get_add() {
	return &this->add;
}

std::vector<std::string> * Libre::Header::get_combo_content() {
	return &this->combo_content;
}

void Libre::Header::refresh() {
	for (Libre::HeaderElement * i : elements) {
		*i->get_combo_content() = this->combo_content;
		i->refresh_combo();
	}
}
