#ifndef LIBRE_BOOK_MATRIX
#define LIBRE_BOOK_MATRIX

#include <vector>
#include <map>
#include <string>
#include <fstream>

namespace Libre {
	class BookMatrix {
		private:
			std::vector<std::string> words;
			std::map<std::string, std::vector<bool>> matrix;
		public:
			BookMatrix(const std::string &);
			~BookMatrix() = default;
			const std::vector<std::string> & get_words();
			bool get_cell(const std::string &, const size_t &);
	};
}

#endif
