#include "../main.hpp"

void Libre::MainWindow::do_replacement() {
	this->change_source_at_replace_id();
	std::vector<std::string> * v = this->search_engine[0].get_last_search_results();

	int progress = 0;

	this->found_verses.clear();

	for (std::vector<std::string>::iterator i = v->begin(); i != v->end() && v->size() != 0; i++) {

		this->mutex.lock();

		this->process_finished = false;
		this->found_verses.push_back(this->search_engine[this->replace_id].get_verse(*i));
		this->found_position = *i;

		this->mutex.unlock();

		this->set_text_dispatcher.emit();

		while (!this->process_finished) { std::this_thread::yield(); }

		progress++;
		this->mutex.lock();
		this->search_section.get_search_entry()->set_progress_fraction(progress / static_cast<float>(v->size()));
		this->mutex.unlock();
	}

	this->join_thread_dispatcher.emit();
}

void Libre::MainWindow::change_source_at_replace_id() {
	std::string source_name = (*this->header.get_elements())[this->replace_id]->get_combo()->get_active_text();
	std::string source_path = this->package_manager->get_source_path(source_name);

	this->search_engine[this->replace_id].set_source(source_path);

	this->view_pane.get_text_view()->change_source(this->replace_id, source_path);
}
