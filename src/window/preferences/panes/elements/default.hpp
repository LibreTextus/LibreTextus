#ifndef ELEMENT_HPP
#define ELEMENT_HPP

#include <gtkmm.h>
#include <string>

namespace Libre {
	template <typename T>
	class PreferencesElement : public Gtk::HBox {
		private:
			Gtk::Label label;
			T element;
		public:
			PreferencesElement(const std::string & text) : label(text) {
				this->pack_start(label);
				this->pack_end(element);
			}

			Gtk::Label * get_label() {
				return &this->label;
			}

			T get_element() {
				return &this->element;
			}
	};
}

#endif
