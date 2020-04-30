#ifndef SOURCE_HANDLER
#define SOURCE_HANDLER

#include <yaml-cpp/yaml.h>
#include <iostream>
#include <tsl/ordered_map.h>
#include <chrono>

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
	static std::vector<std::string> compare_v;

	Libre::BookMap to_map(YAML::Node);
	Libre::NameMap to_names(YAML::Node);

public:
	SourceHandler() = default;
	virtual ~SourceHandler() = default;

	Libre::BookMap * get_source(std::string s);
	Libre::NameMap * get_names(std::string s);
};

#endif
