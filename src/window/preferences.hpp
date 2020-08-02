#ifndef PREFERENCES_WINDOW_HPP
#define PREFERENCES_WINDOW_HPP

#include <gtkmm.h>
#include "preferences/panes/user_inferface_pane.hpp"
#include "preferences/panes/keybindings_pane.hpp"
#include "preferences/panes/book_manager_pane.hpp"

namespace Libre {

	class PreferencesWindow : public Gtk::Window {
		protected:
			Gtk::Notebook note_book;
			Libre::UserInterfacePane ui_pane;
			Libre::KeybindingsPane keybindings_pane;
			Libre::BookManagerPane book_manager_pane;
		public:
			PreferencesWindow() : Gtk::Window() {}
			virtual ~PreferencesWindow() = default;

	};
}

#endif
