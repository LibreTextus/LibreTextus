#ifndef LIBRE_EXPORTER_HPP
#define LIBRE_EXPORTER_HPP

#include <rapidxml/rapidxml.hpp>
#include <rapidxml/rapidxml_utils.hpp>
#include <fstream>
#include <iostream>
#include "search_engine.hpp"

namespace Libre {
	class Exporter {
		private:
			SearchEngine search_engine;
			rapidxml::xml_document<> * file;
			std::ofstream fout;
			std::string path;
			std::string source;
			std::string position;

			void get_position_from_default_source();
			void extract_notes_from_file();

		public:
			Exporter(rapidxml::xml_document<> *, std::string &, std::string &, std::string &);
			virtual ~Exporter() = default;
			int export_note();
	};
}

#endif
