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

	delete[] this->widgets->verse_containers;

	int size = 0;

	for (YAML::const_iterator book = this->widgets->verse_content.begin(); book != this->widgets->verse_content.end(); book++) {
		for (YAML::const_iterator chapter = book->second.begin(); chapter != book->second.end(); chapter++) {
			size += chapter->second.size();
		}
	}

	std::cout << size << '\n';

	this->widgets->verse_containers = new Gtk::ListBoxRow[size];

	int i = 0;

	for (YAML::const_iterator book = this->widgets->verse_content.begin(); book != this->widgets->verse_content.end(); book++) {
		for (YAML::const_iterator chapter = book->second.begin(); chapter != book->second.end(); chapter++) {
			for (YAML::const_iterator verse = chapter->second.begin(); verse != chapter->second.end(); verse++) {
				Gtk::Label * text = new Gtk::Label;
				text->set_markup(verse->second.as<std::string>());
				text->set_halign(Gtk::ALIGN_START);
				text->set_valign(Gtk::ALIGN_START);
				text->set_selectable(true);
				text->set_line_wrap(true);

				this->widgets->verse_containers[i].add(*text);

				this->widgets->verse_box->add(this->widgets->verse_containers[i]);

				this->widgets->verse_containers[i].show_all();

				i++;
			}
		}
	}
}
