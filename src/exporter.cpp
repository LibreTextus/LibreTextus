#include "exporter.hpp"

Libre::Exporter::Exporter(rapidxml::xml_document<> * doc, std::string & p, std::string & s, std::string & pos) : search_engine(s) {
	
	this->file = doc;
	this->path = p;
	this->position = pos;
	this->source = s;
	fout.open(this->path + ".tmp");
	search_engine.set_search_argument(this->position);
}

int Libre::Exporter::export_note() {
	this->get_position_from_default_source();
	this->extract_notes_from_file();

	fout.close();	

	return system(("mv " + path + ".tmp " + this->path).c_str());
}

void Libre::Exporter::get_position_from_default_source() {
	std::string r;
	while (search_engine.search(&r)) {}
}

void Libre::Exporter::extract_notes_from_file() {
	std::vector<std::string> * v = search_engine.get_last_search_results();

	for (rapidxml::xml_node<> * i = this->file->first_node("notebook")->first_node("note"); i; i = i->next_sibling()) {
		bool is_in_range = std::find(v->begin(), v->end(), std::string(i->first_attribute("name")->value())) != v->end();
		if (is_in_range) {
			fout << "# " << i->first_attribute("name")->value() << '\n';
			fout << i->value() << '\n';
		}
	}
}
