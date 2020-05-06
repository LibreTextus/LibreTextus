#ifndef WIDGETS_HPP
#define WIDGETS_HPP

#include <string>
#include <vector>
#include <gtkmm.h>
#include <iostream>
#include <yaml-cpp/yaml.h>
#include <tsl/ordered_map.h>

#include "text_view.hpp"
#include "notebook.hpp"
#include "package_manager.hpp"
#include "search_engine.hpp"
#include "settings.hpp"

namespace Libre {
	class Widgets {
	public:

		PackageManager package_manager;

		// -------------------------------------------------------------------------
		// DECLINE VARIABLES USED BY THE GUI THREAD
		// -------------------------------------------------------------------------

		Settings settings;
		std::vector<SearchEngine> search_engine;

		Gtk::Window * window;
		Glib::RefPtr<Gtk::Application> app;
		Glib::RefPtr<Gtk::StyleContext> style;
		Glib::RefPtr<Gtk::CssProvider> css;
		Glib::RefPtr<Gtk::CssProvider> font_size_css;
		int font_size;
		Gtk::SearchEntry * search_entry;
		Gtk::HBox * panels;
		Gtk::Button * add_button;
		std::vector<Gtk::Button *> close_buttons;
		std::vector<Gtk::HBox *> headers;
		std::vector<Gtk::ComboBoxText *> combo_boxes;
		Libre::TextView * text_view;
		Libre::NoteBook * note_book;
		Gtk::Paned * note_paned;
		std::string found_position;
		std::vector<std::string *> found_verses;
		bool is_fullscreen;
		bool is_note_book_open;

		Gtk::Window * preferences_window;
		Gtk::SpinButton * font_size_spinbutton;
		Gtk::ComboBoxText * preferences_theme_combo;
		Gtk::VBox * book_manager_box;
		tsl::ordered_map<std::string, Gtk::CheckButton *> preferences_sources_check;

		Glib::RefPtr<Gtk::UIManager> ui_manager;
		Glib::RefPtr<Gtk::ActionGroup> action_group;
		Gtk::Window * dialog_window;

		// -------------------------------------------------------------------------
		// DECLINE VARIABLES USED BY THE PROCESS THREAD
		// -------------------------------------------------------------------------

		Glib::Thread * process_thread;
		Glib::Thread * update_thread;
		std::mutex process_mutex;
		Glib::Dispatcher set_text_dispatcher;
		Glib::Dispatcher delete_thread_dispatcher;
		Glib::Dispatcher sync_sources_dispatcher;
		Glib::Dispatcher start_session;
		bool procress_finished;
		int replace_id;

		Widgets() = default;

		~Widgets() {
			delete this->window;
			delete this->preferences_window;
			delete this->dialog_window;

			delete this->search_entry;
			delete this->panels;
			delete this->add_button;

			for (int i = 0; i < this->headers.size(); i++) {
				delete this->close_buttons[i];
				delete this->headers[i];
				delete this->combo_boxes[i];
			}

			delete this->text_view;
			delete this->note_book;
			delete this->note_paned;

			delete this->font_size_spinbutton;
			delete this->preferences_theme_combo;
			delete this->book_manager_box;
		}

		void destroy_with_children(Gtk::Window * w) {
			this->app->remove_window(*w);

			delete w;
		}

		// LIBRE::WIDGETS::APPENDS_SOURCES -----------------------------------------
		// THIS FUNCTION APPENDS ALL ENABLED SOURCES TO AN COMBOBOXTEXT
		// -------------------------------------------------------------------------

		void append_sources(Gtk::ComboBoxText * combo_box) {
			for (YAML::const_iterator i = this->package_manager.get_sources().begin(); i != this->package_manager.get_sources().end(); i++) {
				if (this->package_manager.is_enabled(i->first.as<std::string>())) {
					combo_box->append(i->first.as<std::string>());
				}
			}
			combo_box->set_active_text(this->settings.get<std::string>("startup_file"));
		}

		// LIBRE::WIDGETS::ADD_PANEL -----------------------------------------------
		// THIS FUNCTION ADDS A NEW PANEL TO THE WINDOW
		// -------------------------------------------------------------------------

		void add_panel() {

			// ------------------------------------------
			// ADD HEADER AND TEXT_VIEW TO CONTAINER
			// ------------------------------------------

			Gtk::VBox * scrl_container = new Gtk::VBox(false, 0);
			this->headers.push_back(new Gtk::HBox(false, 0));
			this->close_buttons.push_back(new Gtk::Button);
			this->close_buttons.back()->set_image_from_icon_name("window-close", Gtk::ICON_SIZE_BUTTON);
			this->close_buttons.back()->set_name("view_button");

			// ------------------------------------------
			// ADD COMBOBOX TO HEADER AND APPEND SOURCES
			// ------------------------------------------

			this->combo_boxes.push_back(new Gtk::ComboBoxText);

			this->append_sources(this->combo_boxes.back());

			// ------------------------------------------
			// REMOVE THE ADD BUTTON FROM THE LAST HEADER
			// AND ADD IT TO THIS HEADER
			// ------------------------------------------

			if (this->add_button != nullptr) {
				this->add_button->get_parent()->remove(*this->add_button);
				delete this->add_button;
			}

			this->add_button = new Gtk::Button;
			this->add_button->set_image_from_icon_name("list-add", Gtk::ICON_SIZE_BUTTON);
			this->add_button->set_name("view_button");

			this->headers.back()->pack_end(*this->add_button, Gtk::PACK_SHRINK, 0);
			this->headers.back()->pack_end(*this->close_buttons.back(), Gtk::PACK_SHRINK, 0);
			this->headers.back()->pack_end(*this->combo_boxes.back(), Gtk::PACK_SHRINK, 0);
			this->headers.back()->set_border_width(10);

			this->panels->pack_start(*this->headers.back(), Gtk::PACK_EXPAND_WIDGET, 0);
		}
	};
}

#endif
