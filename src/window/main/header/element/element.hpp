#ifndef MAIN_WINDOW_HEADER_ELEMENT_HPP
#define MAIN_WINDOW_HEADER_ELEMENT_HPP

#include <gtkmm.h>
#include <vector>
#include <settings/settings.hpp>

namespace Libre {
	class HeaderElement : public Gtk::HBox {
		private:
			std::vector<std::string> combo_content;
			Gtk::ComboBoxText combo;
			Gtk::Button close;

			Settings settings;
		public:
			HeaderElement();
			~HeaderElement() = default;

			void refresh_combo();

			std::vector<std::string> * get_combo_content();
			Gtk::ComboBoxText * get_combo();
			Gtk::Button * get_close();
	};
}

#endif
