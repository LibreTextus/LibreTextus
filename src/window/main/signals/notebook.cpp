#include "../main.hpp"

void Libre::MainWindow::toggle_note(const std::string & position) {
	LOG("--> \"toggle_note\" emmited");
	if (position == "") {
		this->view_pane.set_position(this->view_pane.get_height());
		this->view_pane.get_notebook()->save_note();
		this->view_pane.get_text_view()->grab_focus();
	} else {
		this->view_pane.set_position(this->view_pane.get_height() * 2 / 3);
		this->view_pane.get_notebook()->open_note(position);
		this->view_pane.get_notebook()->grab_focus();
	}
}

