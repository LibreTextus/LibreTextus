#include "../search_engine.hpp"

void SearchEngine::interpret_string() {

	std::string arg = this->search_argument;
	std::string search = "";

	std::vector<std::array<std::string, 2>> pos;
	
	this->split_position_and_argument(&search, &arg);
	this->replace_book_names(&arg);
	this->remove_spaces_from_argument(&arg);

	this->get_position_from_string(&arg, &pos);
	
	
	this->positions.clear();

	bool is_valid_position = this->validate_positions(&pos);
	if (is_valid_position) {
		for (int i = 0; i < pos.size(); i++) {
			this->positions.push_back({this->file->find(pos[i][0]), this->file->find(pos[i][1]) + 1});
		}
		this->search_argument = search;

	} else {
		this->positions.push_back({this->file->begin(), this->file->end()});
	}

	this->interpret_argument(&this->search_argument);

	this->create_search_vector_from_string();
	
#ifdef SEARCH_DEBUG
	std::cout << "REGEX ARGS: ";

	for (int i = 0; i < this->search_argument_vector.size(); i++) {
		std::cout << this->search_argument_vector[i] << " AND ";
	}

	std::cout << "(" << this->search_argument_vector.size() << ")" << '\n';
#endif
}

void SearchEngine::split_position_and_argument(std::string * search, std::string * arg) {
	boost::regex e("@", boost::regex::icase);
	boost::smatch m;

	if (boost::regex_search(*arg, m, e)){
		*search = m.prefix().str();
		*arg = m.suffix().str();
	}
}

void SearchEngine::replace_book_names(std::string * arg) {
	boost::regex e;

	for (Libre::NameMap::iterator i = this->names->begin(); i != this->names->end(); i++) {
		for (std::vector<std::string>::iterator x = i.value().begin(); x != i.value().end(); x++) {
			e = boost::regex(*x + "(\\s|$)");
			*arg = boost::regex_replace(*arg, e, i->first);
		}
	}
}

void SearchEngine::remove_spaces_from_argument(std::string * arg) {
	boost::regex e = boost::regex(" ", boost::regex::icase);
	*arg = boost::regex_replace(*arg, e, "");
}

