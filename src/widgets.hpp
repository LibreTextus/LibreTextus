#ifndef WIDGETS_HPP
#define WIDGETS_HPP

#include <string>
#include <vector>
#include <gtkmm.h>
#include <iostream>
#include <yaml-cpp/yaml.h>

class LibreWidgets {
public:

	Glib::RefPtr<Gtk::UIManager> ui_manager;
	Glib::RefPtr<Gtk::ActionGroup> action_group;

	// USED BY GUI THREAD

	Gtk::Window * window;
	Glib::RefPtr<Gtk::Application> app;
	Glib::RefPtr<Gtk::StyleContext> style;
	Glib::RefPtr<Gtk::CssProvider> css;
	Glib::RefPtr<Gtk::CssProvider> font_size_css;
	int font_size;
	Gtk::SpinButton * font_size_spinbutton;
	Gtk::HBox * panels;
	Gtk::SearchEntry * search_entry;
	std::vector<Gtk::TextView> text_views;
	std::vector<Gtk::ComboBoxText> combo_boxes;
	std::vector<Glib::RefPtr<Gtk::TextBuffer>> search_results;
	bool is_fullscreen;
	Gtk::Window * preferences_window;
	Gtk::ComboBoxText * preferences_theme_combo;
	// USED BY SEARCH TRHEAD

	Glib::Thread * process_thread;
	Glib::Dispatcher set_text_dispatcher;
	Glib::Dispatcher delete_thread_dispatcher;
	std::vector<std::string> found_text;
	bool procress_finished;

	YAML::Node sources;

	LibreWidgets() {
		sources = YAML::LoadFile("data/sources.yml");
	}

	~LibreWidgets() {
		delete window;
		delete preferences_window;
	}

	void append_sources(Gtk::ComboBoxText * combo_box) {
		for (YAML::const_iterator i = this->sources.begin(); i != this->sources.end(); i++) {
			combo_box->append(i->first.as<std::string>());
		}

		combo_box->set_active(0);
	}

	void add_panel() {
		Gtk::VBox * scrl_container = new Gtk::VBox(false, 0);
		this->text_views.push_back(Gtk::TextView());
		Gtk::ScrolledWindow * scrolled_window = new Gtk::ScrolledWindow;
		Gtk::HBox * header = new Gtk::HBox(false, 0);

		this->search_results.push_back(Gtk::TextBuffer::create());
		this->text_views.back().set_buffer(this->search_results.back());
		this->text_views.back().set_editable(false);
		this->text_views.back().set_cursor_visible(false);
		this->text_views.back().set_wrap_mode(Gtk::WRAP_WORD);

		scrl_container->pack_start(*header, Gtk::PACK_SHRINK, 0);
		scrl_container->pack_end(*scrolled_window, Gtk::PACK_EXPAND_WIDGET, 0);

		scrolled_window->add(this->text_views.back());
		this->text_views.back().set_border_width(10);

		this->combo_boxes.push_back(Gtk::ComboBoxText());

		this->append_sources(&this->combo_boxes.back());

		header->pack_end(this->combo_boxes.back(), Gtk::PACK_SHRINK, 0);
		header->set_border_width(10);

		this->found_text.push_back("");

		this->panels->pack_start(*scrl_container, Gtk::PACK_EXPAND_WIDGET, 0);

	}
};

#endif
