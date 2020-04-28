#include <gtkmm.h>
#include <X11/Xlib.h>
#include <iostream>
#include "framework.hpp"

int main(int argc, char *argv[]) {

	XInitThreads();

	Framework framework;
	framework.init(argc, argv);
	framework.run();

	return 0;
}
