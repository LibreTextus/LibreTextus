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
	float progress = 0;

	for (float & i : this->thread_progress) {
		progress += i;
	}

	return progress / this->num_threads;
}

