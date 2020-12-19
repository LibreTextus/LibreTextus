#include "search_engine.hpp"
#include <stdexcept>

bool SearchEngine::search(std::string * text) {

	for (int i = 0; i < std::thread::hardware_concurrency(); ++i) {
		if (this->threads[i] != nullptr) {
			this->threads[i]->join();
			delete this->threads[i];
			this->threads[i] = nullptr;
		}
	}

	this->search_distance = this->thread_results.size();

	if (!this->thread_results.empty()) {
		std::string verse = this->thread_results.begin()->second;
		this->thread_results.erase(this->thread_results.begin());

		this->last_search_results.push_back(verse);
		*text = this->file->at(verse);
		this->mark_result(verse, text);

		++this->search_progress;
		return true;
	}

	this->threads.clear();

	delete this->mutex;

	return false;
}

void SearchEngine::thread_search(size_t id) {

	const std::vector<std::array<Libre::BookMap::iterator, 2>> & pos = this->search_argument.get_position();

	Libre::BookMap::iterator search_iterator = pos.front().front();

	size_t search_verse_number = 0;
	size_t search_position_index = 0;

	for (int i = 0; i < id; ++i) {
		++search_verse_number;
		++search_iterator;
		if (search_iterator != pos.back().back()) {
			if (search_iterator == pos[search_position_index][1]) {
				++search_position_index;
				search_iterator = pos[search_position_index][0];
				search_verse_number = std::distance(this->file->begin(), search_iterator);
			}
		} else {
			return;
		}
	}
	
	while (search_iterator != pos.back().back()) {

		bool is_search_for = false;
		if (this->search_argument.get_idx() != 0) {
			is_search_for = this->matrix->verse_has_mod_index(this->search_argument.get_idx(), search_verse_number);
		}

		if (!this->search_argument.get_possible_idx().empty() && is_search_for) {
			for (const std::pair<std::string, std::vector<uint2048_t>> & pidx : this->search_argument.get_possible_idx()) {
				bool has_one_of_possibles = false;
				for (const uint2048_t & idx : pidx.second) {
					if (this->matrix->verse_has_mod_index(idx, search_verse_number)) {
						has_one_of_possibles = true;
						break;
					}
				}

				if (!has_one_of_possibles) {
					is_search_for = false;
					break;
				}
			}
		}

		if (is_search_for) {

			bool strong_check = true;

			for (const std::string & strong : this->search_argument.get_strongs()) {
				bool has_strong = false;
				try {
					for (const std::pair<std::string, std::string> & p : this->strongs->at(search_iterator.key())) {
						if (p.second == strong) {
							has_strong = true;
							break;
						}
					}
				} catch (std::out_of_range &) {}

				if (!has_strong) {
					strong_check = false;
					break;
				}
			}

			if (strong_check) {
				{
					std::lock_guard<std::mutex> lock(*this->mutex);
					this->thread_results[search_verse_number] = search_iterator.key();
				}
			}
		}

		for (int i = 0; i < std::thread::hardware_concurrency(); ++i) {
			++search_verse_number;
			++search_iterator;
			if (search_iterator != pos.back().back()) {
				if (search_iterator == pos[search_position_index][1]) {
					++search_position_index;
					search_iterator = pos[search_position_index][0];
					search_verse_number = std::distance(this->file->begin(), search_iterator);
				}
			} else {
				return;
			}
		}
	}
}
