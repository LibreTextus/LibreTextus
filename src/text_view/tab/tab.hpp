#ifndef LIBRE_TEXT_VIEW_TAB_HPP
#define LIBRE_TEXT_VIEW_TAB_HPP

#include <gtkmm.h>
#include <string>
#include <source_handler/source_handler.hpp>
#include <array>
#include <algorithm>
#include <tsl/ordered_map.h>

#include "verse/verse.hpp"

namespace Libre {
	template <int N>
	class TextViewTab : public Gtk::VBox {
		private:
			std::string source_path;
			SourceHandler source_handler;
			std::array<Libre::TextViewVerse *, N> text_view_verses;
			tsl::ordered_map<std::string, std::string> verse;
			Libre::StrongMap * strong_map;
			sigc::signal<bool, const std::string &> note_exists;
			static int scroll;
		public:
			TextViewTab(const std::string &, sigc::signal<void, std::string> *, sigc::signal<void, std::string> *, sigc::signal<bool, const std::string &>);
			std::array<Libre::TextViewVerse *, N> * get_verses();
			void clear();
			void add_verse(const std::string &, const std::string &);
			void display(const int & i = 0);
			void display_all();
			void scroll_steps(const int &);
			void reset_scroll();
			void change_verse(const std::string &, const std::string &);
			std::string get_active_verse_position();
			void set_source_path(const std::string &);
			size_t get_verses_amount() { return this->verse.size(); }
	};
}

template <int N>
int Libre::TextViewTab<N>::scroll = 0;

template <int N>
Libre::TextViewTab<N>::TextViewTab(const std::string & path, sigc::signal<void, std::string> * trigger_search, sigc::signal<void, std::string> * toggle_note, sigc::signal<bool, const std::string &> s) : 
	Gtk::VBox(false), source_path(path) {
		this->set_name("text_view");
		this->note_exists = s;

		for (Libre::TextViewVerse *& i : this->text_view_verses) {
			i = new Libre::TextViewVerse;
			i->set_toggle_note(toggle_note);
			i->set_trigger_search(trigger_search);
			i->set_note_exits(&this->note_exists);
			this->pack_start(*i, Gtk::PACK_SHRINK, 0);
		}

		this->text_view_verses[0]->set_name("active_verse");
}

template <int N>
void Libre::TextViewTab<N>::clear() {
	this->verse.clear();
	for (Libre::TextViewVerse * i : this->text_view_verses) {
		i->clear();
	}
}

template <int N>
void Libre::TextViewTab<N>::display(const int & i) {
	if (i - this->scroll < N && i - this->scroll >= 0) {
		this->text_view_verses[i - this->scroll]->clear();
		if (i < this->verse.size()) {
			tsl::ordered_map<std::string, std::string>::iterator i_v = this->verse.begin();
			i_v += i;


			if (this->strong_map->find(i_v->first) != this->strong_map->end()) {
				this->text_view_verses[i - this->scroll]->set_strongs(&(*this->strong_map)[i_v->first]);
			} else {
				this->text_view_verses[i - this->scroll]->set_strongs(nullptr);
			}

			this->text_view_verses[i - this->scroll]->set_caption(i_v->first);
			this->text_view_verses[i - this->scroll]->set_verse(i_v.value());
			this->text_view_verses[i - this->scroll]->show_if_not_empty();
		} else {
			this->text_view_verses[i - this->scroll]->clear();
			this->text_view_verses[i - this->scroll]->show_if_not_empty();
		}
	}
}

template <int N>
void Libre::TextViewTab<N>::display_all() {
	for (int i = this->scroll; i < N + this->scroll; ++i) {
		this->display(i);
	}
}

template <int N>
void Libre::TextViewTab<N>::add_verse(const std::string & caption, const std::string & verse) {
	this->verse[caption] = verse;
	this->display(this->verse.size() - 1);
}

template <int N>
std::array<Libre::TextViewVerse *, N> * Libre::TextViewTab<N>::get_verses() {
	return &this->text_view_verses;
}

template <int N>
void Libre::TextViewTab<N>::scroll_steps(const int & i) {
	this->scroll += i;
	
	if (this->scroll < 0)
		this->scroll = 0;
	else if (this->scroll > this->verse.size() - 1)
		this->scroll = this->verse.size() - 1;
}

template <int N>
void Libre::TextViewTab<N>::reset_scroll() {
	this->scroll = 0;
}

template <int N>
void Libre::TextViewTab<N>::change_verse(const std::string & caption, const std::string & verse) {
	this->verse[caption] = verse;
	int i = std::distance(this->verse.begin(), this->verse.find(caption));
	this->display(i);
}

template <int N>
std::string Libre::TextViewTab<N>::get_active_verse_position() {
	return this->text_view_verses.front()->get_caption_label()->get_text();
}

template <int N>
void Libre::TextViewTab<N>::set_source_path(const std::string & path) {
	this->source_path = path;
	this->strong_map = this->source_handler.get_strongs(path);
}

#endif
