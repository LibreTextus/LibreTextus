#ifndef HISTORY_BUTTON
#define HISTORY_BUTTON value

#include <iostream>
#include <gtkmm.h>
#include <vector>
#include "path.hpp"

namespace Libre {
	class HistoryButton : public Gtk::HBox {
	private:
		Gtk::Button history_button;
		Gtk::Menu popup_menu;
		Gtk::RadioMenuItem first_item;
		std::vector<std::string> search_history;
		std::vector<Gtk::CheckMenuItem> check_buttons;
		int active_search;
		int display_begin;
		int display_end;
		sigc::signal<void, std::string> m_trigger_search;

		void remove_words_after_active_search();
		void get_display_range();
		void add_history_to_popup();
		void add_new_history_popup_button(const int &);
		void last_check_button_connect_button_signal(const int &);

	public:
		HistoryButton();
		virtual ~HistoryButton() = default;

		void right_click();
		void button_pressed(bool forward);

		void add_to_history(std::string arg);

		sigc::signal<void, std::string> trigger_search() {
			return this->m_trigger_search;
		}
	};
}

#endif
