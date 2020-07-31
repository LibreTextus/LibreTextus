#include "../search_engine.hpp"

bool SearchEngine::search(std::string * text) {


	while (this->active_verse != this->positions.back()[1]) {
		this->jump_to_next_range_if_end();

		bool found = this->does_verse_contain_match();
		bool only_want_range = this->search_argument == "";

		if (found || only_want_range) {

			*text = this->active_verse.value();

			if (this->search_argument != "") {
				this->mark_result(text);
			}

			this->last_search_results.push_back(this->active_verse->first);

			this->active_verse++;

			return true;
		}
		this->active_verse++;
	}

	return false;
}


void SearchEngine::jump_to_next_range_if_end() {
	if (this->active_verse == this->positions[this->active_verse_index][1]) {
			this->active_verse_index++;
			this->active_verse = this->positions[this->active_verse_index][0];
		}
}

bool SearchEngine::does_verse_contain_match() {
	boost::regex e("", boost::regex::icase);
	bool found = true;

	for(int i = 0; i < this->search_argument_vector.size(); i++) {
		if (this->search_argument_vector[i].front() == '[' && this->search_argument_vector[i].back() == ']') {
			Libre::StrongMap * s_m = this->source_handler.get_strongs(this->file_path);
			bool found_str = false;

			for (tsl::ordered_map<std::string, std::string>::iterator it = (*s_m)[this->active_verse.key()].begin(); it != (*s_m)[this->active_verse.key()].end(); it++) {
				if(this->search_argument_vector[i].substr(1, this->search_argument_vector[i].size() - 2) == it->second) {
					found_str = true;
					break;
				}
			}

			found &= found_str;

		} else {
			e = boost::regex(this->search_argument_vector[i], boost::regex::icase);
			found &= boost::regex_search(this->active_verse.value(), e);
		}
	}

	return found;
}
