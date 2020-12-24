#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include <mutex>
#include <thread>
#include <atomic>
#include <vector>
#include <string>
#include <gtkmm.h>
#include <glibmm/i18n.h>
#include <package_manager/package_manager.hpp>
#include <search_engine/search_engine.hpp>
#include <window/dialog/dialog.hpp>
#include <window/preferences/preferences.hpp>
#include <window/about/about.hpp>
#include <settings/settings.hpp>
#include <log/log.hpp>

#include "menu/menu.hpp"
#include "header/header.hpp"
#include "search_section/search_section.hpp"
#include "view_pane/view_pane.hpp"
#include "window/main/header/element/element.hpp"
#include "window/preferences/preferences.hpp"

namespace Libre {
	class MainWindow : public Gtk::Window {
		private:
			bool is_fullscreen;
			int replace_id;
			std::thread * process_thread;
			std::mutex mutex;
			std::string found_position;
			std::vector<std::string *> found_verses;
			std::string mark_argument;
			std::string header_argument;
			std::atomic_bool process_finished;

			Glib::Dispatcher set_text_dispatcher;
			Glib::Dispatcher join_thread_dispatcher;
			Glib::Dispatcher sync_sources_dispatcher;

			std::vector<SearchEngine> search_engine;

			Gtk::VBox container;
			Libre::Menu menu;
			Libre::Header header;
			Libre::SearchSection search_section;
			Libre::ViewPane view_pane;

			Libre::PackageManager * package_manager;
			Libre::PreferencesWindow * preferences_window;
			Libre::AboutWindow * about_window;
			Libre::Settings settings;
			Glib::RefPtr<Gtk::Application> app;

			void create_menu_items();
			void connect_signals();

			void export_notes();
			void quit();
			void toggle_search();
			void toggle_preferences();
			void add_source();
			void remove_source();
			void remove_source_by_reference(Libre::HeaderElement *);
			int get_id(Libre::HeaderElement *);
			void zoom_in();
			void zoom_out();
			void zoom_reset();
			void toggle_iconify();
			void toggle_fullscreen();
			void source_changed(Libre::HeaderElement *);
			void set_replace_id(Libre::HeaderElement *);
			void do_replacement();
			void toggle_note(const std::string & position);
			void change_source_at_replace_id();
			void do_search();
			void trigger_search(const std::string &);
			gboolean search_request(GdkEventKey *);
			void add_source_dir();
			void remove_source_dir();
			void add_new_search_engine();
			void connect_signals_of_new_buttons();
			void set_text();
			void join_thread();
			std::string get_mark_color();
			void set_startup_file_if_empty();
			void show_about_window();

		public:
			MainWindow(const std::string &);
			~MainWindow() = default;

			void set_package_manager(Libre::PackageManager *);
			void set_application(Glib::RefPtr<Gtk::Application>);
			void set_preferences_window(Libre::PreferencesWindow *);
			void set_about_window(Libre::AboutWindow *);
			void sync_combo_boxes();
			void init();
			void trigger_search_with_history(const std::string &);
			void refresh_theme();

			Libre::Menu * get_menu();
			Libre::SearchSection * get_search_section();
			Libre::ViewPane * get_view_pane();
			Gtk::VBox * get_container();
			Glib::Dispatcher * get_sync_sources_dispatcher();
	};
}

#endif
