#include "search_section.hpp"

Libre::HistoryButton * Libre::SearchSection::get_history_button() {
	return &this->history_button;
}

Gtk::SearchEntry * Libre::SearchSection::get_search_entry() {
	return &this->search_entry;
}

Gtk::Label * Libre::SearchSection::get_number_result_label() {
	return &this->number_results;
}
