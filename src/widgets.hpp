#ifndef WIDGETS_HPP
#define WIDGETS_HPP

#include <string>
#include <vector>
#include <gtkmm.h>
#include <iostream>
#include <mutex>
#include <tsl/ordered_map.h>

#include "splash_screen.hpp"
#include "text_view.hpp"
#include "notebook.hpp"
#include "history_button.hpp"
#include "package_manager.hpp"
#include "search_engine.hpp"
#include "settings.hpp"

namespace Libre {
	struct Widgets {

		PackageManager package_manager;

		// -------------------------------------------------------------------------
		// DECLINE VARIABLES USED BY THE GUI THREAD
		// -------------------------------------------------------------------------

		Settings settings;
		std::vector<SearchEngine> search_engine;

		Glib::RefPtr<Gtk::Application> app;

		struct Main {
			Gtk::Window * window;
			Libre::HistoryButton * history_button;
			Gtk::SearchEntry * search_entry;
			Gtk::Label * number_results;
			Gtk::HBox * panels;
			Gtk::Button * add_button;
			std::vector<Gtk::Button *> close_buttons;
			std::vector<Gtk::HBox *> headers;
			std::vector<Gtk::ComboBoxText *> combo_boxes;
			Libre::TextView * text_view;
			Libre::NoteBook * note_book;
			Gtk::Paned * note_paned;
			bool is_fullscreen;
			bool is_note_book_open;
		} main;

		Libre::SplashScreen * splash_screen;

		struct Preferences {
			Gtk::Window * window;
			Gtk::SpinButton * font_size_spinbutton;
			Gtk::ComboBoxText * theme_combo;
			Gtk::ComboBoxText * lang_combo;
			Gtk::ComboBoxText * default_source_combo;
			Gtk::VBox * book_manager_box;
			tsl::ordered_map<std::string, Gtk::CheckButton *> sources_check;
		} preferences;

		struct Style {
			Glib::RefPtr<Gtk::StyleContext> style;
			Glib::RefPtr<Gtk::CssProvider> css;
			Glib::RefPtr<Gtk::CssProvider> font_size_css;
			int font_size;
		} style;

		struct UI {
			Glib::RefPtr<Gtk::UIManager> manager;
			Glib::RefPtr<Gtk::ActionGroup> action_group;
		} ui;
		
		// -------------------------------------------------------------------------
		// DECLINE VARIABLES USED BY THE PROCESS THREAD
		// -------------------------------------------------------------------------

		struct Processing {
			Glib::Thread * process_thread;
			Glib::Thread * update_thread;
			std::mutex process_mutex;
			Glib::Dispatcher set_text_dispatcher;
			Glib::Dispatcher delete_thread_dispatcher;
			Glib::Dispatcher sync_sources_dispatcher;
			Glib::Dispatcher start_session;
			bool procress_finished;
			int replace_id;
			std::string found_position;
			std::vector<std::string *> found_verses;
			bool restart_application;
		} processing;

		Widgets() = default;

		~Widgets() {
			delete this->main.window;
			delete this->preferences.window;

			delete this->main.search_entry;
			delete this->main.number_results;
			delete this->main.panels;
			delete this->main.add_button;

			for (int i = 0; i < this->main.headers.size(); i++) {
				delete this->main.close_buttons[i];
				delete this->main.headers[i];
				delete this->main.combo_boxes[i];
			}

			delete this->main.note_book;
			delete this->main.text_view;
			delete this->main.note_paned;

			delete this->preferences.font_size_spinbutton;
			delete this->preferences.theme_combo;
			delete this->preferences.book_manager_box;
			delete this->preferences.default_source_combo;

			delete this->splash_screen;
		}

		// LIBRE::WIDGETS::APPENDS_SOURCES -----------------------------------------
		// THIS FUNCTION APPENDS ALL ENABLED SOURCES TO AN COMBOBOXTEXT
		// -------------------------------------------------------------------------

		void append_sources(Gtk::ComboBoxText * combo_box) {
			for (std::vector<std::string>::iterator i = this->package_manager.get_sources().begin(); i != this->package_manager.get_sources().end(); i++) {
				if (this->package_manager.is_enabled(*i)) {
					combo_box->append(*i);
				}
			}
			combo_box->set_active_text(this->settings.get_attribute("startupfile", "file"));
		}

		// LIBRE::WIDGETS::ADD_PANEL -----------------------------------------------
		// THIS FUNCTION ADDS A NEW PANEL TO THE WINDOW
		// -------------------------------------------------------------------------

		void add_panel() {

			// ------------------------------------------
			// ADD HEADER AND TEXT_VIEW TO CONTAINER
			// ------------------------------------------

			Gtk::VBox * scrl_container = new Gtk::VBox(false, 0);
			this->main.headers.push_back(new Gtk::HBox(false, 0));
			this->main.close_buttons.push_back(new Gtk::Button);
			this->main.close_buttons.back()->set_name("close_button");
			// Gtk::Image * img = new Gtk::Image(DATA("res/close.svg"));
			// this->main.close_buttons.back()->set_image(*img);
			// ------------------------------------------
			// ADD COMBOBOX TO HEADER AND APPEND SOURCES
			// ------------------------------------------

			this->main.combo_boxes.push_back(new Gtk::ComboBoxText);

			this->append_sources(this->main.combo_boxes.back());

			// ------------------------------------------
			// REMOVE THE ADD BUTTON FROM THE LAST HEADER
			// AND ADD IT TO THIS HEADER
			// ------------------------------------------

			if (this->main.add_button != nullptr) {
				this->main.add_button->get_parent()->remove(*this->main.add_button);
				delete this->main.add_button;
			}

			this->main.add_button = new Gtk::Button;
			this->main.add_button->set_name("add_button");
			this->main.add_button->set_always_show_image(true);

			this->main.headers.back()->pack_end(*this->main.add_button, Gtk::PACK_SHRINK, 0);
			this->main.headers.back()->pack_end(*this->main.close_buttons.back(), Gtk::PACK_SHRINK, 0);
			this->main.headers.back()->pack_end(*this->main.combo_boxes.back(), Gtk::PACK_SHRINK, 0);
			this->main.headers.back()->set_border_width(10);

			this->main.panels->pack_start(*this->main.headers.back(), Gtk::PACK_EXPAND_WIDGET, 0);
		}
	};
}

#endif
