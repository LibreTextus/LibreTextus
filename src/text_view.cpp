#include "text_view.hpp"

Libre::TextView::TextView() {
	this->set_name("text_view");
	this->main.set_name("text_view");
	this->add(this->main);
	this->get_vscrollbar()->hide();
	this->padding_x = 10;
	this->padding_y = 10;
	this->max_verses = 10;
	this->scroll_status = 0;
}

void Libre::TextView::clear() {
	for (int i = 0; i < this->verses.size(); i++) {
		Gtk::Widget * w = this->verses[i];
		this->main.remove(*w);
		delete w;
	}

	this->verses.clear();
	this->captions.clear();
	this->content.clear();
}


void Libre::TextView::add_verse(const std::string & caption, const std::vector<std::string> & verses_content) {
	this->captions.push_back(caption);
	this->content.push_back(verses_content);

	this->verses.push_back(new Gtk::HBox);
	this->verses.back()->set_homogeneous(true);
	this->verses.back()->set_name("text_view");

	for (int i = 0; i < verses_content.size(); i++) {
		Gtk::Label * l = new Gtk::Label;
		l->set_name("text_view");
		l->set_line_wrap(true);
		l->set_alignment(Gtk::ALIGN_START);
		l->set_line_wrap_mode(Pango::WRAP_WORD);
		l->set_markup(caption + "\n" + verses_content[i]);
		this->verses.back()->pack_start(*l, Gtk::PACK_EXPAND_WIDGET, this->padding_x);
	}

	this->_display();
}

void Libre::TextView::replace_verse(const std::string & caption, const int & version, const std::string & content) {
	int verse_id = std::distance(this->captions.begin(), std::find(this->captions.begin(), this->captions.end(), caption));

	if (this->verses[verse_id]->get_children().size() > version) {
		Gtk::Widget * old_l = this->verses[verse_id]->get_children()[version];
		this->verses[verse_id]->remove(*old_l);
		delete old_l;
	}

	Gtk::Label * l = new Gtk::Label;
	l->set_name("text_view");
	l->set_line_wrap(true);
	l->set_alignment(Gtk::ALIGN_START);
	l->set_line_wrap_mode(Pango::WRAP_WORD);
	l->set_markup(caption + "\n" + content);

	this->verses[verse_id]->pack_start(*l, Gtk::PACK_EXPAND_WIDGET, this->padding_x);
	this->verses[verse_id]->reorder_child(*l, version);

	this->_display();
}

void Libre::TextView::_display() {
	for (int i = 0; i < this->verses.size(); i++) {
		this->main.remove(*this->verses[i]);
	}

	for (int i = 0; i < (this->verses.size() < this->max_verses ? this->verses.size() : this->max_verses); i++) {
		this->main.pack_start(*this->verses[i + this->scroll_status], Gtk::PACK_EXPAND_WIDGET, this->padding_y);
	}

	this->show_all();
}

bool Libre::TextView::on_scroll_event(GdkEventScroll * scroll_event) {
	this->scroll_status += scroll_event->delta_y;

	if (this->scroll_status < 0) {
		this->scroll_status = 0;
		this->get_vscrollbar()->set_value(this->get_vscrollbar()->get_value() - this->verses[this->scroll_status + this->max_verses - 1]->get_height());
		this->_display();
	}

	if (this->scroll_status >= this->verses.size() - this->max_verses) {
		this->scroll_status = this->verses.size() - this->max_verses;
		this->get_vscrollbar()->set_value(this->get_vscrollbar()->get_value() + this->verses[this->scroll_status]->get_height());
		this->_display();
	}

	this->_display();

	return false;
}

void Libre::TextView::remove_tab(const int & id) {
	for (int i = 0; i < this->verses.size(); i++) {
		Gtk::Widget * w = this->verses[i]->get_children()[id];
		this->verses[i]->remove(*w);
		delete w;
	}

	this->_display();
}