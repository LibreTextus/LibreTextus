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
			PreferencesElement(const std::string & text) : Gtk::HBox(), label(text, Gtk::ALIGN_START, Gtk::ALIGN_CENTER) {
				this->element.set_size_request(350, -1),
				this->pack_start(this->label, Gtk::PACK_SHRINK);
				this->pack_end(this->element, Gtk::PACK_SHRINK);
				this->set_homogeneous(false);
				this->set_name("preferences_element");
			}

			Gtk::Label * get_label() {
				return &this->label;
			}

			T * get_element() {
				return &this->element;
			}
	};
}

#endif
