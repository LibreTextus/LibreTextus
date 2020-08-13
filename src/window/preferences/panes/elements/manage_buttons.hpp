#ifndef MANAGE_BUTTONS_HPP
#define MANAGE_BUTTONS_HPP

#include <gtkmm.h>

namespace Libre {
	namespace BookManagerElements {
	class ManageButtons : public Gtk::HBox {
		private:
			Gtk::Button add;
			Gtk::Button remove;

		public:
			ManageButtons();
			virtual ~ManageButtons() = default;

			Gtk::Button * get_add(); 
			Gtk::Button * get_remove();
	};
	}
}

#endif
