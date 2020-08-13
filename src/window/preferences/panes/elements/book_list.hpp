#ifndef BOOK_LIST_HPP
#define BOOK_LIST_HPP

#include <gtkmm.h>
#include <vector>
#include <string>

namespace Libre {
	namespace BookManagerElements {

		class BookList : public Gtk::ScrolledWindow {
			private:
				Gtk::VBox container;
				std::vector<Gtk::CheckButton *> items;

			public:
				BookList();
				virtual ~BookList() = default;

				void append(const std::string & name);

				Gtk::VBox * get_container();
				std::vector<Gtk::CheckButton *> * get_items();

		};

	}
}

#endif
