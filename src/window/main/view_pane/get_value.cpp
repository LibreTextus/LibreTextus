#include "view_pane.hpp"

Libre::TextView * Libre::ViewPane::get_text_view() {
	return &this->text_view;
}

Libre::NoteBook * Libre::ViewPane::get_notebook() {
	return &this->notebook;
}
