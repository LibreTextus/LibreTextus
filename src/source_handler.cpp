#include "source_handler.hpp"

std::map<std::string, YAML::Node> SourceHandler::sources;

YAML::Node SourceHandler::get_source(std::string s) {

	if (sources.find(s) == sources.end()) {
		YAML::Node v = YAML::LoadFile(s);
		sources[s] = v;
	}

	return YAML::Clone(sources[s]);
}
