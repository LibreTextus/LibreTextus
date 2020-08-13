#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include <gtkmm.h>
#include <vector>
#include <fstream>
#include <experimental/filesystem>
#include <glibmm/i18n.h>
#include "window/dialog.hpp"
#include "text_view.hpp"
#include "notebook.hpp"
#include "widgets.hpp"
#include "signal_handler.hpp"
#include "settings.hpp"
#include "path.hpp"
#include "log.hpp"

namespace Libre {
	namespace MainWindow {
		bool create(Libre::Widgets *, SignalHandler *);
	}
}

#endif
