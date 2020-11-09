#include "search_engine.hpp"

SearchEngine::SearchEngine(const std::string & f) : search_mutex(nullptr), num_threads(std::thread::hardware_concurrency()) {
	this->set_source(f);
	this->names = this->source_handler.get_names();
}

