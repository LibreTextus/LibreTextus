#include "signal_handler.hpp"

// SIGNAL_HANDLER : SEARCH_REQUEST ---------------------------------------------

gboolean SignalHandler::search_request(GdkEventKey * event) {

	if (event->keyval == 65293) {	// IF ENTER IS PRESSED (KEYCODE: 65293)

		std::string result;

		this->search_engine->set_search_argument(this->widgets->search_entry->get_text());

		this->widgets->search_result->set_text("");

		while (search_engine->search(&result)) {
			this->widgets->search_result->insert_markup(this->widgets->search_result->end(), result + "\n\n");
		}
	}

	return false;
}

void SignalHandler::source_changed() {
	this->search_engine->set_source(
		"data/BibleEditions/" +
		this->widgets->sources[std::string(this->widgets->combo_boxes->get_active_text())].as<std::string>()
	);

	std::vector<std::array<std::string, 3>> * v = search_engine->get_last_search_results();

	this->widgets->search_result->set_text("");

	std::string result;

	for (std::vector<std::array<std::string, 3>>::iterator i = v->begin(); i != v->end(); i++) {

		std::string verse = (*i)[0] + ", " + (*i)[1] + ", " + (*i)[2] + "\n\n";
		verse += this->search_engine->get_verse((*i)[0], (*i)[1], (*i)[2]) + "\n\n";

		this->widgets->search_result->insert_markup(this->widgets->search_result->end(), verse);
	}
}
