#include <gtkmm.h>
#include <iostream>

#include "framework.hpp"

int main(int argc, char *argv[]) {
	Framework framework;
	framework.init(argc, argv);
	framework.run();

	return 0;
}
