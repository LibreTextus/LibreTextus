#ifndef SHORTCUT_BUTTON
#define SHORTCUT_BUTTON

#include <gtkmm.h>
#include <iostream>
#include <future>

#include <settings/settings.hpp>

namespace Libre {
	class ShortcutButton : public Gtk::Button {
		private:
			std::string settings_name;
			void on_clicked();
			void entry_changed();
			Gtk::Popover popover;
			Gtk::Entry entry;
			Settings settings;
			sigc::signal<void> m_refresh_short_cuts;
		public:
			ShortcutButton();
			~ShortcutButton() = default;
			void set_shortcut(const std::string &);
			sigc::signal<void> refresh_shortcuts();
	};
}

#endif
