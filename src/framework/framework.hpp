#ifndef FRAMEWORK_HPP
#define FRAMEWORK_HPP

#include <gtkmm.h>
#include <iostream>
#include <experimental/filesystem>
#include <glibmm/i18n.h>
#include <locale.h>
#include <string>

#include <path/path.hpp>
#include <log/log.hpp>
#include <source_handler/source_handler.hpp>
#include <window/splash_screen/splash_screen.hpp>
#include <window/preferences/preferences.hpp>
#include <window/main/main.hpp>
#include <text_view/text_view.hpp>
#include <notebook/notebook.hpp>
#include <history_button/history_button.hpp>
#include <package_manager/package_manager.hpp>
#include <search_engine/search_engine.hpp>
#include <settings/settings.hpp>

class Framework {
private:
	std::string arg;

	Libre::PackageManager package_manager;

	Libre::Settings settings;
	std::vector<SearchEngine> search_engine;

	Glib::RefPtr<Gtk::Application> app;

	Libre::MainWindow * main_window;
	Libre::SplashScreen * splash_screen;
	Libre::PreferencesWindow * preferences_window;
	Libre::AboutWindow * about_window;

	Glib::Thread * update_thread;
	Glib::Dispatcher start_session;
	bool restart_application;

	void init_session();

	void create_home_directory_if_missing();
	void create_settings_file_if_missing();

	void init_locales();

	void connect_app_startup_signal();
	void connect_session_init_success_signal();

	void emit_startup_signal();
	void end_log_if_not_restarting();

	void restart();

public:
	Framework() {}
	~Framework() {
		delete this->main_window;
		delete this->preferences_window;
		delete this->splash_screen;
	}

	int init(std::string) ;
	bool run();
};

#endif
