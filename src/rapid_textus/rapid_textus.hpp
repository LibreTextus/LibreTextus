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
	class RapidTextus {
		private:
			void create_settings_file_and_home_if_missing();
			void init_locales();
			void set_startup_file_if_not_already();
		public:
		Libre::PackageManager package_manager;
		Settings settings;

		RapidTextus();

		int rapid_search(const std::string & arg, const std::string & file, const std::string & source, bool highlight, bool show_amount);

		void list_sources();
	};
}

#endif
