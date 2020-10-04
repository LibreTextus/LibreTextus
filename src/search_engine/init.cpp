#include "search_engine.hpp"

SearchEngine::SearchEngine(const std::string & f) : search_mutex(nullptr), file_path(f), num_threads(std::thread::hardware_concurrency()) {
	this->file = this->source_handler.get_source(f);
	this->names = this->source_handler.get_names();
}

