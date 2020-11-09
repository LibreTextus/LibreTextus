#include "source_handler.hpp"
#include "book_matrix/book_matrix.hpp"
#include "book_matrix/xml_converter.hpp"

tsl::ordered_map<std::string, Libre::BookMap> SourceHandler::sources;
tsl::ordered_map<std::string, Libre::StrongMap> SourceHandler::strongs;
tsl::ordered_map<std::string, Libre::BookMatrix> SourceHandler::matrices;
Libre::NameMap SourceHandler::names;
std::string SourceHandler::names_path;

Libre::BookMap * SourceHandler::get_source(const std::string & s) {

	if (this->sources.find(s) == this->sources.end()) {
		rapidxml::file<> file(s.c_str());
		rapidxml::xml_document<> doc;
		doc.parse<0>(file.data());

		std::vector<std::future<Libre::BookMap>> v;

		rapidxml::xml_node<> * begin = doc.first_node("XMLBIBLE")->first_node("BIBLEBOOK");
		rapidxml::xml_node<> * end;

		size_t num_of_books = 0;

		for (rapidxml::xml_node<> * i = begin; i; i = i->next_sibling()) { num_of_books++; }

		num_of_books /= std::thread::hardware_concurrency();

		end = begin;
		
		for (int i = 0; i < std::thread::hardware_concurrency() - 1; ++i) {
			for (int i = 0; i < num_of_books; ++i) {
				end = end->next_sibling();
			}

			v.push_back(std::async(std::launch::async, &SourceHandler::to_map, this, begin, end, s));

			begin = end;
		}


		doc.first_node("XMLBIBLE")->last_node("BIBLEBOOK");
		v.push_back(std::async(std::launch::async, &SourceHandler::to_map, this, begin, end, s));

		this->sources[s] = v.front().get();
		v.pop_back();
		
		for (std::vector<std::future<Libre::BookMap>>::iterator i = v.begin() + 1; i != v.end(); ++i) {
			Libre::BookMap m = i->get();
			this->sources[s].insert(m.begin(), m.end());
		}
	}

	return &this->sources[s];
}

Libre::BookMap SourceHandler::to_map(rapidxml::xml_node<> * begin, rapidxml::xml_node<> * end, const std::string & s) {
	Libre::BookMap output;
	Libre::StrongMap str_num;

	boost::regex e("\\s");

	// doc->first_node("XMLBIBLE")->first_node("BIBLEBOOK")

	for (rapidxml::xml_node<> * b = begin ; b != end; b = b->next_sibling()) {
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
							str_num[v_pos].insert({boost::regex_replace(std::string(v_part->value()), e, ""), std::string("g") + v_part->first_attribute("str")->value()});
						} 
					}
				}
			}
		}
	}

	this->strongs[s] = str_num;

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

Libre::BookMatrix * SourceHandler::get_matrix(const std::string & s) {
	std::string filename = s.substr(0, s.find_last_of(".")) + ".bkmx";

	if (!std::experimental::filesystem::exists(filename)) {
		Libre::XMLConverter conv(s);
		conv.save_to_file(filename);
	}

	this->matrices[filename] = Libre::BookMatrix(filename);

	return &this->matrices[filename];
}
