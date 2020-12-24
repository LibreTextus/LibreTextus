#include "grammar_view.hpp"

Libre::GrammarView::GrammarView() : Gtk::VBox() {
	this->set_name("grammar_view");
}

void Libre::GrammarView::clear() {
	this->labels.clear();
	this->hide();
}

void Libre::GrammarView::append_label(const std::string & s) {
	this->labels.emplace_back(s);
	this->labels.back().set_alignment(Gtk::ALIGN_START, Gtk::ALIGN_START);
	this->pack_start(this->labels.back(), Gtk::PACK_SHRINK);
	this->show_all();
}
