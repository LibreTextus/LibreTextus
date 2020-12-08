#include "search_argument.hpp"

void Libre::SearchArgument::set_idx(uint2048_t i) {
	this->search_idx = i;
}

void Libre::SearchArgument::set_regex_string(const std::string & reg) {
	this->regex_string = reg;
}

void Libre::SearchArgument::clear() {
	this->search_idx = 0;
	this->strongs.clear();
	this->words.clear();
	this->positions.clear();
	this->regex_string.clear();
}

void Libre::SearchArgument::add_positions(const std::array<Libre::BookMap::iterator, 2> & p) {
	this->positions.push_back(p);
}

void Libre::SearchArgument::append_word(const std::string & w) {
	this->words.push_back(w);
}

void Libre::SearchArgument::append_strong(const std::string & s) {
	this->strongs.push_back(s);
}
