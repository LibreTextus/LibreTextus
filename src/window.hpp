#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include <gtkmm.h>
#include <vector>
#include <yaml-cpp/yaml.h>
#include "widgets.hpp"
#include "signal_handler.hpp"
#include "settings.hpp"

namespace Window {
	namespace Main {
		bool create(LibreWidgets * w, SignalHandler * s);
	}

	namespace Preferences {
		bool create(LibreWidgets * w, SignalHandler * s);
	}
}

#endif
