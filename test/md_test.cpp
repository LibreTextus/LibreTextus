#include <stdexcept>
#include <iostream>
#include <markdown/markdown.hpp>

int main(int argc, char const *argv[]) {
	MD::String text("A*B*__C__~D~E");

	int tags[13] = {MD::STYLE::NORMAL,
								 MD::STYLE::HIDDEN,
								 MD::STYLE::ITALIC,
								 MD::STYLE::HIDDEN,
								 MD::STYLE::HIDDEN,
								 MD::STYLE::HIDDEN,
								 MD::STYLE::BOLD,
								 MD::STYLE::HIDDEN,
								 MD::STYLE::HIDDEN,
								 MD::STYLE::HIDDEN,
								 MD::STYLE::STRIKETHROUGH,
								 MD::STYLE::HIDDEN,
								 MD::STYLE::NORMAL,
	};

	int counter = 0;

	for (MD::String::iterator i = text.begin(); i != text.end(); i++) {
		std::cerr << *i << '\n';

		if (!i->has_tag(tags[counter])) {
			std::cerr << *i << "has wrong tag: " << i->tag << '\n';
			throw 42;
		}

		counter++;
	}


	return 0;
}
