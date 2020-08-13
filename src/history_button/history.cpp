#include "history_button.hpp"

void Libre::HistoryButton::add_to_history(std::string arg) {
	this->active_search++;
	this->remove_words_after_active_search();
	this->search_history.push_back(arg);
}

void Libre::HistoryButton::remove_words_after_active_search() {
	if (this->active_search != this->search_history.size()) {
		while (this->active_search != this->search_history.size()) {
			this->search_history.pop_back();
		}
	}
}
