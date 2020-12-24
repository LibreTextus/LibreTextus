#include "grammar_view.hpp"
#include "gtkmm/box.h"

Libre::GrammarView::GrammarView() : Gtk::HBox() {
	this->set_name("grammar_view");
}

void Libre::GrammarView::clear() {
	this->labels.clear();
	this->boxes.clear();
	this->hide();
}

void Libre::GrammarView::append_label(const std::string & s) {
	this->labels.emplace_back(s);
	this->labels.back().set_alignment(Gtk::ALIGN_START, Gtk::ALIGN_START);

	if (this->boxes.empty()) {
		this->boxes.emplace_back();
		this->boxes.back().set_name("grammar_sub_view");
		this->boxes.back().pack_start(this->labels.back(), Gtk::PACK_SHRINK);
		this->pack_start(this->boxes.back(), Gtk::PACK_SHRINK);
	} else if (this->boxes.back().get_children().size() == 3) {
		this->boxes.emplace_back();
		this->boxes.back().set_name("grammar_sub_view");
		this->boxes.back().pack_start(this->labels.back(), Gtk::PACK_SHRINK);
		this->pack_start(this->boxes.back(), Gtk::PACK_SHRINK);
	} else {
		this->boxes.back().pack_start(this->labels.back(), Gtk::PACK_SHRINK);
	}

	this->show_all();
}
