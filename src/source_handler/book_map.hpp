#ifndef LIBRE_BOOK_MAP_HPP
#define LIBRE_BOOK_MAP_HPP

#include <tsl/ordered_map.h>
#include <vector>

namespace Libre {
	typedef tsl::ordered_map<std::string, std::string> BookMap;
	typedef tsl::ordered_map<std::string, std::vector<std::string>> NameMap;
	typedef tsl::ordered_map<std::string, tsl::ordered_map<std::string, std::string>> StrongMap;
	typedef tsl::ordered_map<std::string, tsl::ordered_map<std::string, std::vector<std::string> *>> GrammarMap;
}

#endif
