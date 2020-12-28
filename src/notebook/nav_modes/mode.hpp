#ifndef NAV_MODE
#define NAV_MODE

#include <gtkmm.h>

namespace NavMode {
	class NavMode {
		public:
			virtual std::string get_status() { return ""; }
			virtual bool process_navigation(GdkEventKey *, Glib::RefPtr<Gtk::TextBuffer>) { return false; }
			virtual bool close() { return false; }
			virtual void make_ready(Glib::RefPtr<Gtk::TextBuffer>) {}
	};
}

#endif
