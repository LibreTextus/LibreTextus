#ifndef BOOK_MANAGER_PANE_HPP
#define BOOK_MANAGER_PANE_HPP

#include <gtkmm.h>
#include <glibmm/i18n.h>
#include "elements/default.hpp"
#include "elements/book_view.hpp"
#include "gtkmm/box.h"

namespace Libre {
	class BookManagerPane : public Gtk::VBox {
		private:
			Libre::PreferencesElement<Gtk::ComboBoxText> default_source;
			Libre::BookManagerElements::BookList book_list;
			Libre::BookManagerElements::ManageButtons manage_buttons;

		public:
			BookManagerPane() : Gtk::VBox(), default_source(_("Default")) {
				this->pack_start(this->default_source, Gtk::PACK_SHRINK, 0);
				this->pack_start(this->book_list, Gtk::PACK_SHRINK, 0);
				this->pack_start(this->manage_buttons, Gtk::PACK_SHRINK, 0);
			}

			virtual ~BookManagerPane() = default;

			Libre::PreferencesElement<Gtk::ComboBoxText> * get_default_source() { return &this->default_source; }
			Libre::BookManagerElements::BookList * get_book_list() { return &this->book_list; }
			Libre::BookManagerElements::ManageButtons * get_manage_butons() { return &this->manage_buttons; }
	};
}

#endif
