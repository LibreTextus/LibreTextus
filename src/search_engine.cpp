#include "search_engine.hpp"

// SEARCHENGINE::SEARCHENGINE --------------------------------------------------
// THIS IS THE CONSTRUCTOR OF THE SEARCHENGINE. IT LOADS THE SOURCE + NAMESFILE
// -----------------------------------------------------------------------------

SearchEngine::SearchEngine(std::string file_path, std::string names_path) {
	this->file = this->source_handler.get_source(file_path);
	this->names = this->source_handler.get_names(names_path);
	this->active_verse = this->file->begin();

	W = "\\w\u00C0-\u024f";
}

// SEARCHENGINE::SET_SEARCH_ARGUMENT -------------------------------------------
// FUNCTION TO SET THE SEARCH ARGUMENT. IT WILL RESET THE LAST SEARCH RESULT
// -----------------------------------------------------------------------------

void SearchEngine::set_search_argument(std::string arg) {
	this->search_argument = arg;
	this->raw_search_argument = arg;

	this->interpret_string();
	this->last_search_results.clear();
	this->active_verse = this->positions.front()[0];
	this->active_verse_index = 0;
}

// SEARCHENGINE::SET_MARK_ARGUMENT ---------------------------------------------
// THIS FUNCTION SETS THE MARK STRING TO HIGHLIGHT THE RESULTS
// -----------------------------------------------------------------------------

void SearchEngine::set_mark_argument(std::string arg) {
	this->mark_argument = arg;
}

// SEARCHENGINE::SET_SOURCE ----------------------------------------------------
// THIS FUNCTION SET A NEW SOURCE VIA PATH
// -----------------------------------------------------------------------------

void SearchEngine::set_source(std::string path) {
	this->file = this->source_handler.get_source(path);

	this->active_verse = this->file->begin();
}

// SEARCHENGINE::GET_VERSE -----------------------------------------------------
// RETURNS VERSE THE ARGUMENT HAS TO BE IN THES FORM: *BOOK, CHAPTER, VERSE*
// -----------------------------------------------------------------------------

std::string * SearchEngine::get_verse(std::string p) {
	if (this->file->find(p) != this->file->end()) {
		return &(*this->file)[p];
	}
	else {
		return nullptr;
	}
}

// SEARCHENGINE::GET_PROGRESS --------------------------------------------------
// GET THE SEARCH PROGRESS
// -----------------------------------------------------------------------------

float SearchEngine::get_progress() {
	if (this->file->size()) {
		return static_cast<float>(std::distance(this->file->begin(), this->active_verse)) / this->file->size();
	}

	return 0;
}

// SEARCHENGINE::SEARCH ------------------------------------------------------­­­--
// THIS FUNCTION WILL SEARCH THE ASKED VERSES
// -----------------------------------------------------------------------------

bool SearchEngine::search(std::string * text) {

	boost::regex e;

	while (this->active_verse != this->positions.back()[1]) {
		if (this->active_verse == this->positions[this->active_verse_index][1]) {
			this->active_verse_index++;
			this->active_verse = this->positions[this->active_verse_index][0];
		}

		bool found = true;

		for(int i = 0; i < this->search_argument_vector.size(); i++) { // this->active_verse.value()
			e = this->search_argument_vector[i];
			found &= boost::regex_search(this->active_verse.value(), e);
		}

		if (found || this->search_argument == "") {

			*text = this->active_verse.value();

			if (this->search_argument != "") {
				this->mark_result(text);
			}

			this->last_search_results.push_back(this->active_verse->first);

			this->active_verse++;

			return true;
		}
		this->active_verse++;
	}

	return false;
}

// SEARCHENGINE::SEARCH_POSITION -----------------------------------------------
// THIS FUNCTION CHECKES IF THE SEARCH ARGUMENT IS A BOOK POSITION OR A NORMAL
// SEARCH ARGUMENT. IF IT IS A BOOK POSITION SET THE POSITION AND RETURNS TRUE
// -----------------------------------------------------------------------------

