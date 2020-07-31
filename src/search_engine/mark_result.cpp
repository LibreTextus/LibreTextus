#include "../search_engine.hpp"

void SearchEngine::mark_result(std::string * text) {
	boost::regex e;
	Libre::StrongMap * s_m = this->source_handler.get_strongs(this->file_path);
	
	for(int i = 0; i < this->search_argument_vector.size(); i++) {
		
		bool is_strong = this->search_argument_vector[i].front() == '[' && this->search_argument_vector[i].back() == ']';
		if (is_strong) {
			for (tsl::ordered_map<std::string, std::string>::iterator it = (*s_m)[this->active_verse.key()].begin(); it != (*s_m)[this->active_verse.key()].end(); it++) {
				if (this->search_argument_vector[i].substr(1, this->search_argument_vector[i].size() - 2) == it.value()) {
					e = boost::regex("((?<=[^\\w\u00C0-\uffff])|\\A)" + it.key() + "(?=[^\\w\u00C0-\uffff]|$)", boost::regex::icase);
					break;
				}
			}
		} else {
			e = boost::regex(this->search_argument_vector[i], boost::regex::icase);
		}

		*text = boost::regex_replace(*text, e, this->mark_argument);
	}
}
