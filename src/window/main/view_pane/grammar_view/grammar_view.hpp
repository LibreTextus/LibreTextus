#ifndef LIBRE_GRAMMAR_VIEW_HPP
#define LIBRE_GRAMMAR_VIEW_HPP

#include <gtkmm.h>
#include <vector>

namespace Libre {
	class GrammarView : public Gtk::VBox {
		private:
			std::vector<Gtk::Label> labels;
		public:
			GrammarView();
			~GrammarView() = default;
			void clear();
			void append_label(const std::string &);
	};
}

#endif
