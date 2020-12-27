#include "shortcut_button.hpp"
#include "gtkmm/enums.h"
#include <thread>

Libre::ShortcutButton::ShortcutButton() : Gtk::Button() {
	this->signal_clicked().connect(sigc::mem_fun(this, &Libre::ShortcutButton::on_clicked));
	this->popover.add(entry);
	this->popover.set_position(Gtk::POS_BOTTOM);

	this->entry.signal_changed().connect(sigc::mem_fun(this, &Libre::ShortcutButton::entry_changed), false);
}

void Libre::ShortcutButton::set_shortcut(const std::string & settings_string) {
	this->settings_name = settings_string;
	this->set_label(this->settings.get_attribute(settings_string, "key"));
}

void Libre::ShortcutButton::on_clicked() {
	this->set_label("Press any Key");
	this->popover.set_relative_to(*this);
	this->popover.show_all();
	this->popover.popup();
}

void Libre::ShortcutButton::entry_changed() {
	if (!this->entry.get_text().empty()) {
		this->set_label(this->entry.get_text());
		this->settings.set(this->settings_name, "key", this->entry.get_text());
		this->entry.set_text("");
		this->popover.popdown();
		this->m_refresh_short_cuts();
	}
}

sigc::signal<void> Libre::ShortcutButton::refresh_shortcuts() {
	return this->m_refresh_short_cuts;
}
