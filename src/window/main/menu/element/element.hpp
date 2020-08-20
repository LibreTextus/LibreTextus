#ifndef MAIN_WINDOW_MENU_ELEMENT
#define MAIN_WINDOW_MENU_ELEMENT

#include <gtkmm.h>
#include <string>

namespace Libre {
	class SubMenuElement : public Gtk::MenuItem {
		public:
			SubMenuElement(const std::string & label, const Gtk::AccelKey & key, const sigc::slot<void> & slot) : Gtk::MenuItem() {
				if (slot) {
					this->signal_activate().connect(slot);
				}

				this->set_accel_key(key);
				this->set_label(label);
				this->set_use_underline(true);
			}

			~SubMenuElement() = default;
	};

	class MenuElement : public Gtk::MenuItem {
		private:
			Gtk::Menu submenu;
		public:
			MenuElement(const std::string & label) : Gtk::MenuItem() {
				this->set_label(label);
				this->set_submenu(this->submenu);
			}


			~MenuElement() = default;
	};
}

#endif
