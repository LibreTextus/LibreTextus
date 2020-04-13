#include "source_handler.hpp"

std::map<std::string, Libre::BookMap> SourceHandler::sources;
Libre::NameMap SourceHandler::names;
std::vector<std::string> SourceHandler::compare_v;



Libre::BookMap SourceHandler::get_source(std::string s) {

	if (this->sources.find(s) == this->sources.end()) {
		YAML::Node v = YAML::LoadFile(s);
		this->sources[s] = this->to_map(v);
	}

	return this->sources[s];
}

Libre::BookMap SourceHandler::to_map(YAML::Node n) {
	Libre::BookMap output;

	for (YAML::const_iterator b = n.begin(); b != n.end(); b++) {
		for (YAML::const_iterator c = b->second.begin(); c != b->second.end(); c++) {
			for (YAML::const_iterator v = c->second.begin(); v != c->second.end(); v++) {
				output[b->first.as<std::string>() + ", " +c->first.as<std::string>() + ", " + v->first.as<std::string>()] =  v->second.as<std::string>();
			}
		}
	}

	return output;
}

Libre::NameMap SourceHandler::get_names(std::string s) {

	if (this->sources.find(s) == this->sources.end()) {
		YAML::Node v = YAML::LoadFile(s);
		this->names = this->to_names(v);
	}

	return this->names;
}

Libre::NameMap SourceHandler::to_names(YAML::Node n) {
	Libre::NameMap output;

	for (YAML::const_iterator b = n.begin(); b != n.end(); b++) {
		std::vector<std::string> v;

		for (YAML::const_iterator i = b->second.begin(); i != b->second.end(); i++) {
			v.push_back(i->as<std::string>());
		}

		output[b->first.as<std::string>()] = v;
	}

	return output;
}
