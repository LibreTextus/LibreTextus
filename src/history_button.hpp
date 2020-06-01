#ifndef HISTORY_BUTTON
#define HISTORY_BUTTON value

#include <iostream>
#include <gtkmm.h>
#include <vector>
#include "path.hpp"

namespace Libre {
	class HistoryButton : public Gtk::HBox {
	private:
		Gtk::Button back_button;
		Gtk::Button forward_button;
		Gtk::Menu popup_menu;
		Gtk::RadioMenuItem first_item;
		std::vector<std::string> search_history;
		std::vector<Gtk::CheckMenuItem> check_buttons;
		int active_search;
		sigc::signal<void, std::string> m_trigger_search;

	public:
		HistoryButton();
		virtual ~HistoryButton() = default;

		bool right_click(GdkEventButton * event);
		void button_pressed(bool forward);

		void add_to_history(std::string arg);

		sigc::signal<void, std::string> trigger_search() {
			return this->m_trigger_search;
		}
	};
}

#endif
