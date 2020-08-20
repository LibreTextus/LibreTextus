#ifndef MAIN_WINDOW_HEADER_HPP
#define MAIN_WINDOW_HEADER_HPP

#include <gtkmm.h>
#include <vector>

#include "element/element.hpp"

namespace Libre {
	class Header : public Gtk::HBox {
		private:
			std::vector<std::string> combo_content;
			std::vector<Libre::HeaderElement *> elements;
			Gtk::Button add;
		public:
			Header();
			~Header() = default;

			void remove_element(const int & i);
			void append();
			void refresh();

			std::vector<Libre::HeaderElement *> * get_elements();
			std::vector<std::string> * get_combo_content();
			Gtk::Button * get_add();
				
	};
}

#endif
