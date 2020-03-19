#ifndef SOURCE_HANDLER
#define SOURCE_HANDLER

#include <yaml-cpp/yaml.h>
#include <iostream>
#include <map>

class SourceHandler {
private:
	static std::map<std::string, YAML::Node> sources;

public:
	SourceHandler() = default;
	virtual ~SourceHandler() = default;

	YAML::Node get_source(std::string s);
};

#endif
