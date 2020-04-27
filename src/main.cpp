#include <gtkmm.h>
#include <X11/Xlib.h>
#include <iostream>
#include <experimental/filesystem>

#include "framework.hpp"

int main(int argc, char *argv[]) {

	if (getenv("SNAP")) {
		std::experimental::filesystem::current_path(getenv("SNAP"));
	}

	XInitThreads();

	Framework framework;
	framework.init(argc, argv);
	framework.run();

	return 0;
}
