#ifndef LIBRE_ABOUT_WINDOW_HPP
#define LIBRE_ABOUT_WINDOW_HPP

#include <gtkmm.h>
#include <path/path.hpp>

namespace Libre {
	class AboutWindow : public Gtk::Window {
		private:
			Gtk::VBox box;
			Gtk::Label info;
			Gtk::Image logo;

		public:
			AboutWindow();
			~AboutWindow() = default;
	};
}

#endif
