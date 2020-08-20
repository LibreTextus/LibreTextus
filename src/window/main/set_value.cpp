#include "main.hpp"
#include "package_manager/package_manager.hpp"

void Libre::MainWindow::set_package_manager(Libre::PackageManager * p) {
	this->package_manager = p;
}

void Libre::MainWindow::set_preferences_window(Libre::PreferencesWindow * p) {
	this->preferences_window = p;
}

void Libre::MainWindow::set_application(Glib::RefPtr<Gtk::Application> p) {
	this->app = p;
}
