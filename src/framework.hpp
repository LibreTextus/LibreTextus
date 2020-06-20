#ifndef FRAMEWORK_HPP
#define FRAMEWORK_HPP

#include <gtkmm.h>
#include <iostream>
#include <experimental/filesystem>
#include <glibmm/i18n.h>
#include <locale.h>
#include <string>

#include "signal_handler.hpp"
#include "widgets.hpp"
#include "settings.hpp"
#include "window.hpp"
#include "path.hpp"
#include "log.hpp"
#include "source_handler.hpp"

class Framework {
private:
	SignalHandler signal_handler;
	Libre::Widgets widgets;

public:
	Framework() {}
	virtual ~Framework() {}

	int init(const std::string &) ;
	bool run();
};

#endif
