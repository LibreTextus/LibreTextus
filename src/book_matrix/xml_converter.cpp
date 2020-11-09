#include "xml_converter.hpp"

Libre::XMLConverter::XMLConverter(const std::string & path) : num_verses(0) {
	std::cout << "Load XML FILE\n";
	rapidxml::file<> xml_file(path.c_str());
	
	char * content = this->doc.allocate_string(xml_file.data());
	this->doc.parse<rapidxml::parse_no_data_nodes>(content);

	this->root = this->doc.first_node("XMLBIBLE")->first_node("BIBLEBOOK");

	std::vector<std::string> verse_words;
	std::string verse;

	std::cout << "Count num verses\n";

	for (rapidxml::xml_node<> * b = this->root; b; b = b->next_sibling()) {
		for (rapidxml::xml_node<> * c = b->first_node("CHAPTER"); c; c = c->next_sibling()) {
			for (rapidxml::xml_node<> * v = c->first_node("VERS"); v; v = v->next_sibling()) {
				this->num_verses++;
			}
		}
	}

	std::cout << "Parse File\n";

	size_t i = 0;

	for (rapidxml::xml_node<> * book = this->root; book; book = book->next_sibling()) {
		for (rapidxml::xml_node<> * ch = book->first_node("CHAPTER"); ch; ch = ch->next_sibling()) {
			for (rapidxml::xml_node<> * v = ch->first_node("VERS"); v; v = v->next_sibling()) {
				std::cout << "	* Get Verse and clear Vector\n";
				verse = v->value();
				verse_words.clear();

				std::cout << "	* Make Verse lowercase\n";
				std::transform(verse.begin(), verse.end(), verse.begin(), [](const unsigned char & c) { return std::tolower(c); });

				std::cout << "	* Convert to Vector\n";
				this->split_string(verse, &verse_words);

				std::cout << "	* Write to Matrix\n";
				for (std::string & w : verse_words) {
					if (this->matrix[w].empty()) {
						this->matrix[w] = std::vector<bool>(this->num_verses, false);
						std::cout << "		* Create new Table\n";
					}

					this->matrix[w][i] = true;
				}

				++i;
			}
		}
	}

	std::cout << "End Parsing\n";
}

void Libre::XMLConverter::split_string(const std::string & line, std::vector<std::string> * v) {
	std::string::const_iterator b = line.begin();
	std::string::const_iterator e = line.begin();
	
	while (true) {
		for (;*e != ' ' && *e != '.' && *e != ',' && *e != ';' && e != line.end(); ++e) {}

		v->push_back(std::string(b, e));

		if (e == line.end()) {
			break;
		}

		b = ++e;
	}
}

void Libre::XMLConverter::save_to_file(const std::string & path) {
	std::cout << "Save to file: " << path << '\n';
	std::ofstream f(path);

	std::cout << "Write wordlist\n";

	for (const std::pair<std::string, std::vector<bool>> & i : this->matrix) {
		f << i.first << ' ';
	}

	f << '\n';

	std::cout << "Write Matrix\n";
	std::cout << "Matrix Size " << this->num_verses << '\n';

	for (int i = 0; i < this->num_verses; ++i) {
		std::map<std::string, std::vector<bool>>::iterator j = matrix.begin();
		while (j != matrix.end()) {
			char c = 0;
			
			std::cout << "	* Create Char " << i <<"\r";
			for (int n = 0; j != matrix.end() && n < 8; ++n) {
				c += j->second[i] << n;
				++j;
			}

			f << c;
		}
	}

	f.close();

	std::cout << "\nEnd Writing\n";
}