void SearchEngine::interpret_string() {

	std::string arg = this->search_argument;
	std::string search = "";

	std::vector<std::array<std::string, 2>> pos;

	boost::regex e("@");

	boost::smatch m;

	if (boost::regex_search(arg, m, e)){
		search = m.prefix().str();
		arg = m.suffix().str();
	}

	for (Libre::NameMap::iterator i = this->names->begin(); i != this->names->end(); i++) {
		for (std::vector<std::string>::iterator x = i.value().begin(); x != i.value().end(); x++) {
			e = *x;
			arg = boost::regex_replace(arg, e, i->first);
		}
	}

	e = " ";

	arg = boost::regex_replace(arg, e, "");

	bool run = this->names->find(arg.substr(0, 3)) != this->names->end();

	while (run) {
		pos.push_back({"", ""});

		if (this->names->find(arg.substr(0, 3)) != this->names->end()) {
			pos.back()[0] = arg.substr(0, 3) + " ";
			arg.erase(0, 3);

		} else if (arg.substr(0, 1) == ";") {
			arg.erase(0, 1);
			pos.back()[0] = pos[pos.size() - 2][0].substr(0, 4);

		} else if (arg.substr(0, 1) == ".") {
			pos.back()[0] = pos[pos.size() - 2][0].substr(0, pos[pos.size() - 2][0].find(",") + 1);

			e = "\\d+";
			boost::regex_search(arg, m, e);
			pos.back()[0] += m.str();
			arg = m.suffix().str();

			pos.back()[1] = pos.back()[0];

			if (arg.substr(0, 1) == "-") {
				arg.erase(0, 1);
				pos.back()[1].erase(pos.back()[0].find(",") + 1, std::string::npos);
				boost::regex_search(arg, m, e);
				pos.back()[1] += m.str();
				arg = m.suffix().str();
			}

			if (arg == "") {
				break;
			}

			continue;

		} else {
			break;
		}

		e = "\\d+";
		if (boost::regex_search(arg, m, e)) {
			pos.back()[0] += m.str() + ",";
			arg = m.suffix().str();
		}

		if (arg.substr(0, 1) == "-") {
			arg.erase(0, 1);

			if (this->names->find(arg.substr(0, 3)) != this->names->end()) {
				pos.back()[1] = arg.substr(0, 3);
				arg.erase(0, 3);

				boost::regex_search(arg, m, e);
				pos.back()[1] += m.str() + ",";
				arg = m.suffix().str();

				pos.back()[0] += "1";
				pos.back()[1] += "1";
			} else {

				pos.back()[0] += "1";

				boost::regex_search(arg, m, e);
				pos.back()[1] = pos.back()[0].substr(0, 4) + m.str() + ",";
				arg = m.suffix();

				Libre::BookMap::iterator i = this->file->find(pos.back()[1] + "1");

				for (;i->first.substr(0, i->first.find(",") + 1) == pos.back()[1]; i++) {}

				i--;

				pos.back()[1] = i->first;
			}

		} else if (arg.substr(0, 1) == ",") {
			arg.erase(0, 1);

			boost::regex_search(arg, m, e);
			pos.back()[0] += m.str();
			arg = m.suffix().str();

			pos.back()[1] = pos.back()[0];

			if (arg.substr(0, 1) == "-") {
				arg.erase(0, 1);
				pos.back()[1].erase(pos.back()[0].find(",") + 1, std::string::npos);
				boost::regex_search(arg, m, e);
				pos.back()[1] += m.str();
				arg = m.suffix().str();
			}

		} else {
			if (pos.back()[0].length() == 4) {
				pos.back()[0] += "1,1";
				pos.back()[1] = pos.back()[0];

				Libre::BookMap::iterator i = this->file->find(pos.back()[1]);

				for (;i->first.substr(0, i->first.find(" ")) == pos.back()[1].substr(0, pos.back()[1].find(" ")); i++) {}
				i--;
				pos.back()[1] = i->first;
			} else {
				pos.back()[0] += "1";
				pos.back()[1] = pos.back()[0];

				Libre::BookMap::iterator i = this->file->find(pos.back()[1]);

				for (;i->first.substr(0, i->first.find(",")) == pos.back()[1].substr(0, pos.back()[1].find(",")); i++) {}
				i--;
				pos.back()[1] = i->first;
			}
		}

		if (arg == "") {
			run = false;
		}
	}

	bool valid_position = (pos.size() != 0);

	for (int i = 0; i < pos.size(); i++) {
		std::cout << "[" + std::to_string(i) + "][0]: " << pos[i][0] << (this->file->find(pos[i][0]) == this->file->end() ? " x" : " √") << '\n';
		std::cout << "[" + std::to_string(i) + "][1]: " << pos[i][1] << (this->file->find(pos[i][1]) == this->file->end() ? " x" : " √") << '\n';
		if (this->file->find(pos[i][0]) == this->file->end() || this->file->find(pos[i][1]) == this->file->end()) {
			valid_position = false;
			break;
		}
	}
	this->positions.clear();

	if (valid_position) {
		for (int i = 0; i < pos.size(); i++) {
			this->positions.push_back({this->file->find(pos[i][0]), this->file->find(pos[i][1]) + 1});
			this->search_argument = search;
		}
	} else {
		this->positions.push_back({this->file->begin(), this->file->end()});
	}

	this->interpret_argument(&this->search_argument);

	this->search_argument_vector.clear();

	e = "&";
	arg = this->search_argument;

	while(boost::regex_search(arg, m, e)) {
		this->search_argument_vector.push_back(m.prefix().str());
		arg = m.suffix();
	}

	this->search_argument_vector.push_back(arg);

	std::cout << "REGEX ARGS: ";

	for (int i = 0; i < this->search_argument_vector.size(); i++) {
		std::cout << this->search_argument_vector[i] << " AND ";
	}

	std::cout << "(" << this->search_argument_vector.size() << ")" << '\n';
}

