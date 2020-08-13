#include "package_manager.hpp"

void Libre::PackageManager::connect_dispatcher_signal(Gtk::Label * header, Gtk::Label * info) {
	this->update_text.connect([this, header, info]() {
		this->mtx.lock();
		header->set_text(this->header_string);
		info->set_text(this->info_string);
		this->mtx.unlock();
	});
}
