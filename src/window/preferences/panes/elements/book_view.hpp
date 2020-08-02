#ifndef BOOK_VIEW_HPP
#define BOOK_VIEW_HPP

#include "gtkmm/box.h"
#include <gtkmm.h>
#include <vector>
#include <string>

namespace Libre {
	namespace BookManagerElements {

		class BookListItem : public Gtk::HBox {
			private:
				Gtk::Label title;
				Gtk::CheckButton button;

			public:
				BookListItem(const std::string & t) : Gtk::HBox(), title(t) {
					this->pack_start(this->title, Gtk::PACK_SHRINK, 0);
					this->pack_start(this->button, Gtk::PACK_SHRINK, 0);
				}

				virtual ~BookListItem() = default;

				Gtk::Label * get_title() { return &this->title; }
				Gtk::CheckButton * get_button() { return &this->button; }
		};

		class BookList : public Gtk::ScrolledWindow {
			private:
				Gtk::VBox container;
				std::vector<BookListItem> items;

			public:
				BookList() : Gtk::ScrolledWindow() {
					this->add(this->container);
				}

				virtual ~BookList() = default;

				void append(const std::string & name) {
					this->items.push_back(BookListItem(name));
					this->container.pack_start(this->items.back());
				}

				Gtk::VBox * get_container() { return &this->container; }
				std::vector<BookListItem> * get_items() { return &this->items; }

		};

		class ManageButtons : public Gtk::HBox {
			private:
				Gtk::Button add;
				Gtk::Button remove;

			public:
				ManageButtons() : Gtk::HBox() {
					this->add.set_name("add_button");
					this->remove.set_name("remove_button");
					this->pack_end(this->add, Gtk::PACK_SHRINK, 0);
					this->pack_end(this->remove, Gtk::PACK_SHRINK, 0);
				}

				virtual ~ManageButtons();

				Gtk::Button * get_add() { return &this->add; }
				Gtk::Button * get_remove() { return &this->remove; }
		};
	}
}

#endif
