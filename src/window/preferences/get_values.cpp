#include "preferences.hpp"

Gtk::Notebook * Libre::PreferencesWindow::get_note_book() {
	return &this->note_book;
}

Libre::UserInterfacePane * Libre::PreferencesWindow::get_ui_pane() {
	return &this->ui_pane;
}

Libre::KeybindingsPane * Libre::PreferencesWindow::get_keybindings_pane() {
	return &this->keybindings_pane;
}

Libre::BookManagerPane * Libre::PreferencesWindow::get_book_manager_pane() {
	return &this->book_manager_pane;
}

sigc::signal<void> Libre::PreferencesWindow::restart_application() {
	return this->_restart_application;
}

sigc::signal<void> Libre::PreferencesWindow::sync_source_combo() {
	return this->_sync_all_source_combo_main_window;
}
