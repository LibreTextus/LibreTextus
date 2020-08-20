#include "menu.hpp"

Libre::Menu::Menu() : Gtk::MenuBar() {
}

void Libre::Menu::add_menu_item(const std::string & name) {
	this->menu[name] = new Libre::MenuElement(name);
	this->append(*this->menu[name]);
}

void Libre::Menu::add_sub_menu_item(const std::string & name, const std::string & parent, const std::string & shortcut, const sigc::slot<void> & slot) {

	Libre::SubMenuElement * item = new Libre::SubMenuElement(name, Gtk::AccelKey(shortcut), slot);
	this->menu[parent]->get_submenu()->append(*item);
}

void Libre::Menu::add_sub_menu_item(const std::string & name, const std::string & parent, const Gtk::AccelKey & shortcut, const sigc::slot<void> & slot) {

	Libre::SubMenuElement * item = new Libre::SubMenuElement(name, shortcut, slot);
	this->menu[parent]->get_submenu()->append(*item);
}

void Libre::Menu::add_seperator_to_submenu(const std::string & parent) {
	this->menu[parent]->get_submenu()->append(*(new Gtk::SeparatorMenuItem()));
}
