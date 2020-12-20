#include "../main.hpp"

void Libre::MainWindow::join_thread() {

	this->process_thread->join();

	if (this->search_section.get_search_entry()->get_progress_fraction() != 0) {
		this->search_section.get_search_entry()->set_progress_fraction(0);
	}

	this->search_section.get_number_result_label()->set_text(
			std::to_string(this->search_engine[0].get_last_search_results()->size()) + " " + _("Results"));

	this->view_pane.get_text_view()->show_if_results();

	this->set_sensitive(true);

	if (this->search_engine[0].get_last_search_results()->size() == 0) {
		this->search_section.get_search_entry()->grab_focus();
	} else {
		this->view_pane.get_text_view()->grab_focus();
	}
}


