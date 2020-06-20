#ifndef SOURCE_HANDLER
#define SOURCE_HANDLER

#include <iostream>
#include <tsl/ordered_map.h>
#include <map>
#include <rapidxml/rapidxml.hpp>
#include <rapidxml/rapidxml_utils.hpp>
#include <rapidxml/rapidxml_print.hpp>

// -----------------------------------------------------------------------------
// THE SOURCEHANDLER CLASS IS FOR MAKE IT MORE EFFICIENT. IT LOADS A FILE IF IT
// HAS NOT ALREADY LOADED IT ELSE IT TAKES THE FILE FROM THE MEMORY
// -----------------------------------------------------------------------------

namespace Libre {
	typedef tsl::ordered_map<std::string, std::string> BookMap;
	typedef tsl::ordered_map<std::string, std::vector<std::string>> NameMap;
}

class SourceHandler {
private:
	static std::map<std::string, Libre::BookMap> sources;
	static Libre::NameMap names;
	static std::string names_path;

	Libre::BookMap to_map(rapidxml::xml_document<> *);
	Libre::NameMap to_names(rapidxml::xml_document<> *);

public:
	SourceHandler() = default;
	virtual ~SourceHandler() = default;

	Libre::BookMap * get_source(std::string);
	Libre::NameMap * get_names();
	void set_names_path(std::string);
};

#endif
