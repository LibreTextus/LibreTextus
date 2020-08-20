#ifndef LIBRE_MENU_HPP
#define LIBRE_MENU_HPP 

#include <gtkmm.h>
#include <string>
#include <tsl/ordered_map.h>

#include "element/element.hpp"

namespace Libre {
	class Menu : public Gtk::MenuBar {
		private:
			tsl::ordered_map<std::string, Libre::MenuElement *> menu;

		public:
			Menu();
			~Menu() = default;

			void add_menu_item(const std::string &);
			void add_sub_menu_item(const std::string &, const std::string &, const std::string &, const sigc::slot<void> & slot);
			void add_sub_menu_item(const std::string &, const std::string &, const Gtk::AccelKey &, const sigc::slot<void> & slot);
			void add_seperator_to_submenu(const std::string &);
	};
}

#endif
