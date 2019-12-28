#include <gtkmm.h>
#include <iostream>

#include "window.hpp"

int main (int argc, char *argv[]) {

	GuiHandler gui;

	gui.init(argc, argv);

	gui.run();

	return 0;
}
