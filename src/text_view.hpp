#ifndef LIBRE_TEXT_VIEW
#define LIBRE_TEXT_VIEW

#include <gtkmm.h>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <yaml-cpp/yaml.h>

namespace Libre {
	class TextView : public Gtk::ScrolledWindow {
	private:
		Gtk::VBox main;
		Gtk::Overlay overlay;
		Gtk::Label information_text;
		std::vector<Gtk::HBox *> verses;
		std::vector<std::string> captions;
		std::vector<std::vector<std::string *>> content;
		int scroll_status;
		int padding_x;
		int padding_y;
		int max_verses;
		YAML::Node note_book_file;
		typedef sigc::signal<void, std::string> type_signal_toggle_note;
		type_signal_toggle_note m_signal_toggle_note;

	public:
		TextView(const std::string & info_text);
		virtual ~TextView() = default;

		void clear();
		void add_verse(const std::string & caption, const std::vector<std::string *> & verses_content);
		void replace_verse(const std::string & caption, const int & version, const std::string * content);
		void _display();
		bool on_scroll_event(GdkEventScroll * scroll_event);
		void show_information();
		void show_content();
		void remove_tab(const int & id);
		void set_note_book(YAML::Node & n) {
			this->note_book_file = n;
		}

		type_signal_toggle_note signal_toggle_note() {
			return this->m_signal_toggle_note;
		}

	};
}

#endif
