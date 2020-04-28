#ifndef PACKAGE_MANAGER
#define PACKAGE_MANAGER

#include <string>
#include <stdlib.h>
#include <yaml-cpp/yaml.h>
#include <experimental/filesystem>
#include <regex>
#include <gtkmm.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <iostream>
#include "settings.hpp"
#include "path.hpp"

namespace Libre {
  class PackageManager {
  private:
    std::string root_path;
    Settings settings;
		YAML::Node sources;
		std::string dummy_path;

  public:

		Gtk::Window * window;
		Gtk::Label * main_info;
		Gtk::Label * subtitle;
		Gtk::Spinner * spinner;
		Glib::Dispatcher open_window;
		Glib::Dispatcher close_window;
		Glib::Dispatcher update_text;
		std::string info_string;
		std::string subtitle_string;

    PackageManager() = default;
    virtual ~PackageManager() = default;

    void init();
    void remove(std::string);
    void install(std::string);
    void disable(std::string);
    void enable(std::string);
		std::vector<std::string> get_packages();

		std::string get_root_path() {
			return this->root_path;
		}

		YAML::Node get_sources() {
			return this->sources;
		}

		std::string get_source_path(std::string name) {
			for (YAML::const_iterator i = this->sources.begin(); i != this->sources.end(); i++) {
				if (i->first.as<std::string>() == name) {
					return i->second["path"].as<std::string>();
				}
			}

			return this->dummy_path;
		}

		bool is_enabled(std::string name) {
			return (this->sources[name]["enabled"].as<std::string>() == "true");
		}
  };
}

#endif
