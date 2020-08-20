#include "../main.hpp"

gboolean Libre::MainWindow::search_request(GdkEventKey * event) {
	LOG("--> \"search_request\" emmited");

	if (event->keyval == GDK_KEY_Return) {

		if (this->search_section.get_search_entry()->get_text() == "") {
			this->view_pane.get_text_view()->show_information();
			this->view_pane.get_text_view()->clear();
			this->search_engine[0].set_search_argument("");
			return false;
		}

		std::string text = this->search_section.get_search_entry()->get_text();
		this->trigger_search_with_history(text);

	} else if (event->keyval == 65307) {
		this->view_pane.get_text_view()->grab_focus();
		this->search_section.get_search_entry()->set_position(-1);
	}

	return false;
}

void Libre::MainWindow::toggle_search() {
	LOG("--> \"toggle_search\" emmited");
	this->search_section.get_search_entry()->grab_focus();
}
