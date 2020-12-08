#include "xml_converter.hpp"

Libre::XMLConverter::XMLConverter(const Libre::BookMap & book_map) : num_verses(0) {

	std::vector<std::string> verse_words;
	std::string verse;

	std::string b;

	for (Libre::BookMap::const_iterator i = book_map.begin(); i != book_map.end(); ++i) {
		verse = i->second;
		verse_words.clear();

		if (i->first.substr(0, 3) != b) {
			b = i->first.substr(0, 3);
		}

		std::transform(verse.begin(), verse.end(), verse.begin(), [](char c) { return std::tolower(c); });
		this->split_string(verse, &verse_words);

		this->verses.push_back(verse_words);

		for (std::string & w : verse_words) {
			this->word_idx[w] += 1;
		}
	}

	this->primes.generate(word_idx.size());

	std::map<unsigned long, std::vector<std::string>> inv_word_idx;

	for (const std::pair<std::string, unsigned long> & i : this->word_idx) {
		inv_word_idx[i.second].push_back(i.first);
	}

	size_t n = 0;
	for (auto i = inv_word_idx.rbegin(); i != inv_word_idx.rend(); ++i) {
		for (const std::string & j : i->second) {
			this->sorted_words.push_back(j);
			this->word_idx[j] = this->primes.get_prime(n);
			++n;
		}
	}

}

void Libre::XMLConverter::split_string(const std::string & line, std::vector<std::string> * v) {
	std::string::const_iterator b = line.begin();
	std::string::const_iterator e = line.begin();

	while (true) {
		for (; this->is_word(*e) && e != line.end(); ++e) {}

		v->push_back(std::string(b, e));

		while (!this->is_word(*e) && e != line.end()) { ++e; }

		if (e == line.end())
			break;

		b = e;
	}
}

void Libre::XMLConverter::save_to_file(const std::string & path) {
	std::ofstream f(path);

	for (const std::string & i : this->sorted_words) {
		f << i << ' ';
	}

	f << '\n';

	for (const std::vector<std::string> & i : this->verses) {
		uint2048_t word_id = 1;

		for (const std::string & s : i) {
				if (word_id > word_id * uint2048_t(this->word_idx[s]))
					std::cerr << "Generating Index: Overflow\n";
				word_id *= this->word_idx[s];
		}

		f << word_id << '\n';
	}

	f.close();

}

bool Libre::XMLConverter::is_word(const wchar_t c) {
	return (c > 0x40 && c < 0x5b) || (c > 0x60 && c < 0x7b) || (c > 0xbf);
}
