#ifndef USER_INTERFACE_PANE_HPP
#define USER_INTERFACE_PANE_HPP

#include <gtkmm.h>
#include <glibmm/i18n.h>
#include "elements/default.hpp"
#include "gtkmm/spinbutton.h"

namespace Libre {
	class UserInterfacePane : public Gtk::VBox {
		private:
			Libre::PreferencesElement<Gtk::ComboBoxText> theme;
			Libre::PreferencesElement<Gtk::ComboBoxText> locale;
			Libre::PreferencesElement<Gtk::SpinButton> font_size;

		public:
			UserInterfacePane() : Gtk::VBox(), theme(_("Theme")), locale(_("Language")), font_size(_("Font size")) {
				this->pack_start(this->theme, Gtk::PACK_SHRINK, 0);
				this->pack_start(this->locale, Gtk::PACK_SHRINK, 0);
				this->pack_start(this->font_size, Gtk::PACK_SHRINK, 0);
			}

			~UserInterfacePane() = default;

			Libre::PreferencesElement<Gtk::ComboBoxText> * get_theme() { return &this->theme; };
			Libre::PreferencesElement<Gtk::ComboBoxText> * get_locale() { return &this->locale; };
			Libre::PreferencesElement<Gtk::SpinButton> * get_font_size() { return &this->font_size; };
	};
}

#endif
