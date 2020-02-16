#include "signal_handler.hpp"

// SIGNAL_HANDLER : SEARCH_REQUEST ---------------------------------------------

gboolean SignalHandler::search_request(GdkEventKey * event) {

	if (event->keyval == 65293) {	// IF ENTER IS PRESSED (KEYCODE: 65293)
		this->widgets->combo_boxes->set_button_sensitivity(Gtk::SENSITIVITY_OFF);
		this->widgets->search_entry->set_editable(false);
		this->widgets->search_result->set_text("");
		this->widgets->process_thread = Glib::Thread::create(sigc::mem_fun(*this, &SignalHandler::do_search), true);
	}

	return false;
}

void SignalHandler::source_changed() {
	this->widgets->combo_boxes->set_button_sensitivity(Gtk::SENSITIVITY_OFF);
	this->widgets->search_entry->set_editable(false);
	this->widgets->search_result->set_text("");
	this->widgets->process_thread = Glib::Thread::create(sigc::mem_fun(*this, &SignalHandler::do_replacement), true);
}

void SignalHandler::set_text() {
	this->widgets->search_result->insert_markup(this->widgets->search_result->end(), this->widgets->found_text + "\n\n");
	this->widgets->procress_finished = true;
}

void SignalHandler::delete_thread() {
	if (this->widgets->process_thread) {
		if (this->widgets->process_thread->joinable()) {
			this->widgets->process_thread->join();
		}
	}
}

void SignalHandler::do_search() {
	this->search_engine->set_search_argument(this->widgets->search_entry->get_text());

	while (search_engine->search(&this->widgets->found_text)) {
		this->widgets->procress_finished = false;
		this->widgets->set_text_dispatcher.emit();
		while (!this->widgets->procress_finished) {}
		this->widgets->search_progress = this->search_engine->get_progress();
		this->widgets->search_entry->set_progress_fraction(this->search_engine->get_progress());
	}

	this->widgets->search_entry->set_progress_fraction(0.0);
	this->widgets->combo_boxes->set_button_sensitivity(Gtk::SENSITIVITY_ON);
	this->widgets->search_entry->set_editable(true);

	this->widgets->delete_thread_dispatcher.emit();
}

void SignalHandler::do_replacement() {
	this->search_engine->set_source(
		"data/BibleEditions/" +
		this->widgets->sources[std::string(this->widgets->combo_boxes->get_active_text())].as<std::string>()
	);

	std::vector<std::array<std::string, 3>> * v = search_engine->get_last_search_results();

	for (std::vector<std::array<std::string, 3>>::iterator i = v->begin(); i != v->end(); i++) {
		this->widgets->procress_finished = false;
		this->widgets->found_text = "<span font_weight=\"ultralight\">" + (*i)[0] + ", " + (*i)[1] + ", " + (*i)[2] + "</span>\n\n";
		this->widgets->found_text += this->search_engine->get_verse((*i)[0], (*i)[1], (*i)[2]);
		this->widgets->set_text_dispatcher.emit();
		while (!this->widgets->procress_finished) {}
	}

	this->widgets->combo_boxes->set_button_sensitivity(Gtk::SENSITIVITY_ON);
	this->widgets->search_entry->set_editable(true);
}
