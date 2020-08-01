#include "../signal_handler.hpp"

gboolean SignalHandler::search_request(GdkEventKey * event) {
	LOG("--> \"search_request\" emmited");

	if (event->keyval == 65293) {

		if (this->widgets->main.search_entry->get_text() == "") {
			this->widgets->main.text_view->show_information();
			this->widgets->main.text_view->clear();
			this->widgets->search_engine[0].set_search_argument("");
			return false;
		}

		std::string text = this->widgets->main.search_entry->get_text();
		this->trigger_search_with_history(text);

	} else if (event->keyval == 65307) {
		this->widgets->main.text_view->grab_focus();
		this->widgets->main.search_entry->set_position(-1);
	}

	return false;
}

void SignalHandler::toggle_search() {
	LOG("--> \"toggle_search\" emmited");
	this->widgets->main.search_entry->grab_focus();
}
