#ifndef USER_INTERFACE_PANE_HPP
#define USER_INTERFACE_PANE_HPP

#include <gtkmm.h>
#include <glibmm/i18n.h>
#include "elements/default.hpp"

namespace Libre {
	class UserInterfacePane : public Gtk::VBox {
		private:
			Libre::PreferencesElement<Gtk::ComboBoxText> theme;
			Libre::PreferencesElement<Gtk::ComboBoxText> locale;
			Libre::PreferencesElement<Gtk::SpinButton> font_size;

		public:
			UserInterfacePane();
			~UserInterfacePane() = default;

			Libre::PreferencesElement<Gtk::ComboBoxText> * get_theme();
			Libre::PreferencesElement<Gtk::ComboBoxText> * get_locale();
			Libre::PreferencesElement<Gtk::SpinButton> * get_font_size();
	};
}

#endif
