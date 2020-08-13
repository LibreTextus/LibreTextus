#ifndef SEARCH_ENGINE_HPP
#define SEARCH_ENGINE_HPP

#include <string>
#include <iostream>
#include <boost/regex.hpp>
#include <boost/regex/icu.hpp>
#include <vector>
#include <algorithm>
#include <locale>

#include <source_handler.hpp>
#include <tsl/ordered_map.h>

class SearchEngine {
private:
	Libre::BookMap * file;
	std::string file_path;
	Libre::NameMap * names;
	Libre::BookMap::iterator active_verse;
	int active_verse_index;
	SourceHandler source_handler;
	std::vector<std::string> last_search_results;
	std::string search_argument;
	std::vector<std::string> search_argument_vector;
	std::string raw_search_argument;
	std::string mark_argument;
	std::vector<std::array<Libre::BookMap::iterator, 2>> positions;

	void interpret_string();
	void interpret_argument(std::string * text);
	void mark_result(std::string * text);

	void remove_unneeded_spaces(std::string *);
	void cancel_out_regex_characters(std::string *);
	void create_placeholders(std::string *, std::vector<std::string> *);
	void add_boundries(std::string *);
	void replace_any_character_expression(std::string *);
	void replace_and_expression(std::string *);
	void replace_placeholders_with_argument(std::string *, std::vector<std::string> *);
	void shorten_strong_expression(std::string *);
	void remove_quotes(std::string *);

	void split_position_and_argument(std::string *, std::string *);
	void replace_book_names(std::string *);
	void remove_spaces_from_argument(std::string *);
	void get_position_from_string(std::string *, std::vector<std::array<std::string, 2>> *);
	bool validate_positions(std::vector<std::array<std::string, 2>> *);
	void create_search_vector_from_string();

	void jump_to_next_range_if_end();
	bool does_verse_contain_match();

public:
	SearchEngine (const std::string & path);
	virtual ~SearchEngine() {}

	bool search(std::string * arg); 
	void set_search_argument(std::string arg);
	void set_mark_argument(std::string arg);
	void set_source(std::string path);
	float get_progress();
	std::string * get_verse(std::string p);

	std::vector<std::string> * get_last_search_results() {
		return &this->last_search_results;
	}

	void set_last_search_result(std::vector<std::string> & v) {
		this->last_search_results = v;
	}

	std::string & get_search_argument() {
		return this->raw_search_argument;
	}
};

#endif