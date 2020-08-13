#include "preferences.hpp"
#include "gtkmm/enums.h"

Libre::PreferencesWindow::PreferencesWindow() : Gtk::Window() {

	this->create_css_context();

	this->note_book.append_page(this->ui_pane, _("Appearance"));
	this->note_book.append_page(this->keybindings_pane, _("Keybindings"));
	this->note_book.append_page(this->book_manager_pane, _("Book Manager"));

	this->add_themes_to_themes_combo();
	this->add_locales_to_locales_combo();
	this->set_font_size_adjustment();

	this->ui_pane.get_theme()->get_element()->signal_changed().connect(
			sigc::mem_fun(this, &Libre::PreferencesWindow::theme_changed));

	this->ui_pane.get_locale()->get_element()->signal_changed().connect(
			sigc::mem_fun(this, &Libre::PreferencesWindow::locales_changed));

	this->ui_pane.get_font_size()->get_element()->signal_value_changed().connect(
			sigc::mem_fun(this, &Libre::PreferencesWindow::font_size_changed));

	this->book_manager_pane.get_default_source()->get_element()->signal_changed().connect(
			sigc::mem_fun(this, &Libre::PreferencesWindow::default_source_changed));

	this->book_manager_pane.get_manage_butons()->get_add()->signal_clicked().connect(
			sigc::mem_fun(this, &Libre::PreferencesWindow::manage_buttons_add_pressed));

	this->book_manager_pane.get_manage_butons()->get_remove()->signal_clicked().connect(
			sigc::mem_fun(this, &Libre::PreferencesWindow::manage_buttons_remove_pressed));

	this->sync_sources_dispatcher.connect(
			sigc::mem_fun(this, &Libre::PreferencesWindow::sync_sources));

	this->add(this->note_book);

	this->set_default_size(500, 400);
	this->set_keep_above(true);
	this->set_resizable(false);
	this->set_position(Gtk::WIN_POS_CENTER);
}
