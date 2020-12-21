#include "verse.hpp"
#include <iostream>

Libre::TextViewVerse::TextViewVerse() : Gtk::VBox() {
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


		if (this->grammar != nullptr) {
			if ((*this->grammar)[selection] != nullptr) {

				Gtk::Menu * grammar_submenu = new Gtk::Menu;
				Gtk::MenuItem * grammar_section = new Gtk::MenuItem(_("Grammar"));
				grammar_section->set_submenu(*grammar_submenu);

				menu->prepend(*(new Gtk::SeparatorMenuItem));

				for (auto i = (*this->grammar)[selection]->rbegin(); i != (*this->grammar)[selection]->rend(); ++i) {
					Gtk::MenuItem * grammar_item = new Gtk::MenuItem(_(i->c_str()));
					grammar_item->set_sensitive(false);

					grammar_submenu->prepend(*grammar_item);
				}

				menu->prepend(*grammar_section);
			} 
		}

		
		search_item->signal_button_release_event().connect([this, selection](GdkEventButton *) {
				this->trigger_search->emit(selection);
				return false;
		});

	}
	menu->show_all();
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
