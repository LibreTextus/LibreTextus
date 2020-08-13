#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <rapidxml/rapidxml.hpp>
#include <rapidxml/rapidxml_print.hpp>
#include <rapidxml/rapidxml_utils.hpp>
#include <iostream>
#include <fstream>
#include <vector>

#include <path/path.hpp>

namespace Libre {
	class Settings {
		public:
			Settings () = default;
			virtual ~Settings () = default;

			std::string get_attribute(const std::string &, const std::string &);
			std::vector<std::string> get_children(const std::string &, const std::string &);

			void set(const std::string & tag, const std::string & attr, const std::string & value);
	};
}

#endif
