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

		if (!this->search_argument.get_snippets().empty()) {
			for (const std::string regex : this->search_argument.get_snippets()) {
				e = regex;
				is_search_for &= boost::regex_search(regex, m, e);
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
				e = this->search_argument.get_regex_string();
				bool regex_check = boost::regex_search(this->search_iterator.value(), m, e);

				if (regex_check) {
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
