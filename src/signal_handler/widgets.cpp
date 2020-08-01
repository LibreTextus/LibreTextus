#include "../signal_handler.hpp"

void SignalHandler::disable_widgets() {
	for (int i = 0; i < this->widgets->main.combo_boxes.size(); i++) {
		this->widgets->main.combo_boxes[i]->set_button_sensitivity(Gtk::SENSITIVITY_OFF);
		this->widgets->main.close_buttons[i]->set_sensitive(false);
	}

	this->widgets->main.text_view->grab_focus();

	this->widgets->main.add_button->set_sensitive(false);

	this->widgets->main.search_entry->set_sensitive(false);
	this->widgets->main.history_button->set_sensitive(false);
	this->widgets->ui.action_group->set_sensitive(false);
}
