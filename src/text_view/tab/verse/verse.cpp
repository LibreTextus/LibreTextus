#include "verse.hpp"
#include <iostream>

Libre::TextViewVerse::TextViewVerse() : Gtk::VBox() {
	this->mark_color = this->get_mark_color();

	this->button.set_name("note_toggle");
	this->button.signal_released().connect([this]() { this->toggle_note->emit(this->caption.get_text()); });
	
	this->caption.set_name("text_view");
	this->caption.set_alignment(Gtk::ALIGN_START);
	this->caption.set_selectable(true);
	this->caption.set_can_focus(false);
	this->caption.set_line_wrap(true);
	this->caption.set_line_wrap_mode(Pango::WRAP_WORD);

	this->verse.set_name("text_view");
	this->verse.set_alignment(Gtk::ALIGN_START);
	this->verse.set_selectable(true);
	this->verse.set_can_focus(false);
	this->verse.set_line_wrap(true);
	this->verse.set_line_wrap_mode(Pango::WRAP_WORD);
	this->verse.signal_populate_popup().connect(sigc::mem_fun(this, &Libre::TextViewVerse::label_populate_popup));
	this->verse.signal_motion_notify_event().connect(sigc::mem_fun(this, &Libre::TextViewVerse::label_mouse_motion));

	this->verse.signal_leave_notify_event().connect([this](GdkEventCrossing *) -> bool {
			this->verse.set_markup(this->verse_content); this->last_mark_index = -1; return false; });

	this->caption.signal_populate_popup().connect(sigc::mem_fun(this, &Libre::TextViewVerse::label_populate_popup));

	this->header_box.set_name("text_view");
	this->header_box.pack_start(this->caption, Gtk::PACK_SHRINK, 0);
	this->header_box.pack_start(this->button, Gtk::PACK_SHRINK, 0);
	
	this->set_name("verse_box");
	this->pack_start(this->header_box, Gtk::PACK_SHRINK, 0);
	this->pack_start(this->verse, Gtk::PACK_EXPAND_WIDGET, 0);

	this->caption.set_text("");
	this->verse.set_text("");
}

void Libre::TextViewVerse::set_caption(const std::string & c) {
	this->caption.set_markup(c);
}

void Libre::TextViewVerse::set_verse(const std::string & v) {
	this->verse.set_markup(v);
	this->verse_content = v;
}

void Libre::TextViewVerse::set_strongs(tsl::ordered_map<std::string, std::string> * v) {
	this->strongs = v;
}

void Libre::TextViewVerse::set_grammar(tsl::ordered_map<std::string, std::vector<std::string> *> * v) {
	this->grammar = v;
}


Gtk::Label * Libre::TextViewVerse::get_caption_label() {
	return &this->caption;
}

Gtk::Label * Libre::TextViewVerse::get_verse_label() {
	return &this->verse;
}

void Libre::TextViewVerse::set_trigger_search(sigc::signal<void, std::string> * s) {
	this->trigger_search = s;
}

void Libre::TextViewVerse::set_toggle_note(sigc::signal<void, std::string> * s) {
	this->toggle_note = s;
}

void Libre::TextViewVerse::set_note_exits(sigc::signal<bool, const std::string &> * s) {
	this->note_exists = s;
}

void Libre::TextViewVerse::set_append_grammar(sigc::signal<void, std::string> * s) {
	this->append_grammar = s;
}

void Libre::TextViewVerse::set_clear_grammar(sigc::signal<void> * s) {
	this->clear_grammar = s;
}

void Libre::TextViewVerse::label_populate_popup(Gtk::Menu * menu) {
	int begin;
	int end;
	std::string selection;

	menu->prepend(*(new Gtk::SeparatorMenuItem));
	Gtk::MenuItem * show_context = new Gtk::MenuItem(_("Show Context"));
	show_context->signal_button_release_event().connect([this] (GdkEventButton *) {
			this->trigger_search->emit(this->caption.get_text() + "+");
			return false;
	});
	menu->prepend(*show_context);

	this->verse.get_selection_bounds(begin, end);
	selection = this->verse.get_text().substr(begin, end - begin);

	if (!selection.empty()) {

		menu->prepend(*(new Gtk::SeparatorMenuItem));

		if (this->strongs != nullptr) {
			if (!(*this->strongs)[selection].empty()) {
				Gtk::MenuItem * strong_search_item = new Gtk::MenuItem(
						std::string(_("Search Strong")) + " \"" + (*this->strongs)[selection] + "\""
						);

				menu->prepend(*strong_search_item);

				strong_search_item->signal_button_release_event().connect([this, selection](GdkEventButton *) {
						this->trigger_search->emit("[str " + (*this->strongs)[selection] + "]");
						return false;
						});
			}
		}

		Gtk::MenuItem * search_item = new Gtk::MenuItem(std::string(_("Search")) + " \"" + selection + "\"");
		menu->prepend(*search_item);
		
		search_item->signal_button_release_event().connect([this, selection](GdkEventButton *) {
				this->trigger_search->emit(selection);
				return false;
		});

	}
	menu->show_all();
}

