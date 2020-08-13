#include "signal_handler.hpp"

void SignalHandler::do_search() {

	this->widgets->search_engine[0].set_search_argument(this->widgets->main.search_entry->get_text());

	this->widgets->processing.found_verses.clear();
	this->widgets->processing.found_verses.push_back(new std::string(""));

	while (this->widgets->search_engine[0].search(this->widgets->processing.found_verses[0])) {

		this->widgets->processing.process_mutex.lock();

		this->widgets->processing.found_position = this->widgets->search_engine[0].get_last_search_results()->back();

		for (int i = 1; i < this->widgets->search_engine.size(); i++) {
			this->widgets->processing.found_verses.push_back(this->widgets->search_engine[i].get_verse(this->widgets->processing.found_position));
		}

		this->widgets->processing.procress_finished = false;

		this->widgets->processing.process_mutex.unlock();

		this->widgets->processing.set_text_dispatcher.emit();

		while (!this->widgets->processing.procress_finished) { std::this_thread::yield(); }

		this->widgets->processing.process_mutex.lock();

		this->widgets->main.search_entry->set_progress_fraction(this->widgets->search_engine[0].get_progress());

		this->widgets->processing.found_verses.clear();
		this->widgets->processing.found_verses.push_back(new std::string(""));

		this->widgets->processing.process_mutex.unlock();
	}

	this->widgets->processing.delete_thread_dispatcher.emit();
}

void SignalHandler::trigger_search(const std::string & text) {

	this->widgets->main.search_entry->set_text(text);

	this->widgets->main.number_results->set_text(_("Searching"));

	this->disable_widgets();

	this->widgets->main.text_view->clear();
	this->widgets->main.text_view->show_content();
	this->widgets->main.text_view->grab_focus();

	this->widgets->processing.replace_id = -1;

	this->widgets->processing.process_thread = Glib::Thread::create(
		sigc::mem_fun(*this, &SignalHandler::do_search), true
	);
	LOG("--> \"do_search\" emmited");
}

void SignalHandler::trigger_search_with_history(const std::string & text) {
		this->widgets->main.history_button->add_to_history(text);
		this->trigger_search(text);
}
