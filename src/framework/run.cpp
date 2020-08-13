#include "framework.hpp"
bool Framework::run() {
	LOG("-- Run Application");
	this->emit_startup_signal();
	this->end_log_if_not_restarting();

	return this->widgets.processing.restart_application;
}

void Framework::emit_startup_signal() {
	try {
		this->widgets.app->run();
	} catch (std::exception & ex) {
		std::cerr << "Error cannot run Application: " << ex.what() << '\n';
	}
}

void Framework::end_log_if_not_restarting() {
	if (!this->widgets.processing.restart_application) {
		LOG("--------------------- LOG END ---------------------");
	}
}
