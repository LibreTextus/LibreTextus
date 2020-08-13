#include "signal_handler.hpp"

void SignalHandler::quit() {
	this->widgets->app->quit();
}

