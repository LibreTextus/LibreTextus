#ifndef LIBRE_BOOK_MATRIX
#define LIBRE_BOOK_MATRIX

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <boost/multiprecision/cpp_int.hpp>

#include "primes/primes.hpp"

using namespace boost::multiprecision;

namespace Libre {
	class BookMatrix {
		private:
			std::map<std::string, unsigned long> words;
			std::vector<uint1024_t> matrix;
			Libre::Primes primes;
		public:
			BookMatrix(const std::string &);
			BookMatrix() = default;
			~BookMatrix() = default;
			void load_file(const std::string &);
			const std::map<std::string, unsigned long> & get_words();
			bool verse_has_word(const std::string &, const size_t &);
	};
}

#endif
