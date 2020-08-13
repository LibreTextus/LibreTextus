#include "search_engine.hpp"

SearchEngine::SearchEngine(const std::string & f) {
	this->file_path = f;
	this->file = this->source_handler.get_source(f);
	this->names = this->source_handler.get_names();
	this->active_verse = this->file->begin();
}

