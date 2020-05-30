#include "text_view.hpp"

Libre::TextView::TextView(const std::string & info) {
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

	this->add(this->overlay);
	this->get_vscrollbar()->hide();
	this->overlay.add(this->information_text);

	this->padding_x = 10;
	this->padding_y = 10;
	this->max_verses = 20;
	this->tabs = 1;
	this->scroll_status = 0;
	this->scroll_sensitivity = 0.5;

	this->verses.push_back(Gtk::VBox());
	this->v_labels.push_back({});
	this->c_labels.push_back({});
	this->verse_status.push_back({});

	this->verses[this->tabs - 1].set_name("text_view");
	this->verses[this->tabs - 1].set_border_width(5);

	for (int i = 0; i < this->max_verses; i++) {
		this->v_labels[this->tabs - 1].push_back(Gtk::Label());
		this->v_labels[this->tabs - 1][i].set_name("text_view");
		this->v_labels[this->tabs - 1][i].set_line_wrap(true);
		this->v_labels[this->tabs - 1][i].set_alignment(Gtk::ALIGN_START);
		this->v_labels[this->tabs - 1][i].set_line_wrap_mode(Pango::WRAP_WORD);
		this->v_labels[this->tabs - 1][i].set_selectable(true);
		this->v_labels[this->tabs - 1][i].set_can_focus(false);

		this->c_labels[this->tabs - 1].push_back(Gtk::Label());
		this->c_labels[this->tabs - 1][i].set_name("text_view");
		this->c_labels[this->tabs - 1][i].set_line_wrap(true);
		this->c_labels[this->tabs - 1][i].set_alignment(Gtk::ALIGN_START);
		this->c_labels[this->tabs - 1][i].set_line_wrap_mode(Pango::WRAP_WORD);
		this->c_labels[this->tabs - 1][i].set_selectable(true);
		this->c_labels[this->tabs - 1][i].set_can_focus(false);

		this->verse_status[this->tabs - 1].push_back(Gtk::CheckButton());
		this->verse_status[this->tabs - 1][i].set_name("note_toggle");
		this->verse_status[this->tabs - 1][i].set_can_focus(false);

		Gtk::VBox * vbox = new Gtk::VBox;
		vbox->set_name("verse_box");
		Gtk::HBox * hbox = new Gtk::HBox;
		hbox->set_name("text_view");

		hbox->pack_start(this->c_labels[this->tabs - 1][i], Gtk::PACK_SHRINK, 0);
		hbox->pack_start(this->verse_status[this->tabs - 1][i], Gtk::PACK_SHRINK, 5);

		vbox->pack_start(*hbox, Gtk::PACK_SHRINK, 0);
		vbox->pack_start(this->v_labels[this->tabs - 1][i], Gtk::PACK_EXPAND_WIDGET, 0);

		this->verses[this->tabs - 1].pack_start(*vbox, Gtk::PACK_EXPAND_WIDGET, this->padding_x);
	}

	this->verses[0].get_children()[0]->set_name("active_verse");

	this->main.pack_start(this->verses[0], Gtk::PACK_EXPAND_WIDGET, 5);
}

void Libre::TextView::show_information() {
	this->overlay.set_halign(Gtk::ALIGN_CENTER);
	this->overlay.set_valign(Gtk::ALIGN_CENTER);
	this->overlay.remove();
	this->overlay.add(this->information_text);
}

void Libre::TextView::show_content() {
	this->overlay.set_halign(Gtk::ALIGN_FILL);
	this->overlay.set_valign(Gtk::ALIGN_FILL);
	this->overlay.remove();
	this->overlay.add(this->main);
}

void Libre::TextView::clear() {
	this->content.clear();
	this->captions.clear();

	this->scroll_status = 0;

	this->_display(0);
}


void Libre::TextView::add_verse(const std::string & caption, const std::vector<std::string *> & verses_content) {
	this->content.push_back({});
	for (int i = 0; i < this->tabs; i++) {
		this->content[this->content.size() - 1].push_back((verses_content[i] == nullptr ? "~~~" : *verses_content[i]));
	}

	this->captions.push_back(caption);

	this->_display(this->captions.size() - 1);
}

void Libre::TextView::replace_verse(const std::string & caption, const int & version, const std::string * verse_content) {
	int verse_id = std::distance(this->captions.begin(), std::find(this->captions.begin(), this->captions.end(), caption));
	this->content[verse_id][version] = (verse_content == nullptr ? "~~~" : *verse_content);

	this->_display((verse_id >= this->scroll_status && verse_id < (this->scroll_status + this->max_verses) ?
									verse_id - this->scroll_status : this->max_verses));
}

void Libre::TextView::_display(int begin) {

	this->show_all();

	for (int i = begin; i < this->max_verses; i++) {
		for (int x = 0; x < this->tabs; x++) {
			if (i < this->captions.size() - this->scroll_status) {
				this->c_labels[x][i].set_text(this->captions[i + this->scroll_status]);
				this->v_labels[x][i].set_markup(this->content[i + this->scroll_status][x]);
				this->verse_status[x][i].set_active((this->note_book_file[this->captions[i + this->scroll_status]] ? true : false));
				this->verse_status[x][i].signal_released().connect([this, i]() {
					this->m_signal_toggle_note.emit(this->captions[i + this->scroll_status]);
					for (int x = 0; x < this->tabs; x++) {
						this->verse_status[x][i].set_active(true);
					}
				});
			} else {
				this->c_labels[x][i].hide();
				this->v_labels[x][i].hide();
				this->verse_status[x][i].hide();
			}
		}
	}
}

