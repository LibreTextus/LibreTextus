#include "../main.hpp"

void Libre::MainWindow::do_search() {

	this->search_engine[0].set_search_argument(this->search_section.get_search_entry()->get_text());

	this->view_pane.get_text_view()->scroll_to(this->search_engine.front().get_scroll_overflow());

	this->found_verses.push_back(new std::string(""));

	while (this->search_engine[0].search(this->found_verses[0])) {

		this->mutex.lock();

		this->found_position = this->search_engine[0].get_last_search_results()->back();

		for (int i = 1; i < this->search_engine.size(); i++) {
			this->found_verses.push_back(this->search_engine[i].get_verse(this->found_position));
		}

		this->process_finished = false;

		this->mutex.unlock();

		this->set_text_dispatcher.emit();

		while (!this->process_finished) { std::this_thread::yield(); }

		this->mutex.lock();

		this->search_section.get_search_entry()->set_progress_fraction(this->search_engine[0].get_progress());

		for (int i = 0; i < this->found_verses.size(); ++i) {
			delete this->found_verses[i];
		}

		this->found_verses.clear();

		this->found_verses.push_back(new std::string(""));

		this->mutex.unlock();
	}

	for (int i = 0; i < this->found_verses.size(); ++i) {
		delete this->found_verses[i];
	}
	this->found_verses.clear();


	this->join_thread_dispatcher.emit();
}

void Libre::MainWindow::trigger_search(const std::string & text) {

	this->search_section.get_search_entry()->set_text(text);

	this->search_section.get_number_result_label()->set_text(_("Searching"));

	this->set_sensitive(false);

	this->view_pane.get_text_view()->clear();
	this->view_pane.get_text_view()->show_content();
	this->view_pane.get_text_view()->grab_focus();

	this->replace_id = -1;

	this->process_thread = new std::thread(&Libre::MainWindow::do_search, this);
	LOG("--> \"do_search\" emmited");
}

void Libre::MainWindow::trigger_search_with_history(const std::string & text) {
		this->search_section.get_history_button()->add_to_history(text);
		this->trigger_search(text);
}
