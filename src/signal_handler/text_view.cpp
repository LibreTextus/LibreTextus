#include "../signal_handler.hpp"

void SignalHandler::set_text() {

	this->widgets->processing.process_mutex.lock();

	if (this->widgets->processing.replace_id == -1) {
		this->widgets->main.text_view->add_verse(
			this->widgets->processing.found_position,
			this->widgets->processing.found_verses
		);
	} else {
		this->widgets->main.text_view->replace_verse(
			this->widgets->processing.found_position,
			this->widgets->processing.replace_id,
			this->widgets->processing.found_verses.back()
		);
	}

	this->widgets->processing.procress_finished = true;

	this->widgets->processing.process_mutex.unlock();
}

