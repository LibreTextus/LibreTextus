#ifndef MAIN_WINDOW_VIEW_PANE_HPP
#define MAIN_WINDOW_VIEW_PANE_HPP

#include <gtkmm.h>
#include <string>

#include <text_view/text_view.hpp>
#include <notebook/notebook.hpp>

namespace Libre {
	class ViewPane : public Gtk::Paned {
		private:
			Libre::TextView text_view;
			Libre::NoteBook notebook;

		public:
			ViewPane(const std::string &);
			Libre::TextView * get_text_view();
			Libre::NoteBook * get_notebook();
	};
}

#endif
