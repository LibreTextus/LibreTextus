#include "book_matrix.hpp"

Libre::BookMatrix::BookMatrix(const std::string & path) {
	this->load_file(path);
}

void Libre::BookMatrix::load_file(const std::string & path) {
	std::ifstream f(path);
	std::string wordlist;
	std::string wmatrix;
	std::string l;

	std::cout << "Get Wordlist\n";

	getline(f, wordlist);

	std::cout << "Parse Wordlist\n";
	std::string::iterator b = wordlist.begin(), e = wordlist.begin();

	bool running = true;

	while (running) {
		for (; e != wordlist.end() && *e != ' '; ++e) {}
		this->words[std::string(b, e)] = this->words.size();

		if (e == wordlist.end()) {
			running = false;
		}

		b = ++e;
	}

	std::cout << "Get Matrix\n";

	while(getline(f, l)) {
		wmatrix += l;
	}

	std::cout << "Parse Matrix\n";

	size_t num_lines = wmatrix.size() * 8 / this->words.size();

	for (int i = 0; i < num_lines; i += wmatrix.size()) {
		this->matrix.push_back(wmatrix.substr(i / 8, words.size()));
	}

	std::cout << "BookMatrix Finished\n";

	f.close();
}

const std::map<std::string, unsigned> & Libre::BookMatrix::get_words() {
	return this->words;
}

bool Libre::BookMatrix::get_cell(const std::string & w, const size_t & l) {
	return this->matrix[l][this->words[w] / 8 + (this->words[w] % 8)];
}
