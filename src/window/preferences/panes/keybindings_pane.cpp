#include "keybindings_pane.hpp"
#include "gtkmm/enums.h"
#include "gtkmm/fontbutton.h"
#include "window/preferences/panes/elements/default.hpp"
#include "window/preferences/panes/elements/shortcut_button.hpp"

Libre::KeybindingsPane::KeybindingsPane()
	:
	Gtk::VBox(),
	down_scrolling("Down"),
	up_scrolling("Up"),
	go_bottom("Go to Bottom"),
	go_top("Go to Top"),
	notebook_mode("Notebook Mode")
{
	this->down_scrolling.get_element()->set_shortcut("scdown");
	this->up_scrolling.get_element()->set_shortcut("scup");
	this->go_bottom.get_element()->set_shortcut("scbottom");
	this->go_top.get_element()->set_shortcut("sctop");

	this->notebook_mode.get_element()->append("Normal");
	this->notebook_mode.get_element()->append("Vim");


	this->notebook_mode.get_element()->set_active_text(this->settings.get_attribute("editor", "mode"));

	this->notebook_mode.get_element()->signal_changed().connect([this] () {
				this->settings.set("editor", "mode", this->notebook_mode.get_element()->get_active_text());
				this->m_refresh_mode.emit();
			});

	this->pack_start(up_scrolling, Gtk::PACK_SHRINK);
	this->pack_start(down_scrolling, Gtk::PACK_SHRINK);
	this->pack_start(go_top, Gtk::PACK_SHRINK);
	this->pack_start(go_bottom, Gtk::PACK_SHRINK);
	this->pack_start(notebook_mode, Gtk::PACK_SHRINK);
}


Libre::PreferencesElement<Libre::ShortcutButton> * Libre::KeybindingsPane::get_down() {
	return &this->down_scrolling;
}

Libre::PreferencesElement<Libre::ShortcutButton> * Libre::KeybindingsPane::get_up() {
	return &this->up_scrolling;
}

Libre::PreferencesElement<Libre::ShortcutButton> * Libre::KeybindingsPane::get_bottom() {
	return &this->go_bottom;
}

Libre::PreferencesElement<Libre::ShortcutButton> * Libre::KeybindingsPane::get_top() {
	return &this->go_top;
}
