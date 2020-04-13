#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include <gtkmm.h>
#include <vector>
#include <yaml-cpp/yaml.h>
#include "widgets.hpp"
#include "signal_handler.hpp"
#include "settings.hpp"

namespace Libre {
	namespace MainWindow {
		bool create(Libre::Widgets * w, SignalHandler * s);
	}

	namespace PreferencesWindow {
		bool create(Libre::Widgets * w, SignalHandler * s);
	}
}

#endif
