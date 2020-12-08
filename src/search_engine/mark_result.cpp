#include "search_engine.hpp"

void SearchEngine::mark_result(const std::string & position, std::string * text) {
	boost::regex e;
	if (!this->search_argument.get_regex_string().empty()) {
		e = boost::regex(this->search_argument.get_regex_string(), boost::regex::icase);
		*text = boost::regex_replace(*text, e, this->mark_argument);
	}
	
	for(const std::string & strong : this->search_argument.get_strongs()) {
		Libre::StrongMap * s_m = this->source_handler.get_strongs(this->file_path);

		tsl::ordered_map<std::string, std::string>::iterator i = std::find_if(
				(*s_m)[position].begin(), (*s_m)[position].end(),
			[&](const auto & i) {
					return i.second == strong;
		});

		if (i != (*s_m)[position].end()) {
				e = boost::regex("((?<=[^\\w\u00C0-\uffff])|\\A)" + i.key() + "(?=[^\\w\u00C0-\uffff]|$)", boost::regex::icase);

				*text = boost::regex_replace(*text, e, this->mark_argument);
		}
	}
}
