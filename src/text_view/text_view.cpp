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

	this->refresh_shortcuts();
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
	this->display_all();
}

void Libre::TextView::show_if_results() {
	if (!this->has_results) {
		this->overlay.set_halign(Gtk::ALIGN_CENTER);
		this->overlay.set_valign(Gtk::ALIGN_CENTER);
		this->overlay.remove();
		this->overlay.add(this->no_result_label);
		this->show_all();
	} else {
		this->show_content();
	}
}

void Libre::TextView::clear() {
	for (Libre::TextViewTab<VERSES_SHOWN> * i : this->tabs) {
		i->clear();
	}

	this->tabs.front()->reset_scroll();

	this->has_results = false;
}

void Libre::TextView::add_verse(const std::string & caption, const std::vector<std::string *> & verses_content) {
	this->has_results = true;
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

	if (key->keyval == keymap["scup"])
		s = -1;
	else if (key->keyval == keymap["scdown"])
		s = 1;
	else if (key->keyval == GDK_KEY_Up)
		s = -1;
	else if (key->keyval == GDK_KEY_Down)
		s = 1;
	else if (key->keyval == keymap["sctop"])
		s = -this->tabs.front()->get_verses_amount();
	else if (key->keyval == keymap["scbottom"])
		s = this->tabs.front()->get_verses_amount();
	else if (key->keyval == GDK_KEY_Return)
		this->m_signal_toggle_note.emit(this->tabs.front()->get_active_verse_position());

	if (s != 0) {
		this->tabs.front()->scroll_steps(s);
		this->display_all();
	}

	return false;
}

void Libre::TextView::scroll_to(const size_t & steps) {
	this->tabs.front()->scroll_steps(steps);
	this->display_all();
}

void Libre::TextView::remove_tab(const int & id) {
	this->main.remove(*this->tabs[id]);
	this->tabs.erase(this->tabs.begin() + id);
}

void Libre::TextView::append_tab(const std::string & path) {
	sigc::signal<bool, const std::string &> n_exists;
	n_exists.connect(sigc::mem_fun(this, &Libre::TextView::note_exists));

	sigc::signal<void, const size_t &, const size_t &, const std::string &> so_strongs;
	so_strongs.connect(sigc::mem_fun(this, &Libre::TextView::show_other_strongs));


	this->tabs.push_back(new Libre::TextViewTab<VERSES_SHOWN>(path, &this->m_signal_right_click_search, &this->m_signal_toggle_note, n_exists, &this->m_signal_append_grammar, &this->m_signal_clear_grammar, so_strongs));
	this->tabs.back()->set_source_path(path);
	this->main.pack_start(*this->tabs.back());
}

void Libre::TextView::change_source(const int & id, const std::string & path) {
	this->tabs[id]->set_source_path(path);
}

void Libre::TextView::show_other_strongs(const size_t & id, const size_t & n, const std::string & str) {
	for (Libre::TextViewTab<VERSES_SHOWN> * tab : this->tabs) {
		tab->show_other_strong_at_id(id, n, str);
	}
}

void Libre::TextView::refresh_theme() {
	for (Libre::TextViewTab<VERSES_SHOWN> * tab : this->tabs) {
		tab->refresh_theme();
	}
}

void Libre::TextView::refresh_shortcuts() {
	this->keymap["scup"] = this->settings.get_attribute("scup", "key")[0];
	this->keymap["scdown"] = this->settings.get_attribute("scdown", "key")[0];
	this->keymap["sctop"] = this->settings.get_attribute("sctop", "key")[0];
	this->keymap["scbottom"] = this->settings.get_attribute("scbottom", "key")[0];

	if (this->keymap["scup"] == 0) {
		this->keymap["scup"] = 'k';
		this->settings.set("scup", "key", "k");
	}

	if (this->keymap["scdown"] == 0) {
		this->keymap["scdown"] = 'j';
		this->settings.set("scdown", "key", "j");
	}

	if (this->keymap["sctop"] == 0) {
		this->keymap["sctop"] = 'g';
		this->settings.set("sctop", "key", "g");
	}
	
	if (this->keymap["scbottom"] == 0) {
		this->keymap["scbottom"] = 'G';
		this->settings.set("scbottom", "key", "G");
	}
}
