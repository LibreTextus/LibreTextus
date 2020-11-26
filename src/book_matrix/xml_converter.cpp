#include "xml_converter.hpp"

Libre::XMLConverter::XMLConverter(const std::string & path) : num_verses(0) {
	std::cout << "Load XML FILE\n";
	rapidxml::file<> xml_file(path.c_str());
	
	char * content = this->doc.allocate_string(xml_file.data());
	this->doc.parse<rapidxml::parse_no_data_nodes>(content);

	this->root = this->doc.first_node("XMLBIBLE")->first_node("BIBLEBOOK");


	std::cout << "Count num verses\n";

	for (rapidxml::xml_node<> * b = this->root; b; b = b->next_sibling()) {
		for (rapidxml::xml_node<> * c = b->first_node("CHAPTER"); c; c = c->next_sibling()) {
			for (rapidxml::xml_node<> * v = c->first_node("VERS"); v; v = v->next_sibling()) {
				this->num_verses++;
			}
		}
	}

	std::cout << "Parse File\n";

	std::vector<std::string> verse_words;
	std::wstring verse;

	for (rapidxml::xml_node<> * book = this->root; book; book = book->next_sibling()) {
		for (rapidxml::xml_node<> * ch = book->first_node("CHAPTER"); ch; ch = ch->next_sibling()) {
			for (rapidxml::xml_node<> * v = ch->first_node("VERS"); v; v = v->next_sibling()) {
				verse = converter.from_bytes(v->value());
				verse_words.clear();

				std::transform(verse.begin(), verse.end(), verse.begin(), [](wchar_t c) { return std::tolower(c); });
				this->split_string(verse, &verse_words);

				this->verses.push_back(verse_words);

				for (std::string & w : verse_words) {
					this->word_idx[w] += 1;
				}
			}
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

	std::cout << "End Parsing\n";
}

void Libre::XMLConverter::split_string(const std::wstring & line, std::vector<std::string> * v) {
	std::wstring::const_iterator b = line.begin();
	std::wstring::const_iterator e = line.begin();

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
	std::cout << "Save to file: " << path << '\n';
	std::ofstream f(path);

	std::cout << "Write wordlist\n";

	for (const std::string & i : this->sorted_words) {
		f << i << ' ';
	}

	f << '\n';

	std::cout << "Write Matrix\n";
	std::cout << "Number Verses " << this->num_verses << '\n';
	std::cout << "Number Words " << word_idx.size() << '\n';

	for (const std::vector<std::string> & i : this->verses) {
		uint1024_t word_id = 1;

		for (const std::string & s : i) {
				if (word_id > word_id * uint1024_t(this->word_idx[s]))
					std::cerr << "Generating Index: Overflow\n";
				word_id *= this->word_idx[s];
		}

		f << word_id << '\n';
	}

	f.close();

	std::cout << "End Writing\n";
}

bool Libre::XMLConverter::is_word(const wchar_t c) {
	return (c > 0x40 && c < 0x5b) || (c > 0x60 && c < 0x7b) || (c > 0xbf);
}
