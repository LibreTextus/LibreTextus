#include "../search_engine.hpp"

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
	bool file_is_not_empty = this->file->size() > 0;
	if (file_is_not_empty) {
		return static_cast<float>(std::distance(this->file->begin(), this->active_verse)) / this->file->size();
	}

	return 0;
}

