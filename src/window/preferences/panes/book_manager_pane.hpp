#ifndef BOOK_MANAGER_PANE_HPP
#define BOOK_MANAGER_PANE_HPP

#include <gtkmm.h>
#include <glibmm/i18n.h>
#include "elements/default.hpp"
#include "elements/book_list.hpp"
#include "elements/manage_buttons.hpp"

namespace Libre {
	class BookManagerPane : public Gtk::VBox {
		private:
			Libre::PreferencesElement<Gtk::ComboBoxText> default_source;
			Libre::BookManagerElements::BookList book_list;
			Libre::BookManagerElements::ManageButtons manage_buttons;

		public:
			BookManagerPane();

			virtual ~BookManagerPane() = default;

			Libre::PreferencesElement<Gtk::ComboBoxText> * get_default_source();
			Libre::BookManagerElements::BookList * get_book_list();
			Libre::BookManagerElements::ManageButtons * get_manage_butons();
	};
}

#endif
