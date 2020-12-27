#ifndef KEYBINDINGS_PANE_HPP
#define KEYBINDINGS_PANE_HPP

#include <gtkmm.h>
#include "elements/default.hpp"
#include "elements/shortcut_button.hpp"

namespace Libre {
	class KeybindingsPane : public Gtk::VBox {
		private:
			Libre::PreferencesElement<Libre::ShortcutButton> down_scrolling;
			Libre::PreferencesElement<Libre::ShortcutButton> up_scrolling;
			Libre::PreferencesElement<Libre::ShortcutButton> go_bottom;
			Libre::PreferencesElement<Libre::ShortcutButton> go_top;
			sigc::signal<void> m_refresh_shortcuts;
		public:
			KeybindingsPane();
			~KeybindingsPane() = default;

			Libre::PreferencesElement<Libre::ShortcutButton> * get_down();
			Libre::PreferencesElement<Libre::ShortcutButton> * get_up();
			Libre::PreferencesElement<Libre::ShortcutButton> * get_bottom();
			Libre::PreferencesElement<Libre::ShortcutButton> * get_top();
	};
}

#endif
