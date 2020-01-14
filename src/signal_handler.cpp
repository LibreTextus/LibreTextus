#include "signal_handler.hpp"

gboolean SignalHandler::search_request(GdkEventKey * event) {
	if (event->keyval == 65293) {
		std::cout << "SEARCH REQUEST: " << this->search_entry->get_text() << '\n';
		std::cout << search_engine->search(this->search_entry->get_text()) << '\n';
	}
	return false;
}
