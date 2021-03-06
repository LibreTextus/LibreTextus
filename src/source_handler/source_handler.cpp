#include "source_handler.hpp"
#include "book_matrix/book_matrix.hpp"
#include "book_matrix/xml_converter.hpp"
#include "source_handler/book_map.hpp"
#include <rapidxml/rapidxml.hpp>

tsl::ordered_map<std::string, Libre::BookMap> SourceHandler::sources;
tsl::ordered_map<std::string, Libre::StrongMap> SourceHandler::strongs;
tsl::ordered_map<std::string, Libre::BookMatrix> SourceHandler::matrices;
tsl::ordered_map<std::string, Libre::GrammarMap> SourceHandler::grammar_maps;
Libre::NameMap SourceHandler::names;
std::string SourceHandler::names_path;
Libre::Grammar SourceHandler::grammar;

Libre::BookMap * SourceHandler::get_source(const std::string & s) {
	
	if (this->sources[s].empty()) {
		rapidxml::file<> file(s.c_str());
		rapidxml::xml_document<> doc;
		doc.parse<0>(file.data());

		this->sources[s] = this->to_map(&doc, s);
	}

	return &this->sources[s];
}

Libre::BookMap SourceHandler::to_map(rapidxml::xml_document<> * doc, const std::string & s) {
	Libre::BookMap output;
	Libre::StrongMap str_num;
	Libre::GrammarMap gr_map;

	boost::regex e("\\s");

	for (rapidxml::xml_node<> * b = doc->first_node("XMLBIBLE")->first_node("BIBLEBOOK"); b; b = b->next_sibling()) {
		for (rapidxml::xml_node<> * c = b->first_node("CHAPTER"); c; c = c->next_sibling()) {
			for (rapidxml::xml_node<> * v = c->first_node("VERS"); v; v = v->next_sibling()) {
				std::string v_pos = (this->names.begin() + std::stoi(b->first_attribute("bnumber")->value()) - 1)->first;

				v_pos += " " + std::string(c->first_attribute("cnumber")->value());
				v_pos	+= "," + std::string(v->first_attribute("vnumber")->value());
				output[v_pos] = "";

				for (rapidxml::xml_node<> * v_part = v->first_node(); v_part; v_part = v_part->next_sibling()) {
					if (std::string(v_part->name()) != "DIV") {
						output[v_pos] += v_part->value();

						if (std::string(v_part->name()) == "gr") {
							str_num[v_pos].insert({boost::regex_replace(std::string(v_part->value()), e, ""), std::string(v_part->first_attribute("str")->value())});

							if (v_part->first_attribute("rmac")) {
								if (!(*this->grammar.get_grammar_map())[v_part->first_attribute("rmac")->value()].empty()) {
									gr_map[v_pos].insert({boost::regex_replace(std::string(v_part->value()), e, ""), &(*this->grammar.get_grammar_map())[v_part->first_attribute("rmac")->value()]});
								}
							}
						} 
					}
				}
			}
		}
	}

	this->strongs[s] = str_num;
	this->grammar_maps[s] = gr_map;

	return output;
}

Libre::NameMap * SourceHandler::get_names() {
	return &this->names;
}

inline Libre::NameMap SourceHandler::to_names(rapidxml::xml_document<> * doc) {
	Libre::NameMap output;

	for (rapidxml::xml_node<> * b = doc->first_node("BIBLEBOOKS")->first_node("BOOK"); b; b = b->next_sibling()) {
		std::vector<std::string> v;

		for (rapidxml::xml_node<> * i = b->first_node("ITEM"); i; i = i->next_sibling()) {
			v.push_back(i->first_attribute("name")->value());
		}

		output[b->first_attribute("name")->value()] = v;
	}

	return output;
}

void SourceHandler::set_names_path(const std::string & s) {
	rapidxml::file<> file(s.c_str());
	rapidxml::xml_document<> doc;
	doc.parse<0>(file.data());
	this->names = this->to_names(&doc);
}

Libre::StrongMap * SourceHandler::get_strongs(const std::string & s) {
	return &this->strongs[s];
}

Libre::GrammarMap * SourceHandler::get_grammar_map(const std::string & s) {
	return &this->grammar_maps[s];
}

Libre::BookMatrix * SourceHandler::get_matrix(const std::string & s) {
	std::string filename = s.substr(0, s.find_last_of(".")) + ".bkmx";

	if (!std::experimental::filesystem::exists(filename)) {
		Libre::XMLConverter conv(this->sources[s]);
		conv.save_to_file(filename);
	}

	this->matrices[filename].load_file(filename);

	return &this->matrices[filename];
}

void SourceHandler::regenerate_matrices() {
	for (const std::pair<std::string, Libre::BookMatrix> & p : this->matrices) {
		Libre::XMLConverter conv(this->sources[p.first.substr(0, p.first.find_last_of(".")) + ".xml"]);
		conv.save_to_file(p.first);

		this->matrices[p.first].load_file(p.first);
	}
}
