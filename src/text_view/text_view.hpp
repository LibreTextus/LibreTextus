#ifndef LIBRE_TEXT_VIEW
#define LIBRE_TEXT_VIEW

#include <gtkmm.h>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <rapidxml/rapidxml.hpp>
#include <rapidxml/rapidxml_utils.hpp>
#include <rapidxml/rapidxml_print.hpp>
#include <glibmm/i18n.h>

#include <source_handler/source_handler.hpp>

#include "tab/tab.hpp"

#define VERSES_SHOWN 30

namespace Libre {
	class TextView : public Gtk::ScrolledWindow {
	private:
		Gtk::HBox main;
		Gtk::Overlay overlay;
		Gtk::Label information_text;
		Gtk::Label no_result_label;
		std::vector<Libre::TextViewTab<VERSES_SHOWN> *> tabs;
		bool has_results;
		float scroll_sensitivity;
		rapidxml::xml_node<> * note_book_file;
		sigc::signal<void, std::string> m_signal_toggle_note;
		sigc::signal<void, std::string> m_signal_right_click_search;
		sigc::signal<void, std::string> m_signal_append_grammar;
		sigc::signal<void> m_signal_clear_grammar;
		bool note_exists(const std::string &);
		void show_other_strongs(const size_t &, const size_t &, const std::string &);

	public:
		TextView(const std::string &);
		virtual ~TextView() = default;

		void clear();
		void add_verse(const std::string & caption, const std::vector<std::string *> & verses_content);
		void replace_verse(const std::string & caption, const int & version, const std::string * content);
		void display(const int & i);
		void display_all();
		bool on_scroll_event(GdkEventScroll * scroll_event);
		bool on_key_press_event(GdkEventKey * key);
		void show_information();
		void show_content();
		void show_if_results();
		void remove_tab(const int & id);
		void append_tab(const std::string & path);
		void label_populate_popup(Gtk::Menu * menu, int tab, int version);
		void set_info_text(const std::string &);
		void scroll_to(const size_t &);
		void set_note_book(rapidxml::xml_node<> * root) {
			this->note_book_file = root;
		}

		sigc::signal<void, std::string> signal_toggle_note();
		sigc::signal<void, std::string> signal_right_click_search();
		sigc::signal<void, std::string> signal_append_grammar();
		sigc::signal<void> signal_clear_grammar();


		bool on_button_release_event(GdkEventButton * button_event) {
				this->grab_focus();
				return false;
		}

		void change_source(const int & id, const std::string & path);
		void refresh_theme();

	};
}

#endif
