#include "signal_handler.hpp"

void SignalHandler::do_replacement() {

	this->change_source_at_replace_id();
	std::vector<std::string> * v = this->widgets->search_engine[0].get_last_search_results();

	int progress = 0;

	this->widgets->processing.found_verses.clear();

	for (std::vector<std::string>::iterator i = v->begin(); i != v->end() && v->size() != 0; i++) {

		this->widgets->processing.process_mutex.lock();

		this->widgets->processing.procress_finished = false;
		this->widgets->processing.found_verses.push_back(this->widgets->search_engine[this->widgets->processing.replace_id].get_verse(*i));
		this->widgets->processing.found_position = *i;

		this->widgets->processing.process_mutex.unlock();

		this->widgets->processing.set_text_dispatcher.emit();

		while (!this->widgets->processing.procress_finished) { std::this_thread::yield(); }

		progress++;
		this->widgets->processing.process_mutex.lock();
		this->widgets->main.search_entry->set_progress_fraction(progress / static_cast<float>(v->size()));
		this->widgets->processing.process_mutex.unlock();
	}

	this->widgets->processing.delete_thread_dispatcher.emit();
}

void SignalHandler::change_source_at_replace_id() {
	std::string source_name = this->widgets->main.combo_boxes[this->widgets->processing.replace_id]->get_active_text();
	std::string source_path = this->widgets->package_manager.get_source_path(source_name);

	this->widgets->search_engine[this->widgets->processing.replace_id].set_source(source_path);

	this->widgets->main.text_view->change_source(this->widgets->processing.replace_id, source_path);
}
