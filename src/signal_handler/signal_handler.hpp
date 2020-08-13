#ifndef SIGNAL_HANDLER_HPP
#define SIGNAL_HANDLER_HPP

#include <gtkmm.h>
#include <iostream>
#include <thread>
#include <algorithm>
#include <glibmm/i18n.h>

#include <window/dialog/dialog.hpp>
#include <settings/settings.hpp>
#include <path/path.hpp>
#include <widgets.hpp>
#include <log/log.hpp>
#include <source_handler.hpp>

class SignalHandler {
private:
	Libre::Widgets * widgets;
	Libre::Settings settings;
	std::string mark_argument;
	std::string header_argument;

	std::string get_mark_color();
	void set_startup_file_if_empty();

	void disable_widgets();
	void set_replace_id(Gtk::ComboBoxText *);
	void change_source_at_replace_id();
	void sync_combo_boxes();
	void add_new_search_engine();
	void connect_signals_of_new_buttons();
	int get_id_close_button_and_erase(Gtk::Button * b);
	void remove_tab_index(const int &);
	void move_add_button(const int &);

public:
	SignalHandler() {}

	virtual ~SignalHandler() {
	}

	void init(Libre::Widgets * w);

	gboolean search_request(GdkEventKey * event);
	void do_search();
	void do_replacement();

	void set_text();
	void delete_thread();

	void source_changed(Gtk::ComboBoxText * b);

	void quit();
	void toggle_fullscreen();
	void toggle_iconify();
	void toggle_search();
	void toggle_preferences();
	void zoom_in();
	void zoom_out();
	void zoom_reset();
	void add_source();
	void remove_source();
	void remove_source_by_reference(Gtk::Button * b);


	void add_source_dir();
	void remove_source_dir();

	void sync_enabled_sources();

	void toggle_note(std::string position);
	void export_notes();
	void trigger_search(const std::string & text);
	void trigger_search_with_history(const std::string & text);
};

#endif
