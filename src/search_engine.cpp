#include "search_engine.hpp"

SearchEngine::SearchEngine(std::string file_path, std::string names_path) {
	this->file = this->source_handler.get_source(file_path);
	this->names = this->source_handler.get_names(names_path);
	this->last_result = this->file.begin();

	W = "[\\w\\u00C0-\\u024f]";
}

void SearchEngine::set_search_argument(std::string arg) {
	this->search_argument = arg;
	this->interpreted_argument = arg;
	interpret_argument(&this->interpreted_argument);

	this->is_book = this->search_position();
	this->last_search_results.clear();
	this->last_result = this->file.begin();
}

void SearchEngine::set_mark_argument(std::string arg) {
	this->mark_argument = arg;
}

void SearchEngine::set_header_argument(std::string arg) {
	this->header_argument = arg;
}

void SearchEngine::set_source(std::string path) {
	this->file.clear();
	this->file = this->source_handler.get_source(path);

	this->last_result = this->file.begin();
}

std::string SearchEngine::get_verse(std::string p) {
	if (this->file.find(p) != this->file.end()) {
		return this->file[p];
	}
	else {
		return "~~~";
	}
}

float SearchEngine::get_progress() {
	if (this->file.size()) {
		return static_cast<float>(std::distance(this->file.begin(), this->last_result)) / this->file.size();
	}

	return 0;
}

bool SearchEngine::search(std::string * text) {
	if (this->is_book) {
		return search_book(text);
	}
	else {
		return search_word(text);
	}
}

bool SearchEngine::search_book(std::string * text) {

	bool begin = this->last_result != this->file.begin();

	bool end = false;

	while (this->last_result != this->file.end()){
		if (this->last_result->first == this->positions[0]) {
			begin = true;
		}

		if (this->last_result->first == this->positions[1]) {
			end = true;
		}

		if (begin) {

			*text += this->last_result.value();

			this->last_result++;

			this->last_search_results.push_back(this->last_result->first);

			if (end) {
				this->last_result = this->file.end();
			}

			return true;
		}
		this->last_result++;
	}
}

bool SearchEngine::search_word(std::string * text) {

	std::regex e(this->interpreted_argument);
	// -- BOOK LOOP

	while (this->last_result != this->file.end()) {
		if (std::regex_search(this->last_result.value(), e)) {	//	IF THERE IS THE EXPRESSION SEARCHED FOR
			*text += this->last_result.value();
			mark_result(text);

			this->last_result++;

			this->last_search_results.push_back(this->last_result->first);

			return true;
		}
		this->last_result++;
	}

	return false;
}

bool SearchEngine::search_position() {

	std::string pos[3][2];

	for (int i = 0; i < 3; i++) {
		for (int x = 0; x < 2; x++) {
			pos[i][x] = "";
		}
	}

	std::regex e(",");	// REGEX ARGUMENT
	std::smatch m;			// REGEX MATCH

	int comma_count = 0;	// NUMBER OF COMMAS

	std::string arg_copy = this->search_argument;	// COPY ARG FOR COUNT COMMAS

	while (std::regex_search(arg_copy, m, e)) {	// WHILE COMMA FOUND
		comma_count++;														// ADD ONE TO COMMA_COUNT
		arg_copy = m.suffix().str();							// ARG_COPY TO STRING AFTER FOUND COMMA
	}

	for (Libre::NameMap::iterator i = this->names.begin(); i != this->names.end(); i++) {	// FOR ALL POSSIBLE BOOK NAMES
		for (std::vector<std::string>::iterator x = i.value().begin(); x != i.value().end(); x++) {		// FOR ALL ALL POSSIBLE SPELLINGS
			e = "\\b" + *x + "\\b";																																			// FIND SPELLING
			this->search_argument = std::regex_replace(this->search_argument, e, i->first);							// REPLACE SPELLING WITH DEFAULT SPELLING : 1Mo -> GEN
		}
	}

	e = " ";															// FIND ALL SPACES
	this->search_argument = std::regex_replace(this->search_argument, e, "");	// AND REPLACE THEM WITH NOTHING (DELETE)

	if (comma_count == 2) {	// IF THERE ARE TWO COMMAS; THE ARGUMENT LOOKS LIKE *GEN, 1, 1 - 2*
		e = "[\\w-]+";	// ALL WORD-CHARACTERS [a-zA-z0-9]
		arg_copy = this->search_argument;	// COPY ARGUMENT FOR FIND WORDS

		for (int i = 0; i < 3; i++) {	// FOR EVERY ELEMENT OF POSITION-MAP
			std::regex_search(arg_copy, m, e);	// SEARCH NEXT WORD

			pos[i][0] = m.str();		// ADD POSITION
			arg_copy = m.suffix().str();				// ARG_COPY TO STRING AFTER FOUND WORD
		}

		e = "-";	// SEARCH ALL "-"

		std::string part;	// USED FOR REGEX_SEARCH

		for (int i = 0; i < 3; i++) {
			part = pos[i][0];				// PART FOR LOOKING IF THERE IS AN "-"
			if (std::regex_search(part, m, e)) {					// IF THERE IS AN "-"
				pos[i][0] = m.prefix().str();	// POSITION RANGE STARTS BEFORE THE "-"
				pos[i][1] = m.suffix().str();	// POSITION RANGE STOPS AFTER THE "-"

			} else {
				pos[i][1] = pos[i][0];	// IF THERE ARE NO "-" END EQUALS STOP
			}
		}
	} else if (comma_count == 4) {	// IF THERA ARE FOUR COMMAS; THE ARGUMENT LOOKS LIKE *GEN, 1, 1 - GEN, 1, 2*
		e = "-";											// SEARCH ALL "-"
		std::regex_search(this->search_argument, m, e);

		std::string prefix = m.prefix().str();	// GET PART BEFORE "-"
		std::string suffix = m.suffix().str();	// GET PART AFTER "-"

		e = "\\w+";	// SEARCH EVERY WORD

		for (int i = 0; i < 3; i++) {	// FOR EVERY POSITION
			std::regex_search(prefix, m, e);				// FIND EVERY WORD
			pos[i][0] = m.str();	// PUSH BACK TO BOOK / CHAPTER / VERSE
			prefix = m.suffix().str();							// SET "PREFIX" TO STRING AFTER FOUND WORD

			std::regex_search(suffix, m, e);				// JUST SAME AS THE BEFORE BUT AFTER THE "-"
			pos[i][1] = m.str();
			suffix = m.suffix().str();
		}
	}
	// 1Mo, 1, 2 - 4

	this->positions[0] = pos[0][0] + ", " + pos[1][0] + ", " + pos[2][0];
	this->positions[1] = pos[0][1] + ", " + pos[1][1] + ", " + pos[2][1];

	if (pos[0][1] == "" || pos[1][1] == "" || pos[2][1] == "") {
		return false;
	}

	return true;
}

