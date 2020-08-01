#include "../dialog_window.hpp"

Libre::DialogWindow::DialogWindow(const std::string & title, const std::string & info) : Window(), info_label(info), ok_button(_("OK")), cancel_button(_("Cancel")) {

	this->main_container.set_border_width(10);
	this->main_container.set_spacing(10);

	this->button_container.set_border_width(10);
	this->button_container.set_spacing(10);
	this->button_container.pack_end(this->ok_button, Gtk::PACK_SHRINK, 0);
	this->button_container.pack_end(this->cancel_button, Gtk::PACK_SHRINK, 0);

	this->main_container.pack_start(info_label, Gtk::PACK_SHRINK, 0);
	this->main_container.pack_start(button_container, Gtk::PACK_SHRINK, 0);
	this->add(main_container);
	
	this->set_title(title);
	this->set_default_size(300, 100);
	this->set_keep_above(true);
	this->set_resizable(false);
	this->set_position(Gtk::WIN_POS_CENTER);
}

Gtk::VBox * Libre::DialogWindow::get_main_container() {
	return &this->main_container;
}

Gtk::HBox * Libre::DialogWindow::get_button_container() {
	return &this->button_container;
}

Gtk::Label * Libre::DialogWindow::get_info_label() {
	return &this->info_label;
}

Gtk::Button * Libre::DialogWindow::get_ok_button() {
	return &this->ok_button;
}

Gtk::Button * Libre::DialogWindow::get_cancel_button() {
	return &this->cancel_button;
}

Libre::ComboDialogWindow::ComboDialogWindow(const std::string & title, const std::string & info, const std::vector<std::string> & items) : Libre::DialogWindow(title, info) {
	for (int i = 0; i < items.size(); i++) {
		this->combo.append(items[i]);
	}
	this->combo.set_active(0);

	this->main_container.pack_start(this->combo, Gtk::PACK_SHRINK, 0);
	this->main_container.reorder_child(this->combo, 1);
}

Gtk::ComboBoxText * Libre::ComboDialogWindow::get_combo() {
	return &this->combo;
}

Libre::EntryDialogWindow::EntryDialogWindow(const std::string & title, const std::string & info, const std::string & placeholder_text) : Libre::DialogWindow(title, info) {
	this->entry.set_placeholder_text(placeholder_text);
	this->main_container.pack_start(this->entry, Gtk::PACK_SHRINK, 0);
	this->main_container.reorder_child(this->entry, 1);
}

Gtk::Entry * Libre::EntryDialogWindow::get_entry() {
	return &this->entry;
}
