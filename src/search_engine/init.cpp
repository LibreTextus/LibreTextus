#include "search_engine.hpp"

SearchEngine::SearchEngine(const std::string & f) {
	this->set_source(f);
	this->names = this->source_handler.get_names();
}

