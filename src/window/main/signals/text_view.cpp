#include "../main.hpp"

void Libre::MainWindow::set_text() {

	this->mutex.lock();

	this->search_section.get_search_entry()->set_progress_fraction(this->search_engine[0].get_progress());

	if (this->replace_id == -1) {
		this->view_pane.get_text_view()->add_verse(
			this->found_position,
			this->found_verses
		);
	} else {
		this->view_pane.get_text_view()->replace_verse(
			this->found_position,
			this->replace_id,
			this->found_verses.back()
		);
	}

	this->process_finished = true;

	this->mutex.unlock();
}

