#ifndef SPLASH_SCREEN_HPP
#define SPLASH_SCREEN_HPP
#include <gtkmm.h>
#include "path.hpp"

namespace Libre {
	class SplashScreen : public Gtk::Window {
		protected:
			Gtk::VBox container;
			Gtk::Label title;
			Gtk::Label header;
			Gtk::Label info;
			Gtk::Spinner spinner;

		public:
			SplashScreen();
			virtual ~SplashScreen() = default;
			Gtk::Label * get_header();
			Gtk::Label * get_info();
			Gtk::Spinner * get_spinner();
	};
}

#endif
