#ifndef LIBRE_BOOK_MATRIX
#define LIBRE_BOOK_MATRIX

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <fstream>

namespace Libre {
	class BookMatrix {
		private:
			std::map<std::string, unsigned> words;
			std::vector<std::string> matrix;
		public:
			BookMatrix(const std::string &);
			BookMatrix() = default;
			~BookMatrix() = default;
			void load_file(const std::string &);
			const std::map<std::string, unsigned> & get_words();
			bool get_cell(const std::string &, const size_t &);
	};
}

#endif
