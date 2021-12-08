#include "package_manager.hpp"

void Libre::PackageManager::update() {

	this->show_message(_("Update Packages"), "");

	for (int i = 0; i < this->packages.size(); i++) {
		system(("git -C " + HOME(this->packages[i]) + " pull").c_str());

		this->show_message(
				_("Update Packages"),
				std::string(_("Updating")) + " " + this->packages[i]
		);

		this->refresh_db(this->packages[i]);
	}

	this->refresh_lists();
}
