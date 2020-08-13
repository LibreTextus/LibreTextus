#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include <gtkmm.h>
#include <vector>
#include <fstream>
#include <experimental/filesystem>
#include <glibmm/i18n.h>

#include "dialog/dialog.hpp"
#include <text_view.hpp>
#include <notebook/notebook.hpp>
#include <widgets.hpp>
#include <signal_handler/signal_handler.hpp>
#include <settings/settings.hpp>
#include <path/path.hpp>
#include <log/log.hpp>

namespace Libre {
	namespace MainWindow {
		bool create(Libre::Widgets *, SignalHandler *);
	}
}

#endif
