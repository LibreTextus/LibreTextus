#ifndef WIDGETS_HPP
#define WIDGETS_HPP

#include <string>
#include <vector>
#include <gtkmm.h>
#include <iostream>
#include <yaml-cpp/yaml.h>
#include <tsl/ordered_map.h>

#include "package_manager.hpp"

namespace Libre {
	class Widgets {
	public:

		PackageManager package_manager;

		// -------------------------------------------------------------------------
		// DECLINE VARIABLES USED BY THE GUI THREAD
		// -------------------------------------------------------------------------

		Gtk::Window * window;
		Glib::RefPtr<Gtk::Application> app;
		Glib::RefPtr<Gtk::StyleContext> style;
		Glib::RefPtr<Gtk::CssProvider> css;
		Glib::RefPtr<Gtk::CssProvider> font_size_css;
		int font_size;
		Gtk::HBox * panels;
		Gtk::SearchEntry * search_entry;
		Gtk::Button * add_button;
		std::vector<Gtk::Button *> close_buttons;
		std::vector<Gtk::HBox *> headers;
		std::vector<Gtk::TextView *> text_views;
		std::vector<Gtk::ComboBoxText *> combo_boxes;
		std::vector<Glib::RefPtr<Gtk::TextBuffer>> search_results;
		bool is_fullscreen;

		Gtk::Window * preferences_window;
		Gtk::SpinButton * font_size_spinbutton;
		Gtk::ComboBoxText * preferences_theme_combo;
		tsl::ordered_map<std::string, Gtk::CheckButton *> preferences_sources_check;

		Glib::RefPtr<Gtk::UIManager> ui_manager;
		Glib::RefPtr<Gtk::ActionGroup> action_group;
		Gtk::Window * dialog_window;

		// -------------------------------------------------------------------------
		// DECLINE VARIABLES USED BY THE PROCESS THREAD
		// -------------------------------------------------------------------------

		Glib::Thread * process_thread;
		Glib::Dispatcher set_text_dispatcher;
		Glib::Dispatcher delete_thread_dispatcher;
		std::vector<std::array<std::string, 2>> found_text;
		bool procress_finished;
		int replace_id;

		YAML::Node sources;

		Widgets() {
			this->sources = YAML::LoadFile("data/sources.yml");
		}

		~Widgets() {
			delete window;
			delete preferences_window;
		}

		// LIBRE::WIDGETS::APPENDS_SOURCES -----------------------------------------
		// THIS FUNCTION APPENDS ALL ENABLED SOURCES TO AN COMBOBOXTEXT
		// -------------------------------------------------------------------------

		void append_sources(Gtk::ComboBoxText * combo_box) {
			for (YAML::const_iterator i = this->sources.begin(); i != this->sources.end(); i++) {
				if (i->second["enabled"].as<std::string>() == "true") {
					combo_box->append(i->first.as<std::string>());
				}
			}
			combo_box->set_active(0);
		}

		// LIBRE::WIDGETS::ADD_PANEL -----------------------------------------------
		// THIS FUNCTION ADDS A NEW PANEL TO THE WINDOW
		// -------------------------------------------------------------------------

		void add_panel() {

			// ------------------------------------------
			// ADD HEADER AND TEXT_VIEW TO CONTAINER
			// ------------------------------------------

			Gtk::VBox * scrl_container = new Gtk::VBox(false, 0);
			this->text_views.push_back(new Gtk::TextView);
			Gtk::ScrolledWindow * scrolled_window = new Gtk::ScrolledWindow;
			this->headers.push_back(new Gtk::HBox(false, 0));
			this->close_buttons.push_back(new Gtk::Button);
			this->close_buttons.back()->set_image_from_icon_name("window-close", Gtk::ICON_SIZE_BUTTON);
			this->close_buttons.back()->set_name("view_button");

			// ------------------------------------------
			// SET PROPERTIES OF TEXT_VIEW
			// ------------------------------------------

			this->search_results.push_back(Gtk::TextBuffer::create());
			this->text_views.back()->set_buffer(this->search_results.back());
			this->text_views.back()->set_editable(false);
			this->text_views.back()->set_cursor_visible(false);
			this->text_views.back()->set_wrap_mode(Gtk::WRAP_WORD);
			this->text_views.back()->set_border_width(10);

			// ------------------------------------------
			// DISPLAY HEADER AND SCROLLED_WINDOW
			// ------------------------------------------

			scrl_container->pack_start(*this->headers.back(), Gtk::PACK_SHRINK, 0);
			scrl_container->pack_end(*scrolled_window, Gtk::PACK_EXPAND_WIDGET, 0);

			scrolled_window->add(*this->text_views.back());

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

			this->found_text.push_back({"", ""});

			this->panels->pack_start(*scrl_container, Gtk::PACK_EXPAND_WIDGET, 0);

		}
	};
}

#endif
