#include "../main.hpp"


void Libre::MainWindow::source_changed(Libre::HeaderElement * e) {

	LOG("--> \"source_changed\" emmited");

	if (!this->process_finished) {
		return;
	}

	this->set_sensitive(false);
	this->view_pane.get_text_view()->grab_focus();

	this->set_replace_id(e);

	this->process_thread = new std::thread(&Libre::MainWindow::do_replacement, this);
	LOG("--> \"do_replacement\" emmited");
}

void Libre::MainWindow::set_replace_id(Libre::HeaderElement * e) {
	this->replace_id = 0;

	for (;this->replace_id < this->header.get_elements()->size(); this->replace_id++) {
		if (e == (*this->header.get_elements())[this->replace_id]) {
			break;
		}
	}
}
