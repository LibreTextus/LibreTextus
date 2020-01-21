#include <gtkmm.h>
#include <iostream>

#include "window.hpp"

int main(int argc, char *argv[]) {

	Framework framework;

	framework.init(argc, argv, "data/main_window.glade");

	framework.run();

	return 0;
}