bool Libre::TextView::on_scroll_event(GdkEventScroll * scroll_event) {

	if (this->captions.size() == 0) {
		return false;
	}

	this->scroll_status += (
		scroll_event->delta_y > this->scroll_sensitivity ?
		1 :
		(scroll_event->delta_y < -this->scroll_sensitivity ? -1 : 0));

	if (this->scroll_status < 0) {
		this->scroll_status = 0;

	} else if (this->scroll_status >= this->captions.size()) {
		this->scroll_status = this->captions.size() - 1;
	}

	this->_display(0);

	return false;
}

bool Libre::TextView::on_key_press_event(GdkEventKey * key) {

	if (this->captions.size() == 0) {
		return true;
	}

	switch (key->keyval) {
		case 107: this->scroll_status -= 1; break;
		case 106: this->scroll_status += 1; break;
		case 65362: this->scroll_status -= 1; break;
		case 65364: this->scroll_status += 1; break;
		case 65293: this->m_signal_toggle_note.emit(this->captions[this->scroll_status]); break;
		default: this->error_bell(); break;
	}

	if (this->scroll_status < 0) {
		this->scroll_status = 0;
		this->error_bell();

	} else if (this->scroll_status >= this->captions.size()) {
		this->scroll_status = this->captions.size() - 1;
		this->error_bell();
	}

	if (this->main.is_visible()) {
		this->_display(0);
	}

	return true;
}

void Libre::TextView::remove_tab(const int & id) {
	this->tabs--;

	this->verses[id].get_parent()->remove(this->verses[id]);

	for (int i = 0; i < this->max_verses; i++) {
		this->c_labels[id][i].get_parent()->remove(this->c_labels[id][i]);
		this->v_labels[id][i].get_parent()->remove(this->v_labels[id][i]);
		this->verse_status[id][i].get_parent()->remove(this->verse_status[id][i]);
	}

	this->verses.erase(this->verses.begin() + id);
	this->c_labels.erase(this->c_labels.begin() + id);
	this->v_labels.erase(this->v_labels.begin() + id);
	this->verse_status.erase(this->verse_status.begin() + id);

	for (int i = 0; i < this->content.size(); i++) {
		this->content[i].erase(this->content[i].begin() + id);
	}

	this->verses[0].get_children()[0]->set_name("active_verse");
}

void Libre::TextView::append_tab() {
	this->tabs++;

	this->verses.push_back(Gtk::VBox());
	this->v_labels.push_back({});
	this->c_labels.push_back({});
	this->verse_status.push_back({});

	this->verses[this->tabs - 1].set_name("text_view");
	this->verses[this->tabs - 1].set_border_width(5);

	for (int i = 0; i < this->max_verses; i++) {
		this->v_labels[this->tabs - 1].push_back(Gtk::Label());
		this->v_labels[this->tabs - 1][i].set_name("text_view");
		this->v_labels[this->tabs - 1][i].set_line_wrap(true);
		this->v_labels[this->tabs - 1][i].set_alignment(Gtk::ALIGN_START);
		this->v_labels[this->tabs - 1][i].set_line_wrap_mode(Pango::WRAP_WORD);
		this->v_labels[this->tabs - 1][i].set_selectable(true);
		this->v_labels[this->tabs - 1][i].set_can_focus(false);

		this->c_labels[this->tabs - 1].push_back(Gtk::Label());
		this->c_labels[this->tabs - 1][i].set_name("text_view");
		this->c_labels[this->tabs - 1][i].set_line_wrap(true);
		this->c_labels[this->tabs - 1][i].set_alignment(Gtk::ALIGN_START);
		this->c_labels[this->tabs - 1][i].set_line_wrap_mode(Pango::WRAP_WORD);
		this->c_labels[this->tabs - 1][i].set_selectable(true);
		this->c_labels[this->tabs - 1][i].set_can_focus(false);

		this->verse_status[this->tabs - 1].push_back(Gtk::CheckButton());
		this->verse_status[this->tabs - 1][i].set_name("note_toggle");
		this->verse_status[this->tabs - 1][i].set_can_focus(false);

		Gtk::VBox * vbox = new Gtk::VBox;
		vbox->set_name("verse_box");
		Gtk::HBox * hbox = new Gtk::HBox;
		hbox->set_name("text_view");

		hbox->pack_start(this->c_labels[this->tabs - 1][i], Gtk::PACK_SHRINK, 0);
		hbox->pack_start(this->verse_status[this->tabs - 1][i], Gtk::PACK_SHRINK, 5);

		vbox->pack_start(*hbox, Gtk::PACK_SHRINK, 0);
		vbox->pack_start(this->v_labels[this->tabs - 1][i], Gtk::PACK_EXPAND_WIDGET, 0);

		this->verses[this->tabs - 1].pack_start(*vbox, Gtk::PACK_EXPAND_WIDGET, this->padding_x);
	}

	this->main.pack_start(this->verses[this->tabs - 1], Gtk::PACK_EXPAND_WIDGET, 5);

	for (int i = 0; i < this->content.size(); i++) {
		this->content[i].push_back("");
	}
}
