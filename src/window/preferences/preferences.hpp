#ifndef PREFERENCES_WINDOW_HPP
#define PREFERENCES_WINDOW_HPP

#include <gtkmm.h>
#include <iostream>
#include <experimental/filesystem>
#include <vector>
#include "panes.hpp"
#include <settings/settings.hpp>
#include <path/path.hpp>
#include <window/dialog/dialog.hpp>
#include <package_manager/package_manager.hpp>

namespace Libre {

	class PreferencesWindow : public Gtk::Window {
		protected:
			Gtk::Notebook note_book;
			Libre::UserInterfacePane ui_pane;
			Libre::KeybindingsPane keybindings_pane;
			Libre::BookManagerPane book_manager_pane;

			Glib::RefPtr<Gtk::CssProvider> theme_css_provider;
			Glib::RefPtr<Gtk::CssProvider> font_size_css_provider;
			Libre::Settings settings;

			sigc::signal<void> _restart_application;
			sigc::signal<void> _sync_all_source_combo_main_window;

			Glib::Dispatcher sync_sources_dispatcher;

			Libre::PackageManager * package_manager;
			
			void create_css_context();
			void add_themes_to_themes_combo();
			void add_locales_to_locales_combo();
			void set_font_size_adjustment();
			void add_sources_to_default_source_combo();

			void theme_changed();
			void locales_changed();
			void font_size_changed();
			void enable_changed(Gtk::CheckButton *);
			void sync_default_source_combo();
			void default_source_changed();
			void manage_buttons_add_pressed();
			void manage_buttons_remove_pressed();
			void sync_sources();

		public:
			PreferencesWindow();
			virtual ~PreferencesWindow() = default;

			void set_package_manager(Libre::PackageManager *);

			Gtk::Notebook * get_note_book();
			Libre::UserInterfacePane * get_ui_pane();
			Libre::KeybindingsPane * get_keybindings_pane();
			Libre::BookManagerPane * get_book_manager_pane();
			sigc::signal<void> restart_application();
			sigc::signal<void> sync_source_combo();
	};
}

#endif
