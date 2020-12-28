#ifndef KEYBINDINGS_PANE_HPP
#define KEYBINDINGS_PANE_HPP

#include <gtkmm.h>
#include "elements/default.hpp"
#include "elements/shortcut_button.hpp"
#include "gtkmm/comboboxtext.h"

namespace Libre {
	class KeybindingsPane : public Gtk::VBox {
		private:
			Libre::PreferencesElement<Libre::ShortcutButton> down_scrolling;
			Libre::PreferencesElement<Libre::ShortcutButton> up_scrolling;
			Libre::PreferencesElement<Libre::ShortcutButton> go_bottom;
			Libre::PreferencesElement<Libre::ShortcutButton> go_top;
			Libre::PreferencesElement<Gtk::ComboBoxText> notebook_mode;
			sigc::signal<void> m_refresh_mode;
			Settings settings;
		public:
			KeybindingsPane();
			~KeybindingsPane() = default;

			Libre::PreferencesElement<Libre::ShortcutButton> * get_down();
			Libre::PreferencesElement<Libre::ShortcutButton> * get_up();
			Libre::PreferencesElement<Libre::ShortcutButton> * get_bottom();
			Libre::PreferencesElement<Libre::ShortcutButton> * get_top();

			sigc::signal<void> signal_refresh_mode() {
				return this->m_refresh_mode;
			}
	};
}

#endif
