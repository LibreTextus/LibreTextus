#include <gtkmm.h>
#include <X11/Xlib.h>
#include "framework.hpp"
#include "path.hpp"

int main(int argc, char *argv[]) {

	XInitThreads();

	bool restart = false;

	do {
		Framework framework;
		framework.init(argc, argv);
		restart = framework.run();
	} while(restart);

	return 0;
}
