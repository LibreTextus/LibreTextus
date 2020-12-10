#include "about.hpp"
#include "gtkmm/enums.h"

Libre::AboutWindow::AboutWindow()
	:	logo(Gdk::Pixbuf::create_from_file(DATA("icon.svg"), 100, 100, true)),
		info("Version: " + std::string(VERSION) + ", " + std::string(GIT_COMMIT_ID)) {

		this->box.pack_start(this->logo, Gtk::PACK_SHRINK, 5);
		this->box.pack_start(this->info, Gtk::PACK_SHRINK, 5);
		this->add(this->box);

		this->set_title("About");
		this->set_border_width(20);
		this->set_keep_above(true);
		this->set_resizable(false);
		this->set_position(Gtk::WIN_POS_CENTER);
}
