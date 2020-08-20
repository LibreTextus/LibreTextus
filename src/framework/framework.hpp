#ifndef FRAMEWORK_HPP
#define FRAMEWORK_HPP

#include <gtkmm.h>
#include <iostream>
#include <experimental/filesystem>
#include <glibmm/i18n.h>
#include <locale.h>
#include <string>

#include <widgets.hpp>
#include <settings/settings.hpp>
#include <path/path.hpp>
#include <log/log.hpp>
#include <source_handler/source_handler.hpp>

class Framework {
private:
	std::string arg;
	Libre::Widgets widgets;

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
	virtual ~Framework() {}

	int init(std::string) ;
	bool run();
};

#endif
