#ifndef LIBRE_SEARCH_ENGINE_ARGUMENT
#define LIBRE_SEARCH_ENGINE_ARGUMENT

#include <vector>
#include <map>
#include <array>
#include <string>
#include <boost/multiprecision/cpp_int.hpp>

#include <source_handler/source_handler.hpp>

using namespace boost::multiprecision;

namespace Libre {
	class SearchArgument {
		private:
			uint2048_t search_idx;
			std::string regex_string;
			std::vector<std::array<Libre::BookMap::iterator, 2>> positions;
			std::vector<std::string> words;
			std::vector<std::string> strongs;
			std::vector<std::string> snippets;
			std::map<std::string, std::vector<uint2048_t>> possible_idx;
		public:
			SearchArgument() = default;
			~SearchArgument() = default;
			const std::vector<std::array<Libre::BookMap::iterator, 2>> & get_position();
			void add_positions(const std::array<Libre::BookMap::iterator, 2> &);
			void set_idx(const uint2048_t &);
			uint2048_t get_idx();
			void set_regex_string(const std::string &);
			const std::string & get_regex_string();
			void append_word(const std::string &);
			const std::vector<std::string> & get_words();
			void append_strong(const std::string &);
			const std::vector<std::string> & get_strongs();
			void append_snippet(const std::string &);
			const std::vector<std::string> & get_snippets();
			void append_possible_idx(const std::string &, const uint2048_t &);
			const std::map<std::string, std::vector<uint2048_t>> & get_possible_idx();
			void clear();
	};
}

#endif
