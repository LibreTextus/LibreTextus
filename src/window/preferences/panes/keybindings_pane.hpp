#ifndef KEYBINDINGS_PANE_HPP
#define KEYBINDINGS_PANE_HPP

#include <gtkmm.h>

namespace Libre {
	class KeybindingsPane : public Gtk::VBox {
		public:
			KeybindingsPane() : Gtk::VBox() {};
	};
}

#endif
