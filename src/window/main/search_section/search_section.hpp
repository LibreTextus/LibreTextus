#ifndef MAIN_WINDOW_SEARCH_SECTION_HPP
#define MAIN_WINDOW_SEARCH_SECTION_HPP

#include <gtkmm.h>
#include <glibmm/i18n.h>
#include <history_button/history_button.hpp>

namespace Libre {
	class SearchSection : public Gtk::HBox {
		private:
			Libre::HistoryButton history_button;
			Gtk::SearchEntry search_entry;
			Gtk::Label number_results;
		public:
			SearchSection();
			~SearchSection() = default;

			Libre::HistoryButton * get_history_button();
			Gtk::SearchEntry * get_search_entry();
			Gtk::Label * get_number_result_label();
	};
}

#endif
