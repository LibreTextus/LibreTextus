#include <gtkmm.h>
#include <X11/Xlib.h>
#include <glibmm/i18n.h>
#include <locale.h>
#include "framework.hpp"

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "");
	bindtextdomain(GETTEXT_PACKAGE, LIBRETEXTUS_LOCALEDIR);
	textdomain(GETTEXT_PACKAGE);

	XInitThreads();

	Framework framework;
	framework.init(argc, argv);
	framework.run();

	return 0;
}
