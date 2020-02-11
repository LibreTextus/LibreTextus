#include "signal_handler.hpp"

// SIGNAL_HANDLER : SEARCH_REQUEST ---------------------------------------------

gboolean SignalHandler::search_request(GdkEventKey * event) {

	if (event->keyval == 65293) {	// IF ENTER IS PRESSED (KEYCODE: 65293)

		this->widgets->search_entry->set_progress_fraction(0.5);	// SET PROGRESSBAR TO 50%
		this->widgets->search_entry->progress_pulse();						// MAKE PROGRESSBAR PULSE

		this->widgets->verse_content = search_engine->search(this->widgets->search_entry->get_text());	// GET RESULTS

		std::cout << "SEARCH FINISHED" << '\n';

		this->widgets->search_entry->set_progress_fraction(1.0);	// SET PROGRESSBAR TO 100%

		this->update_text_content();															// DISPLAY IT

		this->widgets->search_entry->set_progress_fraction(0.0);	// RESET PROGRESSBAR
	}

	return false;
}

// SIGNAL_HANDLER : UPDATE_TEXT_CONTENT ----------------------------------------

void SignalHandler::update_text_content() {

	this->widgets->search_result->set_text("");

	for (YAML::const_iterator book = this->widgets->verse_content.begin(); book != this->widgets->verse_content.end(); book++) {
		for (YAML::const_iterator chapter = book->second.begin(); chapter != book->second.end(); chapter++) {
			for (YAML::const_iterator verse = chapter->second.begin(); verse != chapter->second.end(); verse++) {

				this->widgets->search_result->insert_markup(
					this->widgets->search_result->end(),
					"<span font_weight=\"ultralight\">" +
					book->first.as<std::string>() + ", " + chapter->first.as<std::string>() + ", " + verse->first.as<std::string>() +
					"</span>"
				);

				this->widgets->search_result->insert_markup(
					this->widgets->search_result->end(),
					"\n\n" +
					search_engine->mark_result(verse->second.as<std::string>(),
																							this->widgets->search_entry->get_text(),
					 																		"<span background=\"#db3131\">", "</span>")
					+ "\n\n"
				);

			}
		}
	}
}
