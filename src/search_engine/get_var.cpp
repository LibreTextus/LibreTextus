#include "search_engine.hpp"

std::string * SearchEngine::get_verse(std::string p) {
	bool is_not_end_of_file = this->file->find(p) != this->file->end();
	if (is_not_end_of_file) {
		return &(*this->file)[p];
	}
	else {
		return nullptr;
	}
}

float SearchEngine::get_progress() {
	return static_cast<float>(this->search_progress) / this->search_distance;
}

size_t SearchEngine::get_scroll_overflow() {
	return this->scroll_overflow;
}
