#include "text_view.hpp"

bool Libre::TextView::note_exists(const std::string & pos) {
	for (rapidxml::xml_node<> * note = this->note_book_file->first_node("note"); note; note = note->next_sibling()) {
		if (note->first_attribute("name")->value() == pos) {
			return true;
		}
	}

	return false;
}
