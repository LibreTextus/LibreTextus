#include "../signal_handler.hpp"

void SignalHandler::delete_thread() {

	if (this->widgets->processing.process_thread->joinable()) {
		this->widgets->processing.process_thread->join();
	}

	this->widgets->main.search_entry->set_progress_fraction(0);

	this->widgets->main.number_results->set_text(std::to_string(this->widgets->search_engine[0].get_last_search_results()->size()) + " " + _("Results"));

	this->widgets->main.text_view->show_if_results();

	for (int i = 0; i < this->widgets->main.combo_boxes.size(); i++) {
		this->widgets->main.combo_boxes[i]->set_button_sensitivity(Gtk::SENSITIVITY_ON);
		this->widgets->main.close_buttons[i]->set_sensitive(true);
	}

	this->widgets->main.add_button->set_sensitive(true);

	this->widgets->main.search_entry->set_sensitive(true);
	this->widgets->main.history_button->set_sensitive(true);
	this->widgets->ui.action_group->set_sensitive(true);

	if (this->widgets->search_engine[0].get_last_search_results()->size() == 0) {
		this->widgets->main.search_entry->grab_focus();
	}
}


