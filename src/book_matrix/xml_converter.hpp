#ifndef LIBRE_XML_CONVERTER_HPP
#define LIBRE_XML_CONVERTER_HPP

#include <rapidxml/rapidxml.hpp>
#include <rapidxml/rapidxml_utils.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <vector>
#include <map>
#include <algorithm>
#include <locale>
#include <codecvt>
#include <fstream>
#include <iostream>

#include <tolowermap/tolowermap.hpp>

#include <source_handler/book_map.hpp>

#include "primes/primes.hpp"

using namespace boost::multiprecision;

typedef number<cpp_int_backend<2048, 2048, unsigned_magnitude, unchecked, void>> uint2048_t;

namespace Libre {
	class XMLConverter {
		private:
			std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;

			rapidxml::xml_document<> doc;
			rapidxml::xml_node<> * root;
			std::map<std::string, unsigned long> word_idx;
			std::vector<std::string> sorted_words;
			std::vector<std::vector<std::string>> verses;
			size_t num_verses;
			Libre::Primes primes;

			void split_string(const std::wstring &, std::vector<std::string> *);
			bool is_word(const wchar_t);

		public:
			XMLConverter(const Libre::BookMap &);
			~XMLConverter() = default;

			void save_to_file(const std::string &);
	};
}

#endif
