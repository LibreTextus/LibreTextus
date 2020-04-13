#include "package_manager.hpp"

// LIBRE::PACKAGEMANAGER::INIT -------------------------------------------------
// THIS FUNCTION INITIALIZES THE PACKAGEMANAGER. IF THERE IS NO PACKAGE
// INSTALLED IN THE PACKAGE_DIRECTORY IT WILL INSTALL THE DEFAULT
// -----------------------------------------------------------------------------

void Libre::PackageManager::init() {

  this->root_path = this->settings.get<std::string>("root_dir");

  Gtk::Window installer_window;
  installer_window.set_title("Installer");
  installer_window.set_default_size(100, 60);

  Gtk::Label l("Install");

  installer_window.add(l);

  installer_window.show_all();

  l.set_text(("Create root directory under: " + this->root_path).c_str());

  std::string commands =  "if [ -d $'" +  this->root_path + "' ]; then \n" +
                          " mkdir " + this->root_path + "\n" +
                          "fi";

  std::cout << commands << '\n';

  system(commands.c_str());

  l.set_text("Clone default LibreTextusLibrary: LibreTextus/BibleEditions");

  commands =  "if [ '$(ls -A $" + this->root_path + ")' ]; then \n" +
              " git clone http://hackernet.local:3000/LibreTextus/BibleEditions " + this->root_path + "\n" +
              "fi";

  // system(commands.c_str());

}

void Libre::PackageManager::install() {

}

void Libre::PackageManager::remove() {

}

void Libre::PackageManager::disable() {

}

void Libre::PackageManager::enable() {

}
