#ifndef LIBRE_XML_CONVERTER_HPP
#define LIBRE_XML_CONVERTER_HPP

#include <rapidxml/rapidxml.hpp>
#include <rapidxml/rapidxml_utils.hpp>
#include <vector>
#include <map>
#include <fstream>
#include <algorithm>
#include <iostream>

namespace Libre {
	class XMLConverter {
		private:
			rapidxml::xml_document<> doc;
			rapidxml::xml_node<> * root;
			std::map<std::string, std::vector<bool>> matrix;
			size_t num_verses;

			void split_string(const std::string &, std::vector<std::string> *);

		public:
			XMLConverter(const std::string &);
			~XMLConverter() = default;

			void save_to_file(const std::string &);
	};
}

#endif