void SearchEngine::interpret_argument(std::string * arg) {

	// -- CHECK QUOTES

	std::regex e("\".[^\"]*\"");	//	EVERYTHING WHICH HAS QUOTES AS BORDERS AND DOES NOT CONTAIN BORDERS
	std::smatch m;
	std::vector<std::string> static_expressions;	//	EVERY EXPRESSION WITH QUOTES BELONGS INTO THIS VECTOR

	std::string arg_copy = *arg;										//	COPY ARGUMENTS FOR SEARCHING THE QUOTES

	while (std::regex_search(arg_copy, m, e)) {		//	WHILE REGEX_SEARCH FINDS SOMETHING
		static_expressions.push_back(m.str());			//	ADD QUOTED STRINGS TO THIS VECTOR
		arg_copy = m.suffix().str();								//	USE STRING AFTER FOUND PART FOR NEXT SEARCH STATEMENT
	}

	*arg = regex_replace(*arg, e, "&ç&€");		//	REPLACE EVERY QUOTED PART WITH "&ç&€"

	// -- WORD SUBDIVISION

	e = "[\\w\\*]+";	//	SELECT EVERY WORD (WITH FOLLOWING "*") EXCEPT "&ç&€"
	*arg = std::regex_replace(*arg, e, "\\b$&\\b");		//	ADD "\b" AT THE END AND BEGINNING

	e = "\\*";																		//	SELECT EVERY "*"
	*arg = std::regex_replace(*arg, e, "\\w*");		//	REPLACE IT WHITH [:WORD_CONTAINING_UMLAUTS:]*

	e = " ";																			//	SELECT EVERY [:SPACE:]

	if (std::regex_search(*arg, e)) {							//	IF THERE ARE SPACES
		*arg = "(" + *arg + ")";											//	PUT STRING IN PARANTHESES
		*arg = std::regex_replace(*arg, e, "|");			//	PUT A "OR"-SIGN BETWEEN EVERY WORD
	}

	// -- FOR EVERY ELEMENT IN VECTOR INSERT IN THE OLD PLACE

	for (std::vector<std::string>::iterator i = static_expressions.begin(); i != static_expressions.end(); i++) {
		e = "\\b" + W + "+\\b";															//	SELECT EVERY WORD
		*i = regex_replace(*i, e, "\\b$&\\b");							//	PUT "\b" AT THE END AND BEGINNING

		e = "\\*";																					//	SEARCH FOR EVERY "*"
		*i = regex_replace(*i, e, "\\*");										//	REPLACE WITH "\*"

		e = "&ç&€";																	//	SELECT EVERY "&ç&€"

		if (std::regex_search(*arg, m, e))	{									//	IF THERE ARE ANY "&ç&€"
			*arg = m.prefix().str() + *i + m.suffix().str();		//	REPLACE IT WITH THE QUOTED STATEMENT
		}
	}

	e = "\"";																							//	SELECT EVERY QUOTE
	*arg = std::regex_replace(*arg, e, "");									// 	DELETE THE QUOTE
}

void SearchEngine::mark_result(std::string * text) {

	std::regex e(this->interpreted_argument);
	*text = std::regex_replace(*text, e, this->mark_argument);
}
