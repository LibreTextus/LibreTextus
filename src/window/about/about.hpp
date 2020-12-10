#ifndef LIBRE_ABOUT_WINDOW_HPP
#define LIBRE_ABOUT_WINDOW_HPP

#include <gtkmm.h>

namespace Libre {
	class AboutWindow : public Gtk::Window {
		private:
			Gtk::HBox box;
			Gtk::Label info;

		public:
			AboutWindow();
			~AboutWindow() = default;
	};
}

#endif
