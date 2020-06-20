#include <gtkmm.h>
#include <X11/Xlib.h>
#include <iostream>
#include <string>
#include <boost/program_options.hpp>
#include "framework.hpp"
#include "path.hpp"
#include "quick_search.hpp"

int main(int argc, char *argv[]) {
	try {
		boost::program_options::options_description desc("usage");
		desc.add_options()
			("help", "Show this help screen")
			("search,s", boost::program_options::value<std::string>()->default_value(""), "Search for the following argument")
			("print,p", "Print results without open a window");

		boost::program_options::variables_map vm;
		boost::program_options::store(boost::program_options::parse_command_line(argc, argv, desc), vm);

		if (vm.count("help")) {
			std::cout << desc << '\n';
		} else if (vm.count("print")) {
			Libre::quick_search(vm["search"].as<std::string>());
		} else {
			XInitThreads();

			bool restart = false;

			do {
				Framework framework;
				framework.init(vm["search"].as<std::string>());
				restart = framework.run();
			} while(restart);
		}
	} catch (const boost::program_options::error &ex) {
		std::cerr << ex.what() << '\n';
	}

	return 0;
}
