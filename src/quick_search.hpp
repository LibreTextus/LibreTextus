#ifndef QUICK_SEARCH_HPP
#define QUICK_SEARCH_HPP

#include <string>
#include <iostream>
#include <experimental/filesystem>
#include "package_manager.hpp"
#include "settings.hpp"
#include "source_handler.hpp"
#include "search_engine.hpp"
#include "path.hpp"

namespace Libre {
	void quick_search(const std::string & arg) {

		if (!std::experimental::filesystem::exists(HOME("settings.xml"))) {
			std::experimental::filesystem::copy(DATA("settings.xml"), HOME("settings.xml"));
		}


		Libre::PackageManager package_manager;
		package_manager.init(true);
		
		Settings settings;

		if (settings.get_attribute("startupfile", "file").empty()) {
			settings.set("startupfile", "file", package_manager.get_sources().front());
		}


		SourceHandler source_handler;
		source_handler.set_names_path(HOME(settings.get_attribute("namesfile", "file")));

		SearchEngine search_engine(package_manager.get_source_path(settings.get_attribute("startupfile", "file")));

		std::string result("");

		search_engine.set_search_argument(arg);

		while (search_engine.search(&result)) {
			std::cout << search_engine.get_last_search_results()->back() << '\n';
			std::cout << result << '\n';
			std::cout << '\n';
		}
	}
}

#endif
