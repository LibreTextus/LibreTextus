#include <gtkmm.h>
#include <X11/Xlib.h>
#include <glibmm/i18n.h>
#include <locale.h>
#include "framework.hpp"
#include "path.hpp"

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "");
	bindtextdomain(GETTEXT_PACKAGE, DATA("../locale").c_str());
	textdomain(GETTEXT_PACKAGE);

	XInitThreads();

	Framework framework;
	framework.init(argc, argv);
	framework.run();

	return 0;
}
