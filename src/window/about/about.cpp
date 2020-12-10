#include "about.hpp"
#include "gtkmm/enums.h"

Libre::AboutWindow::AboutWindow()
	: info("Version: " + std::string(VERSION) + ", " + std::string(GIT_COMMIT_ID)) {
		this->box.pack_start(this->info);
		this->add(this->box);

		this->set_title("About");
		this->set_default_size(300, 100);
		this->set_keep_above(true);
		this->set_resizable(false);
		this->set_position(Gtk::WIN_POS_CENTER);
}
