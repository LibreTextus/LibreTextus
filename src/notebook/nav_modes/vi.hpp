#ifndef NAV_VI_MODE
#define NAV_VI_MODE

#include "mode.hpp"

namespace NavMode {

	class VI : public NavMode {
		private:
			enum Modes {NORMAL, INSERT, VISUAL};
			std::vector<std::string> status_string = {"Normal", "Insert", "Visual"};
			short active_mode = Modes::NORMAL;
			guint last_pressed;
			Gtk::TextBuffer::iterator selection_begin;
			bool process_normal(GdkEventKey *, Glib::RefPtr<Gtk::TextBuffer>);
			bool process_insert(GdkEventKey *, Glib::RefPtr<Gtk::TextBuffer>);
			bool process_visual(GdkEventKey *, Glib::RefPtr<Gtk::TextBuffer>);
			bool close_notebook;
		public:
			bool process_navigation(GdkEventKey *, Glib::RefPtr<Gtk::TextBuffer>);
			std::string get_status();
			bool close();
			void make_ready(Glib::RefPtr<Gtk::TextBuffer>);
	};
}
#endif
