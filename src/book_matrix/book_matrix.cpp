#include "book_matrix.hpp"

Libre::BookMatrix::BookMatrix(const std::string & path) {
	this->load_file(path);
}

void Libre::BookMatrix::load_file(const std::string & path) {
	std::ifstream f(path);
	std::string wordlist;
	std::string wmatrix;
	std::string l;

	getline(f, wordlist);

	while (getline(f, l)) {
		wmatrix += l;
	}

	std::string::iterator b = wordlist.begin();
	std::string::iterator e = wordlist.begin();

	while (true) {
		for (;*e != ' ' && e != wordlist.end(); ++e) {}
		this->words.push_back(std::string(b, e));

		if (e == wordlist.end()) {
			break;
		}

		b = ++e;
	}

	size_t num_lines = matrix.size() * 8 / this->words.size();

	for (int i = 0; i < this->words.size(); ++i) {
		this->matrix[this->words[i]] = std::vector<bool>(num_lines, false);
	}

	size_t pos = 0;

	for (int i = 0; i < num_lines; ++i) {
		for (int j = 0; j < this->words.size(); ++j) {
			this->matrix[this->words[j]][i] = wmatrix[pos / 8] & (1 << (pos % 8));
			pos++;
		}
	}

	f.close();
}

const std::vector<std::string> & Libre::BookMatrix::get_words() {
	return this->words;
}

bool Libre::BookMatrix::get_cell(const std::string & w, const size_t & l) {
	return this->matrix[w][l];
}
