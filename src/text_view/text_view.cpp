#include "text_view.hpp"

Libre::TextView::TextView(const std::string & info) : Gtk::ScrolledWindow() {

	this->set_name("text_view");
	this->set_can_focus(true);
	this->set_focus_on_click(true);

	this->main.set_name("text_view");
	this->main.set_homogeneous(true);

	this->information_text.set_markup(info);
	this->information_text.set_justify(Gtk::JUSTIFY_CENTER);
	this->information_text.set_line_wrap(true);
	this->information_text.set_line_wrap_mode(Pango::WRAP_WORD);
	this->information_text.set_selectable(true);
	this->information_text.set_can_focus(false);

	this->no_result_label.set_markup("<span size=\"xx-large\">" + std::string(_("No Results")) + "</span>");
	this->no_result_label.set_justify(Gtk::JUSTIFY_CENTER);
	this->no_result_label.set_line_wrap(true);
	this->no_result_label.set_line_wrap_mode(Pango::WRAP_WORD);
	this->no_result_label.set_selectable(true);
	this->no_result_label.set_can_focus(false);
	this->no_result_label.set_name("no_result_label");

	this->add(this->overlay);
	this->overlay.add(this->information_text);
	this->get_vscrollbar()->hide();

	this->scroll_sensitivity = 0.5;
	this->has_results = false;
}

void Libre::TextView::show_information() {
	this->overlay.set_halign(Gtk::ALIGN_CENTER);
	this->overlay.set_valign(Gtk::ALIGN_CENTER);
	this->overlay.remove();
	this->overlay.add(this->information_text);
	this->show_all();
}

void Libre::TextView::show_content() {
	this->overlay.set_halign(Gtk::ALIGN_FILL);
	this->overlay.set_valign(Gtk::ALIGN_FILL);
	this->overlay.remove();
	this->overlay.add(this->main);
	this->show_all();
}

void Libre::TextView::show_if_results() {
	if (this->has_results) {
		this->overlay.set_halign(Gtk::ALIGN_CENTER);
		this->overlay.set_valign(Gtk::ALIGN_CENTER);
		this->overlay.remove();
		this->overlay.add(this->no_result_label);
		this->show_all();
	}
}

void Libre::TextView::clear() {
	for (Libre::TextViewTab<VERSES_SHOWN> * i : this->tabs) {
		i->clear();
	}

	this->has_results = false;
}

void Libre::TextView::add_verse(const std::string & caption, const std::vector<std::string *> & verses_content) {
	for (int i = 0; i < this->tabs.size(); i++) {
		this->tabs[i]->add_verse(caption, (verses_content[i] == nullptr ? "~~~" : *verses_content[i]));
	}
}

void Libre::TextView::replace_verse(const std::string & caption, const int & version, const std::string * verse_content) {
	this->tabs[version]->change_verse(caption, (verse_content == nullptr ? "~~~" : *verse_content));
}

void Libre::TextView::display_all() {
	for (Libre::TextViewTab<VERSES_SHOWN> * i : this->tabs) {
		i->display_all();
	}
}

void Libre::TextView::display(const int & i) {
	for (Libre::TextViewTab<VERSES_SHOWN> * j : this->tabs) {
		j->display(i);
	}
}

bool Libre::TextView::on_scroll_event(GdkEventScroll * scroll_event) {

	this->tabs.front()->scroll_steps(scroll_event->delta_y > this->scroll_sensitivity ?
			1 : (scroll_event->delta_y < -this->scroll_sensitivity ? -1 : 0));

	this->display_all();

	return false;
}

bool Libre::TextView::on_key_press_event(GdkEventKey * key) {

	short int s = 0;

	switch (key->keyval) {
		case GDK_KEY_k: s = -1; break;
		case GDK_KEY_j: s = 1; break;
		case GDK_KEY_Up: s = -1; break;
		case GDK_KEY_Down: s = 1; break;
		case GDK_KEY_Return: this->m_signal_toggle_note.emit(this->tabs.front()->get_active_verse_position()); break;
		case GDK_KEY_G: s = this->tabs.front()->get_verses_amount(); break;
		case GDK_KEY_g: s = -this->tabs.front()->get_verses_amount(); break;
		default: break;
	}

	this->tabs.front()->scroll_steps(s);

	this->display_all();

	return true;
}

void Libre::TextView::remove_tab(const int & id) {
	this->main.remove(*this->tabs[id]);
	this->tabs.erase(this->tabs.begin() + id);
}

void Libre::TextView::append_tab(const std::string & path) {
	sigc::signal<bool, const std::string &> s;
	s.connect(sigc::mem_fun(this, &Libre::TextView::note_exists));

	this->tabs.push_back(new Libre::TextViewTab<VERSES_SHOWN>(path, &this->m_signal_right_click_search, &this->m_signal_toggle_note, s));
	this->tabs.back()->set_source_path(path);
	this->main.pack_start(*this->tabs.back());
}

void Libre::TextView::change_source(const int & id, const std::string & path) {
	this->tabs[id]->set_source_path(path);
}
