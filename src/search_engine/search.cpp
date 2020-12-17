#include "search_engine.hpp"
#include <thread>

bool SearchEngine::search(std::string * text) {
	boost::regex e;
	boost::smatch m;

	const std::vector<std::array<Libre::BookMap::iterator, 2>> & pos = this->search_argument.get_position();
	
	while (this->search_iterator != pos.back().back()) {

		bool is_search_for = false;
		if (this->search_argument.get_idx() != 0) {
			is_search_for = this->matrix->verse_has_mod_index(this->search_argument.get_idx(), this->search_verse_number);
		}

		if (!this->search_argument.get_possible_idx().empty() && is_search_for) {
			for (const std::pair<std::string, std::vector<uint2048_t>> & pidx : this->search_argument.get_possible_idx()) {
				bool has_one_of_possibles = false;
				for (const uint2048_t & idx : pidx.second) {
					if (this->matrix->verse_has_mod_index(idx, this->search_verse_number)) {
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
				for (const std::pair<std::string, std::string> & p : (*this->strongs)[this->search_iterator.key()]) {
					if (p.second == strong) {
						has_strong = true;
						break;
					}
				}

				if (!has_strong) {
					strong_check = false;
					break;
				}
			}

			if (strong_check) {
				this->last_search_results.push_back(this->search_iterator.key());
				*text = this->search_iterator.value();
				this->mark_result(this->search_iterator.key(), text);

				++this->search_progress;
				++this->search_verse_number;
				++this->search_iterator;
				if (this->search_iterator != pos.back().back()) {
					if (this->search_iterator == pos[this->search_position_index][1]) {
						++search_position_index;
						this->search_iterator = pos[this->search_position_index][0];
					}
				}

				return true;
			}
		}

		++this->search_progress;
		++this->search_verse_number;
		++this->search_iterator;
		if (this->search_iterator != pos.back().back()) {
			if (this->search_iterator == pos[this->search_position_index][1]) {
				++search_position_index;
				this->search_iterator = pos[this->search_position_index][0];
			}
		}
	}

	return false;
}
