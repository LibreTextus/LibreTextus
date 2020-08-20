#ifndef WIDGETS_HPP
#define WIDGETS_HPP

#include <string>
#include <vector>
#include <gtkmm.h>
#include <iostream>
#include <mutex>
#include <tsl/ordered_map.h>

#include <window/splash_screen/splash_screen.hpp>
#include <window/preferences/preferences.hpp>
#include <window/main/main.hpp>
#include <text_view/text_view.hpp>
#include <notebook/notebook.hpp>
#include <history_button/history_button.hpp>
#include <package_manager/package_manager.hpp>
#include <search_engine/search_engine.hpp>
#include <settings/settings.hpp>

#include <window/main/menu/menu.hpp>

namespace Libre {
	struct Widgets {

		PackageManager package_manager;

		Libre::Settings settings;
		std::vector<SearchEngine> search_engine;

		Glib::RefPtr<Gtk::Application> app;

		Libre::MainWindow * main_window;
		Libre::SplashScreen * splash_screen;
		Libre::PreferencesWindow * preferences_window;

		struct Processing {
			Glib::Thread * update_thread;
			std::mutex process_mutex;
			Glib::Dispatcher delete_thread_dispatcher;
			Glib::Dispatcher start_session;
			bool restart_application;
		} processing;
		
		
		Widgets() = default;

		~Widgets() {
			delete this->main_window;
			delete this->preferences_window;
			delete this->splash_screen;
		}
	};
}

#endif
