#include "rapid_textus.hpp"

int Libre::RapidTextus::rapid_search(const std::string & arg, const std::string & file, const std::string & source, bool highlight, bool show_amount) {

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
