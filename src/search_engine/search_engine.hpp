#ifndef SEARCH_ENGINE_HPP
#define SEARCH_ENGINE_HPP

#include <string>
#include <iostream>
#include <boost/regex.hpp>
#include <boost/regex/icu.hpp>
#include <vector>
#include <queue>
#include <algorithm>
#include <locale>
#include <codecvt>
#include <mutex>
#include <shared_mutex>
#include <thread>

#include <source_handler/source_handler.hpp>
#include <tsl/ordered_map.h>

#include "search_argument/search_argument.hpp"
#include "source_handler/book_map.hpp"

class SearchEngine {
private:
	Libre::BookMap * file;
	Libre::BookMatrix * matrix;
	Libre::StrongMap * strongs;
	std::string file_path;
	Libre::NameMap * names;
	SourceHandler source_handler;
	std::vector<std::string> last_search_results;
	Libre::SearchArgument search_argument;
	std::string raw_search_argument;
	std::string mark_argument;
	size_t search_distance;
	size_t search_progress;
	mutable std::mutex * mutex;
	std::vector<std::thread *> threads;
	typedef std::priority_queue<std::pair<size_t, std::string>, std::vector<std::pair<size_t, std::string>>, std::greater<std::pair<size_t, std::string>>> result_queue;
	result_queue thread_results;
	size_t scroll_overflow;

	void interpret_string(const std::string &);
	void interpret_argument(std::string);
	void mark_result(const std::string &, std::string * text);

	void remove_unneeded_spaces(std::string *);
	void cancel_out_regex_characters(std::string *);
	void create_placeholders(std::string *, std::vector<std::string> *);
	void add_boundries(std::string *);
	void replace_any_character_expression(std::string *);
	void replace_and_expression(std::string *);
	void replace_placeholders_with_argument(std::string *, std::vector<std::string> *);
	void remove_quotes(std::string *);
	void pop_strong_expressions(std::string *);
	void create_search_index(const std::string &);

	void split_position_and_argument(std::string *, std::string *);
	void replace_book_names(std::string *);
	void remove_spaces_from_argument(std::string *);
	void get_position_from_string(std::string *, std::vector<std::array<std::string, 2>> *);
	bool validate_positions(std::vector<std::array<std::string, 2>> *);
	void thread_search(size_t i);
	void calc_distance();

public:
	SearchEngine (const std::string & path);
	virtual ~SearchEngine() {}

	bool search(std::string * arg); 
	void set_search_argument(std::string arg);
	void set_mark_argument(std::string arg);
	void set_source(std::string path);
	float get_progress();
	size_t get_scroll_overflow();
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
