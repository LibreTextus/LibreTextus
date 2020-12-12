#ifndef SOURCE_HANDLER
#define SOURCE_HANDLER

#include <iostream>
#include <future>
#include <tsl/ordered_map.h>
#include <map>
#include <rapidxml/rapidxml.hpp>
#include <rapidxml/rapidxml_utils.hpp>
#include <rapidxml/rapidxml_print.hpp>
#include <boost/regex.hpp>
#include <experimental/filesystem>

#include <book_matrix/book_matrix.hpp>
#include <book_matrix/xml_converter.hpp>
#include <grammar/grammar.hpp>

#include "book_map.hpp"

class SourceHandler {
private:
	static tsl::ordered_map<std::string, Libre::BookMap> sources;
	static tsl::ordered_map<std::string, Libre::StrongMap> strongs;
	static tsl::ordered_map<std::string, Libre::BookMatrix> matrices;
	static tsl::ordered_map<std::string, Libre::GrammarMap> grammar_maps;
	static Libre::NameMap names;
	static std::string names_path;

	static Libre::Grammar grammar;

	Libre::BookMap to_map(rapidxml::xml_document<> *, const std::string &);
	inline Libre::NameMap to_names(rapidxml::xml_document<> *);

public:
	SourceHandler() = default;
	virtual ~SourceHandler() = default;

	Libre::BookMap * get_source(const std::string &);
	Libre::NameMap * get_names();
	Libre::StrongMap * get_strongs(const std::string &);
	Libre::BookMatrix * get_matrix(const std::string &);
	Libre::GrammarMap * get_grammar_map(const std::string &);
	void set_names_path(const std::string &);
};

#endif
