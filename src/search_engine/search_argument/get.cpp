#include "search_argument.hpp"


uint2048_t Libre::SearchArgument::get_idx() {
	return this->search_idx;
}

const std::string & Libre::SearchArgument::get_regex_string() {
	return this->regex_string;
}

const std::vector<std::array<Libre::BookMap::iterator, 2>> & Libre::SearchArgument::get_position() {
	return this->positions;
}

const std::vector<std::string> & Libre::SearchArgument::get_words() {
	return this->words;
}

const std::vector<std::string> & Libre::SearchArgument::get_strongs() {
	return this->strongs;
}

const std::vector<std::string> & Libre::SearchArgument::get_snippets() {
	return this->snippets;
}

const std::map<std::string, std::vector<uint2048_t>> & Libre::SearchArgument::get_possible_idx() {
	return this->possible_idx;
}
