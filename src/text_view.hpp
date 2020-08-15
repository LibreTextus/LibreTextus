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

namespace Libre {
	class TextView : public Gtk::ScrolledWindow {
	private:
		Gtk::HBox main;
		Gtk::Overlay overlay;
		Gtk::Label information_text;
		Gtk::Label no_result_label;
		std::vector<Gtk::VBox> verses;
		std::vector<std::vector<Gtk::Label>> v_labels;
		std::vector<std::vector<Gtk::Label>> c_labels;
		std::vector<std::vector<Gtk::CheckButton>> verse_status;
		std::vector<std::string> captions;
		std::vector<std::string> source_paths;
		std::vector<std::vector<std::string>> content;
		int scroll_status;
		int padding_x;
		int padding_y;
		int max_verses;
		int tabs;
		float scroll_sensitivity;
		rapidxml::xml_node<> * note_book_file;
		sigc::signal<void, std::string> m_signal_toggle_note;
		sigc::signal<void, std::string> m_signal_right_click_search;

		bool note_exists(const std::string & pos) {
			for (rapidxml::xml_node<> * note = this->note_book_file->first_node("note"); note; note = note->next_sibling()) {
				if (note->first_attribute("name")->value() == pos) {
					return true;
				}
			}

			return false;
		}

	public:
		TextView(const std::string &, const std::string &);
		virtual ~TextView() = default;

		void clear();
		void add_verse(const std::string & caption, const std::vector<std::string *> & verses_content);
		void replace_verse(const std::string & caption, const int & version, const std::string * content);
		void _display(int begin);
		bool on_scroll_event(GdkEventScroll * scroll_event);
		bool on_key_press_event(GdkEventKey * key);
		void show_information();
		void show_content();
		void show_if_results();
		void remove_tab(const int & id);
		void append_tab(const std::string & path);
		void label_populate_popup(Gtk::Menu * menu, int tab, int version);
		void set_note_book(rapidxml::xml_node<> * root) {
			this->note_book_file = root;
		}

		sigc::signal<void, std::string> signal_toggle_note() {
			return this->m_signal_toggle_note;
		}

		sigc::signal<void, std::string> signal_right_click_search() {
			return this->m_signal_right_click_search;
		}

		bool on_button_release_event(GdkEventButton * button_event) {
				this->grab_focus();
				return false;
		}

		void change_source(const int & id, const std::string & path) {
			this->source_paths[id] = path;
		}

	};
}

#endif
