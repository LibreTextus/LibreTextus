#ifndef SIGNAL_HANDLER_HPP
#define SIGNAL_HANDLER_HPP

#include <gtkmm.h>
#include <iostream>

class SignalHandler {
public:
	SignalHandler();

	virtual ~SignalHandler();

	static void search_input() {
		std::cout << "-- SEARCH FUNCTION --" << '\n';
	}
};

#endif
