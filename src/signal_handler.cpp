#include "signal_handler.hpp"

gboolean SignalHandler::search_request(GdkEventKey * event) {
	if (event->keyval == 65293) {
		std::cout << "SEARCH REQUEST: " << this->widgets->search_entry->get_text() << '\n';
		search_engine->search(this->widgets->search_entry->get_text());
		std::cout << "--- FOUND RESULTS FOR: " << this->widgets->search_entry->get_text() << " ---" << '\n';
	}
	return false;
}
