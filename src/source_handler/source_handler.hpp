#ifndef SOURCE_HANDLER
#define SOURCE_HANDLER

#include <iostream>
#include <tsl/ordered_map.h>
#include <map>
#include <rapidxml/rapidxml.hpp>
#include <rapidxml/rapidxml_utils.hpp>
#include <rapidxml/rapidxml_print.hpp>
#include <boost/regex.hpp>

namespace Libre {
	typedef tsl::ordered_map<std::string, std::string> BookMap;
	typedef tsl::ordered_map<std::string, std::vector<std::string>> NameMap;
	typedef tsl::ordered_map<std::string, tsl::ordered_map<std::string, std::string>> StrongMap;
}

class SourceHandler {
private:
	static tsl::ordered_map<std::string, Libre::BookMap> sources;
	static tsl::ordered_map<std::string, Libre::StrongMap> strongs;
	static Libre::NameMap names;
	static std::string names_path;

	Libre::BookMap to_map(rapidxml::xml_document<> *, const std::string &);
	inline Libre::NameMap to_names(rapidxml::xml_document<> *);

public:
	SourceHandler() = default;
	virtual ~SourceHandler() = default;

	Libre::BookMap * get_source(const std::string &);
	Libre::NameMap * get_names();
	Libre::StrongMap * get_strongs(const std::string &);
	void set_names_path(const std::string &);
};

#endif
