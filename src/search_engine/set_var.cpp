#include "search_engine.hpp"

void SearchEngine::set_search_argument(std::string arg) {
	std::cout << "set search argument\n";
	this->search_argument = arg;
	this->raw_search_argument = arg;

	this->interpret_string();
	this->last_search_results.clear();
}

void SearchEngine::set_mark_argument(std::string arg) {
	this->mark_argument = arg;
}


void SearchEngine::set_source(std::string path) {
	this->file = this->source_handler.get_source(path);
	this->file_path = path;
	this->matrix = this->source_handler.get_matrix(path);
}

