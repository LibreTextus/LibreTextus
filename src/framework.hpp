#ifndef FRAMEWORK_HPP
#define FRAMEWORK_HPP

#include <gtkmm.h>
#include <iostream>

#include "signal_handler.hpp"
#include "widgets.hpp"

class Framework {
private:
	SignalHandler signal_handler;
	LibreWidgets widgets;

public:
	Framework() {}
	virtual ~Framework() {}

	int init(int argc, char *argv[]) ;
	void run();
};

#endif
