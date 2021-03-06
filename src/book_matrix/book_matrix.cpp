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

	std::string::iterator b = wordlist.begin(), e = wordlist.begin();

	bool running = true;

	size_t n_words = 1;
	for (const char & i: wordlist) {
		if (i == ' ')
			++n_words;
	}

	this->primes.generate(n_words);

	size_t n = 0;
	while (running) {
		for (; e != wordlist.end() && *e != ' '; ++e) {}
		this->words[std::string(b, e)] = this->primes.get_prime(n);

		if (e == wordlist.end()) {
			running = false;
		}

		b = ++e;
		++n;
	}

	while (getline(f, l)) {
		this->matrix.push_back(uint2048_t(l));
	}

	f.close();
}

const std::map<std::string, uint2048_t> & Libre::BookMatrix::get_words() {
	return this->words;
}

bool Libre::BookMatrix::verse_has_word(const std::string & w, const size_t & l) {
	return this->matrix[l] % this->words[w] == 0;
}

bool Libre::BookMatrix::verse_has_mod_index(const uint2048_t & idx, const size_t & verse) {
	return this->matrix[verse] % idx == 0;
}