// SEARCHENGINE::INTERPRET_ARGUMENT --------------------------------------------
// THIS FUNCTION TURNS THE SEARCH ARGUMENT INTO A REGEX ARGUMENT
// -----------------------------------------------------------------------------

void SearchEngine::interpret_argument(std::string * arg) {

	while (arg->back() == ' ') {
		arg->pop_back();
	}

	while (arg->front() == ' ') {
		*arg = arg->substr(1, std::string::npos);
	}

	// ------------------------------------------
	// IF THERE ARE QUOTED WORDS REPLACE IT WITH
	// *&ç&€* AND AFTER EVERY MANIPULATION
	// INSERT THE QUOTED WORDS IN ITS PLACE
	// THE REPLACE STRING HAS TO BE NON-WORD
	// CHARACTERS THAT THEY WONT BE SELECTED
	// IN THE FOLLOWING PROCESS
	// ------------------------------------------

	boost::regex e("\".[^\"]*\"");

	boost::smatch m;
	std::vector<std::string> static_expressions;

	std::string arg_copy = *arg;

	while (boost::regex_search(arg_copy, m, e)) {
		static_expressions.push_back(m.str());
		arg_copy = m.suffix().str();
	}

	*arg = boost::regex_replace(*arg, e, "_INSERT_");

	// ------------------------------------------
	// SELECT EVERY WORD AND LIST THEM IN
	// PARANTHESES WITH *OR* OPERATORS
	// ------------------------------------------
	e = "[\\w\u00C0-\u024f\\*]+";
	*arg = boost::regex_replace(*arg, e, "((?<=[^\\\\w\u00C0-\u024f])|\\\\A)$&(?=[^\\\\w\u00C0-\u024f]|$)");

	e = "\\*";
	*arg = boost::regex_replace(*arg, e, "[\\\\w\u00C0-\u024f]*");

	e = " ";

	if (boost::regex_search(*arg, e)) {
		*arg = boost::regex_replace(*arg, e, "&");
	}

	// ------------------------------------------
	// INSERT THE QUOTED WORDS ON THEIR POSITION
	// AND DELETE THE QUOTES
	// ------------------------------------------

	for (std::vector<std::string>::iterator i = static_expressions.begin(); i != static_expressions.end(); i++) {
		e = "((?<=[^\\\\w\u00C0-\u024f])|\\\\A)$&(?=[^\\\\w\u00C0-\u024f]|$)";
		*i = boost::regex_replace(*i, e, "((?<=[^\\\\w\u00C0-\u024f])|\\\\A)$&(?=[^\\\\w\u00C0-\u024f]|$)");

		e = "\\*";
		*i = boost::regex_replace(*i, e, "\\*");

		e = "_INSERT_";

		if (boost::regex_search(*arg, m, e))	{
			*arg = m.prefix().str() + *i + m.suffix().str();
		}
	}

	e = "\"";
	*arg = boost::regex_replace(*arg, e, "");
}

// SEARCHENGINE::MARK_RESULT ---------------------------------------------------
// THIS FUNCTION REPLACES THE RESULT WITH THE RESULT WITH MARKS
// -----------------------------------------------------------------------------

void SearchEngine::mark_result(std::string * text) {
	boost::regex e("&");
	e = boost::regex_replace(this->search_argument, e, "|");
	*text = boost::regex_replace(*text, e, this->mark_argument);
}
