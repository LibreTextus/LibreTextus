#include "../signal_handler.hpp"

void SignalHandler::toggle_note(std::string position) {
	LOG("--> \"toggle_note\" emmited");
	if (position == "") {
		this->widgets->main.note_paned->set_position(this->widgets->main.note_paned->get_height());
		this->widgets->main.note_book->save_note();
		this->widgets->main.text_view->grab_focus();
	} else {
		if (this->widgets->main.note_paned->get_position() > this->widgets->main.note_paned->get_height() - 50) {
			this->widgets->main.note_paned->set_position(this->widgets->main.note_paned->get_height() * 2 / 3);
		}
		this->widgets->main.note_book->open_note(position);
		this->widgets->main.note_book->grab_focus();
	}
}

