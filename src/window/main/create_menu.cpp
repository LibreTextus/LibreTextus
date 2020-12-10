#include "main.hpp"

void Libre::MainWindow::create_menu_items() {
	menu.add_menu_item(_("File"));
	menu.add_sub_menu_item(_("Export Notes"), _("File"), "<control>E", sigc::mem_fun(this, &MainWindow::export_notes));
	menu.add_seperator_to_submenu(_("File"));
	menu.add_sub_menu_item(_("Quit"), _("File"), "<control>Q", sigc::mem_fun(this, &MainWindow::quit));

	menu.add_menu_item(_("Edit"));
	menu.add_sub_menu_item(_("Search"), _("Edit"), "<control>F", sigc::mem_fun(this, &MainWindow::toggle_search));
	menu.add_sub_menu_item(_("Preferences"), _("Edit"), Gtk::AccelKey(',', Gdk::ModifierType::CONTROL_MASK), sigc::mem_fun(this, &MainWindow::toggle_preferences));

	menu.add_menu_item(_("View"));
	menu.add_sub_menu_item(_("Add Source"), _("View"), "<control>N", sigc::mem_fun(this, &MainWindow::add_source));
	menu.add_sub_menu_item(_("Remove Source"), _("View"), "<control>D", sigc::mem_fun(this, &MainWindow::remove_source));
	menu.add_sub_menu_item(_("Zoom in"), _("View"), Gtk::AccelKey('+', Gdk::ModifierType::CONTROL_MASK), sigc::mem_fun(this, &MainWindow::zoom_in));
	menu.add_sub_menu_item(_("Zoom out"), _("View"), Gtk::AccelKey('-', Gdk::ModifierType::CONTROL_MASK), sigc::mem_fun(this, &MainWindow::zoom_out));
	menu.add_sub_menu_item(_("Zoom reset"), _("View"), Gtk::AccelKey('=', Gdk::ModifierType::CONTROL_MASK), sigc::mem_fun(this, &MainWindow::zoom_reset));
	menu.add_sub_menu_item(_("Minimize"), _("View"), "<control>M", sigc::mem_fun(this, &MainWindow::toggle_iconify));
	menu.add_sub_menu_item(_("Fullscreen"), _("View"), "F11", sigc::mem_fun(this, &MainWindow::toggle_fullscreen));

	menu.add_menu_item(_("History"));
	menu.add_sub_menu_item(_("Go back"), _("History"), "<alt>Left", 
			sigc::bind<bool>(sigc::mem_fun(this->search_section.get_history_button(), &Libre::HistoryButton::button_pressed), false));
	menu.add_sub_menu_item(_("Go forward"), _("History"), "<alt>Right", 
			sigc::bind<bool>(sigc::mem_fun(this->search_section.get_history_button(), &Libre::HistoryButton::button_pressed), true));

	menu.add_menu_item(_("Help"));
	menu.add_sub_menu_item(_("Help"), _("Help"), "F1", sigc::mem_fun(this, &MainWindow::zoom_in));
	menu.add_sub_menu_item(_("About"), _("Help"), "", sigc::mem_fun(this, &MainWindow::show_about_window));
}
