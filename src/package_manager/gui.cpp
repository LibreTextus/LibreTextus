#include "package_manager.hpp"

void Libre::PackageManager::show_message(const std::string & h, const std::string & info) {
	this->mtx.lock();
	this->header_string = h;
	this->info_string = info;
	this->mtx.unlock();
	this->update_text.emit();
}
