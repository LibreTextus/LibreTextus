#include "package_manager.hpp"

void Libre::PackageManager::install(std::string url) {

	std::string name;
	name = url.substr(url.find_last_of("/") + 1);

	this->mtx.lock();
	this->header_string = std::string(_("Install")) + " " + name;
	this->info_string = _("This could take a while...");
	this->mtx.unlock();
	this->update_text.emit();

	system(("git clone " + url + " " + HOME(name)).c_str());

	this->show_message(_("Looking for sources..."), "");

	this->refresh_db(name);

	this->show_message(_("Update sources list"), "");
	this->write_to_file();

	this->refresh_lists();
}

