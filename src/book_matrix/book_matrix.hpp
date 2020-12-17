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
typedef number<cpp_int_backend<2048, 2048, unsigned_magnitude, unchecked, void>> uint2048_t;

namespace Libre {
	class BookMatrix {
		private:
			std::map<std::string, uint2048_t> words;
			std::vector<uint2048_t> matrix;
			Libre::Primes primes;
		public:
			BookMatrix(const std::string &);
			BookMatrix() = default;
			~BookMatrix() = default;
			void load_file(const std::string &);
			const std::map<std::string, uint2048_t> & get_words();
			bool verse_has_word(const std::string &, const size_t &);
			bool verse_has_mod_index(const uint2048_t &, const size_t &);
	};
}

#endif
