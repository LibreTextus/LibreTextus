#ifndef MAIN_WINDOW_VIEW_PANE_HPP
#define MAIN_WINDOW_VIEW_PANE_HPP

#include <gtkmm.h>
#include <string>

#include <text_view/text_view.hpp>
#include <notebook/notebook.hpp>
#include "grammar_view/grammar_view.hpp"

namespace Libre {
	class ViewPane : public Gtk::Paned {
		private:
			Gtk::VBox view_container;
			Libre::TextView text_view;
			Libre::GrammarView grammar_view;
			Libre::NoteBook notebook;

		public:
			ViewPane(const std::string &);
			Libre::TextView * get_text_view();
			Libre::NoteBook * get_notebook();
			Libre::GrammarView * get_grammar_view();
	};
}

#endif
