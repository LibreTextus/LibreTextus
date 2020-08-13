#ifndef QUICK_SEARCH_HPP
#define QUICK_SEARCH_HPP

#include <fstream>
#include <stdexcept>
#include <string>
#include <iostream>
#include <experimental/filesystem>
#include <glibmm/i18n.h>
#include <vector>
#include <package_manager/package_manager.hpp>
#include <settings.hpp>
#include <source_handler.hpp>
#include <search_engine/search_engine.hpp>
#include <path/path.hpp>

namespace Libre {
	void quick_init(Libre::PackageManager & package_manager, Settings & settings) {
	
		if (!std::experimental::filesystem::exists(HOME())) {
			std::experimental::filesystem::create_directory(HOME());
		}

		if (!std::experimental::filesystem::exists(HOME("settings.xml"))) {
			std::experimental::filesystem::copy(DATA("settings.xml"), HOME("settings.xml"));
		}

		package_manager.init(true);

		if (settings.get_attribute("locale", "locale").empty()) {
			setlocale(LC_ALL, "");
			setenv("LANGUAGE", std::string(setlocale(LC_ALL, NULL)).substr(0, std::string(setlocale(LC_ALL, NULL)).find_last_of(".")).c_str(), 1);
		} else {
			setlocale(LC_ALL, (settings.get_attribute("locale", "locale") + ".utf8").c_str());
			setenv("LANGUAGE", settings.get_attribute("locale", "locale").c_str(), 1);
		}

		bindtextdomain(GETTEXT_PACKAGE, DATA("../locale").c_str());
		textdomain(GETTEXT_PACKAGE);


		if (settings.get_attribute("startupfile", "file").empty()) {
			settings.set("startupfile", "file", package_manager.get_sources().front());
		}
	}


	int quick_search(const std::string & arg, const std::string & file, const std::string & source, bool highlight, bool show_amount) {

		Libre::PackageManager package_manager;
		Settings settings;

		quick_init(package_manager, settings);

		SourceHandler source_handler;
		source_handler.set_names_path(HOME(settings.get_attribute("namesfile", "file")));
		
		SearchEngine search_engine(package_manager.get_source_path(settings.get_attribute("startupfile", "file")));

		if (!package_manager.get_source_path(source).empty()) {
			search_engine.set_source(package_manager.get_source_path(source));
		} else if (!source.empty()) {
			std::cerr << "Could not find source: " + source << '\n';
			return -1;
		}

		std::string result("");

		search_engine.set_search_argument(arg);
		search_engine.set_mark_argument((highlight ? (file.empty() ? "\033[1;31m$&\033[0m" : "*$&*") : "$&"));

		std::ofstream ifile;
		if (!file.empty()) {
			ifile.open(file);
		}

		int amount = 0;

		while (search_engine.search(&result)) {
			if (file.empty()) {
				std::cout << search_engine.get_last_search_results()->back() << '\n';
				std::cout << result << '\n';
				std::cout << '\n';
			} else {
				ifile << search_engine.get_last_search_results()->back().c_str() << '\n';
				ifile << result.c_str() << '\n';
				ifile << '\n';
			}

			amount++;
		}

		if (show_amount) {
			if (file.empty()) {
				std::cout << "[ " << amount << " " << _("Results") <<  " ]\n\n";
			} else {
				ifile << "[ " << amount << " " << _("Results") <<  " ]\n\n";
			}
		}

		if (!file.empty()) {
			ifile.close();
		}

		return 0;
	}

	void list_sources() {
		Libre::PackageManager package_manager;
		Settings settings;

		quick_init(package_manager, settings);

		std::vector<std::string> * v = &package_manager.get_sources();

		for (std::vector<std::string>::iterator i = v->begin(); i != v->end(); i++) {
			std::cout << *i << (settings.get_attribute("startupfile", "file") == *i ? std::string(" (\033[1;31m") + _("default") + "\033[0m)" : "") << '\n';
		}
	}
}

#endif
