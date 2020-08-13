#include "user_inferface_pane.hpp"


Libre::UserInterfacePane::UserInterfacePane()
	: Gtk::VBox(), theme(_("Theme")), locale(_("Language")), font_size(_("Font size")) {

	this->pack_start(this->theme, Gtk::PACK_SHRINK, 0);
	this->pack_start(this->locale, Gtk::PACK_SHRINK, 0);
	this->pack_start(this->font_size, Gtk::PACK_SHRINK, 0);
}

Libre::PreferencesElement<Gtk::ComboBoxText> * Libre::UserInterfacePane::get_theme() {
	return &this->theme;
};

Libre::PreferencesElement<Gtk::ComboBoxText> * Libre::UserInterfacePane::get_locale() {
	return &this->locale;
};

Libre::PreferencesElement<Gtk::SpinButton> * Libre::UserInterfacePane::get_font_size() {
	return &this->font_size;
};

