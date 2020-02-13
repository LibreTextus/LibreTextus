#include "signal_handler.hpp"

// SIGNAL_HANDLER : SEARCH_REQUEST ---------------------------------------------

gboolean SignalHandler::search_request(GdkEventKey * event) {

	if (event->keyval == 65293) {	// IF ENTER IS PRESSED (KEYCODE: 65293)

		std::string result;

		this->search_engine->set_search_argument(this->widgets->search_entry->get_text());

		while (search_engine->search(&result)) {
			this->widgets->search_result->insert_markup(this->widgets->search_result->end(), result + "\n\n");
		}

		this->widgets->search_result->insert_markup(this->widgets->search_result->end(), result + "\n\n");

		std::cout << "SEARCH FINISHED" << '\n';
	}

	return false;
}