bool Libre::TextViewVerse::label_mouse_motion(GdkEventMotion * event) {

	int offx, offy;
	this->verse.get_layout_offsets(offx, offy);

	int px, py;
	this->verse.get_layout()->get_pixel_size(px, py);

	int cx = event->x * Pango::SCALE, cy = event->y * Pango::SCALE;

	int index = 0, trailing;
	this->verse.get_layout()->xy_to_index(cx, cy, index, trailing);
	
	if (index > 0)
		index = Glib::ustring(this->verse.get_text().raw().substr(0, index)).size();
	
	if (index == this->last_mark_index)
		return false;

	this->last_mark_index = index;

	if (index >= 0 && index < this->verse.get_text().size()) {
		if (this->is_non_word(this->verse.get_text()[index]))
			return false;

		int begin = index, end = index;

		while (begin > 0) {
			--begin;
			if (this->is_non_word(this->verse.get_text()[begin])) {
				++begin;
				break;
			}
		}

		while (end < this->verse.get_text().size()) {
			++end;
			if (this->is_non_word(this->verse.get_text()[end]))
				break;
		}

		Glib::ustring word = this->verse.get_text().substr(begin, end - begin);
		this->clear_grammar->emit();

		if (this->strongs != nullptr) {
			if (!(*this->strongs)[word].empty()) {
				this->append_grammar->emit(_("Strong: ") +  (*this->strongs)[word]);
			}
		}

		if (this->grammar != nullptr) {
			if ((*this->grammar)[word] != nullptr) {
				for (auto i = (*this->grammar)[word]->rbegin(); i != (*this->grammar)[word]->rend(); ++i) {
					this->append_grammar->emit(_(i->c_str()));
				}
			}
		}

		word = "<span background='#" + this->mark_color + "'>" + word;
		word += "</span>";

		int pbegin = begin;
		bool is_pango = this->verse_content[0] == '<';

		for (int i = 0; i < pbegin || is_pango; ++i) {
			if (is_pango) {
				++pbegin;
			}

			if (this->verse_content[i + 1] == '<') {
				is_pango = true;
			} else if (this->verse_content[i] == '>') {
				is_pango = false;
			}
		}

		Glib::ustring mark = this->verse_content.substr(0, pbegin) + word + this->verse_content.substr(pbegin + end - begin, std::string::npos);
		this->verse.set_markup(mark);

	}

	return false;
}

bool Libre::TextViewVerse::is_non_word(const char & c) {
	std::vector<char> non_word = {' ', ',', '.', '(', ')', ';', '?', '!'};
	for (const char & nc : non_word) {
		if (nc == c)
			return true;
	}
	return false;
}

void Libre::TextViewVerse::clear() {
	this->verse.set_text("");
	this->caption.set_text("");
}

void Libre::TextViewVerse::show_if_not_empty() {
	if (this->caption.get_text().empty()) {
		this->button.hide();
		this->caption.hide();
		this->verse.hide();
		this->hide();
	} else {
		this->button.set_active(this->note_exists->emit(this->caption.get_text()));
		this->button.show();
		this->caption.show();
		this->verse.show();
		this->show_all();
	}
}

std::string Libre::TextViewVerse::get_mark_color() {
	Gdk::RGBA rgba;
	this->get_style_context()->lookup_color("theme_mark_color", rgba);

	std::string r, g, b;

	std::stringstream stream;
	stream << std::hex << static_cast<int>(rgba.get_red() * 255);
	r = stream.str();
	if (r.length() < 2) { r = "0" + r; }
	stream.str("");

	stream << std::hex << static_cast<int>(rgba.get_green() * 255);
	g += stream.str();
	if (g.length() < 2) { g = "0" + g; }
	stream.str("");

	stream << std::hex << static_cast<int>(rgba.get_blue() * 255);
	b += stream.str();
	if (b.length() < 2) { b = "0" + b; }

	return r + g + b;
}