void SearchEngine::get_position_from_string(std::string * arg, std::vector<std::array<std::string, 2>> * pos) {
	boost::regex e;
	boost::smatch m;
	bool run = this->names->find(arg->substr(0, 3)) != this->names->end();

	while (run) {
		pos->push_back({"", ""});

		if (this->names->find(arg->substr(0, 3)) != this->names->end()) {
			pos->back()[0] = arg->substr(0, 3) + " ";
			arg->erase(0, 3);

		} else if (arg->substr(0, 1) == ";") {
			arg->erase(0, 1);
			pos->back()[0] = (*pos)[pos->size() - 2][0].substr(0, 4);

		} else if (arg->substr(0, 1) == ".") {
			pos->back()[0] = (*pos)[pos->size() - 2][0].substr(0, (*pos)[pos->size() - 2][0].find(",") + 1);

			e = boost::regex("\\d+", boost::regex::icase);
			boost::regex_search(*arg, m, e);
			pos->back()[0] += m.str();
			*arg = m.suffix().str();

			pos->back()[1] = pos->back()[0];

			if (arg->substr(0, 1) == "-") {
				arg->erase(0, 1);
				pos->back()[1].erase(pos->back()[0].find(",") + 1, std::string::npos);
				boost::regex_search(*arg, m, e);
				pos->back()[1] += m.str();
				*arg = m.suffix().str();
			}

			if (*arg == "") {
				break;
			}

			continue;

		} else {
			break;
		}

		e = boost::regex("\\d+", boost::regex::icase);
		if (boost::regex_search(*arg, m, e)) {
			pos->back()[0] += m.str() + ",";
			*arg = m.suffix().str();
		}

		if (arg->substr(0, 1) == "-") {
			arg->erase(0, 1);

			if (this->names->find(arg->substr(0, 3)) != this->names->end()) {
				pos->back()[1] = arg->substr(0, 3);
				arg->erase(0, 3);

				if (!arg->empty()) {
					boost::regex_search(*arg, m, e);
					pos->back()[1] += m.str() + ",";
					*arg = m.suffix().str();

					pos->back()[0] += "1";
					pos->back()[1] += "1";

				} else {
					pos->back()[0] += "1,1";
					pos->back()[1] += " 1,1";

					Libre::BookMap::iterator i = this->file->find(pos->back()[1]);

					for (;i->first.substr(0, i->first.find(" ")) == pos->back()[1].substr(0, pos->back()[1].find(" ")); i++) {}
					i--;
					pos->back()[1] = i->first;
				}

			} else {

				pos->back()[0] += "1";

				boost::regex_search(*arg, m, e);
				pos->back()[1] = pos->back()[0].substr(0, 4) + m.str() + ",";
				*arg = m.suffix();

				Libre::BookMap::iterator i = this->file->find(pos->back()[1] + "1");

				for (;i->first.substr(0, i->first.find(",") + 1) == pos->back()[1]; i++) {}

				i--;

				pos->back()[1] = i->first;
			}

		} else if (arg->substr(0, 1) == ",") {
			arg->erase(0, 1);

			boost::regex_search(*arg, m, e);
			pos->back()[0] += m.str();
			*arg = m.suffix().str();

			pos->back()[1] = pos->back()[0];

			if (arg->substr(0, 1) == "-") {
				arg->erase(0, 1);
				pos->back()[1].erase(pos->back()[0].find(",") + 1, std::string::npos);
				boost::regex_search(*arg, m, e);
				pos->back()[1] += m.str();
				*arg = m.suffix().str();
			}

		} else {
			if (pos->back()[0].length() == 4) {
				pos->back()[0] += "1,1";
				pos->back()[1] = pos->back()[0];

				Libre::BookMap::iterator i = this->file->find(pos->back()[1]);

				for (;i->first.substr(0, i->first.find(" ")) == pos->back()[1].substr(0, pos->back()[1].find(" ")); i++) {}
				i--;
				pos->back()[1] = i->first;
			} else {
				pos->back()[0] += "1";
				pos->back()[1] = pos->back()[0];

				Libre::BookMap::iterator i = this->file->find(pos->back()[1]);

				for (;i->first.substr(0, i->first.find(",")) == pos->back()[1].substr(0, pos->back()[1].find(",")); i++) {}
				i--;
				pos->back()[1] = i->first;
			}
		}

		if (arg->empty()) {
			run = false;
		}
	}
}

bool SearchEngine::validate_positions(std::vector<std::array<std::string, 2>> * pos) {
	bool valid_position = (pos->size() != 0);

	for (int i = 0; i < pos->size(); i++) {

#ifdef SEARCH_DEBUG
		std::cout << "[" + std::to_string(i) + "][0]: " << pos[i][0] << (this->file->find(pos[i][0]) == this->file->end() ? " x" : " √") << '\n';
		std::cout << "[" + std::to_string(i) + "][1]: " << pos[i][1] << (this->file->find(pos[i][1]) == this->file->end() ? " x" : " √") << '\n';
#endif

		if (this->file->find((*pos)[i][0]) == this->file->end() || this->file->find((*pos)[i][1]) == this->file->end()) {
			valid_position = false;
			break;
		}
	}

	return valid_position;
}

void SearchEngine::create_search_vector_from_string() {
	this->search_argument_vector.clear();
	boost::regex e = boost::regex("(?<!\\\\)&", boost::regex::icase);
	boost::smatch m;
	std::string arg = this->search_argument;

	while(boost::regex_search(arg, m, e)) {
		this->search_argument_vector.push_back(m.prefix().str());
		arg = m.suffix();
	}

	this->search_argument_vector.push_back(arg);
}