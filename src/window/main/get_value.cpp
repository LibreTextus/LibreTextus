#include "main.hpp"

Libre::Menu * Libre::MainWindow::get_menu() {
	return &this->menu;
}


Libre::SearchSection * Libre::MainWindow::get_search_section() {
	return &this->search_section;
}

Libre::ViewPane * Libre::MainWindow::get_view_pane() {
	return &this->view_pane;
}

Gtk::VBox * Libre::MainWindow::get_container() {
	return &this->container;
}

Glib::Dispatcher * Libre::MainWindow::get_sync_sources_dispatcher() {
	return &this->sync_sources_dispatcher;
}
