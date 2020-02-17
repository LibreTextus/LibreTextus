#include "search_engine.hpp"

SearchEngine::SearchEngine(std::string file_path, std::string names_path) {
	this->file = YAML::LoadFile(file_path);
	this->names = YAML::LoadFile(names_path);

	this->last_result = nullptr;

	W = "[\\w\\u00C0-\\u024f]";
}

void SearchEngine::set_search_argument(std::string arg) {
	this->search_argument = arg;
	this->interpreted_argument = arg;
	interpret_argument(&this->interpreted_argument);

	if (this->last_result != nullptr) {
		delete [] this->last_result;
	}
	this->last_result = nullptr;
}

void SearchEngine::set_mark_argument(std::string arg) {
	this->mark_argument = arg;
}

void SearchEngine::set_header_argument(std::string arg) {
	this->header_argument = arg;
}

void SearchEngine::set_source(std::string path) {
	this->file = YAML::LoadFile(path);

	delete [] this->last_result;
	this->last_result = nullptr;
}

std::string SearchEngine::get_verse(std::string book, std::string chapter, std::string verse) {
	if (this->file[book][chapter][verse])
		return this->file[book][chapter][verse].as<std::string>();
	else
		return "~~~";
}

float SearchEngine::get_progress() {
	int progress = 0;
	for (YAML::const_iterator i = this->file.begin(); i != this->file.end(); i++) {
		progress++;
		if (i->first.as<std::string>() == this->last_search_results.back()[0]) {
			return (progress / 66.0);
		}
	}

	return 0;
}

bool SearchEngine::search(std::string * text) {
	if (this->last_result == nullptr) {
		this->last_result = new YAML::const_iterator[3];

		this->last_search_results.clear();

		this->last_result[0] = this->file.begin();
		this->last_result[1] = this->last_result[0]->second.begin();
		this->last_result[2] = this->last_result[1]->second.begin();

		if (search_book(text)) {
			this->is_book = true;
			return true;
		} else {
			this->is_book = false;

			delete [] this->last_result;
			this->last_result = new YAML::const_iterator[3];

			this->last_result[0] = this->file.begin();
			this->last_result[1] = this->last_result[0]->second.begin();
			this->last_result[2] = this->last_result[1]->second.begin();

			return search_word(text);
		}
	} else {
		if (this->is_book) {
			return search_book(text);
		}
		else {
			return search_word(text);
		}
	}
}

bool SearchEngine::search_book(std::string * text) {

	std::string positions[3][2] = {{"", ""}, {"", ""}, {"", ""}}; //	RESULT RANGE

	std::regex e(",");	// REGEX ARGUMENT
	std::smatch m;			// REGEX MATCH

	int comma_count = 0;	// NUMBER OF COMMAS

	std::string arg_copy = this->search_argument;	// COPY ARG FOR COUNT COMMAS

	while (std::regex_search(arg_copy, m, e)) {	// WHILE COMMA FOUND
		comma_count++;														// ADD ONE TO COMMA_COUNT
		arg_copy = m.suffix().str();							// ARG_COPY TO STRING AFTER FOUND COMMA
	}

	for (YAML::const_iterator i = this->names.begin(); i != this->names.end(); i++) {	// FOR ALL POSSIBLE BOOK NAMES
		for (YAML::const_iterator x = i->second.begin(); x != i->second.end(); x++) {		// FOR ALL ALL POSSIBLE SPELLINGS
			e = "\\b" + x->as<std::string>() + "\\b";																			// FIND SPELLING
			this->search_argument = std::regex_replace(this->search_argument, e, i->first.as<std::string>());									// REPLACE SPELLING WITH DEFAULT SPELLING : 1Mo -> GEN
		}
	}

	e = " ";															// FIND ALL SPACES
	this->search_argument = std::regex_replace(this->search_argument, e, "");	// AND REPLACE THEM WITH NOTHING (DELETE)

	if (comma_count == 2) {	// IF THERE ARE TWO COMMAS; THE ARGUMENT LOOKS LIKE *GEN, 1, 1 - 2*
		e = "[\\w-]+";	// ALL WORD-CHARACTERS [a-zA-z0-9]
		arg_copy = this->search_argument;	// COPY ARGUMENT FOR FIND WORDS

		for (int i = 0; i < 3; i++) {	// FOR EVERY ELEMENT OF POSITION-MAP
			std::regex_search(arg_copy, m, e);	// SEARCH NEXT WORD

			positions[i][0] = m.str();		// ADD POSITION
			arg_copy = m.suffix().str();				// ARG_COPY TO STRING AFTER FOUND WORD
		}

		e = "-";	// SEARCH ALL "-"

		std::string part;	// USED FOR REGEX_SEARCH

		for (int i = 0; i < 3; i++) {
			part = positions[i][0];				// PART FOR LOOKING IF THERE IS AN "-"
			if (std::regex_search(part, m, e)) {					// IF THERE IS AN "-"
				positions[i][0] = m.prefix().str();	// POSITION RANGE STARTS BEFORE THE "-"
				positions[i][1] = m.suffix().str();	// POSITION RANGE STOPS AFTER THE "-"

			} else {
				positions[i][1] = positions[i][0];	// IF THERE ARE NO "-" END EQUALS STOP
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
			positions[i][0] = m.str();	// PUSH BACK TO BOOK / CHAPTER / VERSE
			prefix = m.suffix().str();							// SET "PREFIX" TO STRING AFTER FOUND WORD

			std::regex_search(suffix, m, e);				// JUST SAME AS THE BEFORE BUT AFTER THE "-"
			positions[i][1] = m.str();
			suffix = m.suffix().str();
		}
	}

	// 1Mo, 1, 2 - 4

	if (positions[0][1] == "" ||			// IF THERE IS SOMETHING MISSING EXIT
			positions[1][1] == "" ||	// TODO: ADD WHOLE CHAPTER IF VERSE MISSING
			positions[2][1] == "") {
		return false;
	}


	bool begin = !(this->last_result[0] == this->file.begin() &&
								 this->last_result[1] == this->last_result[0]->second.begin() &&
							 	 this->last_result[2] == this->last_result[1]->second.begin());

	bool end = false;


	while (this->last_result[0] != this->file.end() && !end){
		while (this->last_result[1] != this->last_result[0]->second.end() && !end){
			for (; this->last_result[2] != this->last_result[1]->second.end() && !end; this->last_result[2]++){

				if (this->last_result[0]->first.as<std::string>() == positions[0][0] &&
						this->last_result[1]->first.as<std::string>() == positions[1][0] &&
						this->last_result[2]->first.as<std::string>() == positions[2][0]) {
							std::cout << "WHAT" << '\n';
							begin = true;
				}

				if (this->last_result[0]->first.as<std::string>() == positions[0][1] &&
						this->last_result[1]->first.as<std::string>() == positions[1][1] &&
						this->last_result[2]->first.as<std::string>() == positions[2][1]) {
							end = true;
				}

				if (begin) {

					this->add_header(text);

					*text += this->last_result[2]->second.as<std::string>();

					this->last_search_results.push_back({
						this->last_result[0]->first.as<std::string>(),
						this->last_result[1]->first.as<std::string>(),
						this->last_result[2]->first.as<std::string>()
					});

					this->last_result[2]++;

					if (this->last_result[2] == this->last_result[1]->second.end()) {
						this->last_result[1]++;

						if (this->last_result[1] == this->last_result[0]->second.end()) {
							this->last_result[0]++;

							if (this->last_result[0] == this->file.end()) {
								this->last_result[0] = this->file.end();
								this->last_result[1] = this->last_result[0]->second.end();
								this->last_result[2] = this->last_result[1]->second.end();
							} else {
								this->last_result[1] = this->last_result[0]->second.begin();
								this->last_result[2] = this->last_result[1]->second.begin();
							}

						} else {
							this->last_result[2] = this->last_result[1]->second.begin();
						}
					}

					if (end) {
						this->last_result[0] = this->file.end();
						this->last_result[1] = this->last_result[0]->second.end();
						this->last_result[2] = this->last_result[1]->second.end();
					}

					return true;
				}
			}
			this->last_result[1]++;

			if (this->last_result[1] != this->last_result[0]->second.end()) {
				this->last_result[2] = this->last_result[1]->second.begin();
			}
		}

		this->last_result[0]++;

		if (this->last_result[0] != this->file.end()) {
			this->last_result[1] = this->last_result[0]->second.begin();
			this->last_result[2] = this->last_result[1]->second.begin();
		}
	}

	return false;
}

bool SearchEngine::search_word(std::string * text) {


	std::regex e(this->interpreted_argument);
	// -- BOOK LOOP

	while (this->last_result[0] != this->file.end()) {

		// -- CHAPTER LOOP

		while (this->last_result[1] != this->last_result[0]->second.end()) {

			// -- VERSE LOOP

			for (; this->last_result[2] != this->last_result[1]->second.end(); this->last_result[2]++) {

				if (std::regex_search(this->last_result[2]->second.as<std::string>(), e)) {	//	IF THERE IS THE EXPRESSION SEARCHED FOR
					add_header(text);
					*text += this->last_result[2]->second.as<std::string>();
					mark_result(text);

					this->last_search_results.push_back({
						this->last_result[0]->first.as<std::string>(),
						this->last_result[1]->first.as<std::string>(),
						this->last_result[2]->first.as<std::string>()
					});

					this->last_result[2]++;

					if (this->last_result[2] == this->last_result[1]->second.end()) {
						this->last_result[1]++;

						if (this->last_result[1] == this->last_result[0]->second.end()) {
							this->last_result[0]++;

							if (this->last_result[0] == this->file.end()) {
								this->last_result[0] = this->file.end();
								this->last_result[1] = this->last_result[0]->second.end();
								this->last_result[2] = this->last_result[1]->second.end();
							} else {
								this->last_result[1] = this->last_result[0]->second.begin();
								this->last_result[2] = this->last_result[1]->second.begin();
							}

						} else {
							this->last_result[2] = this->last_result[1]->second.begin();
						}
					}
					return true;
				}
			}

			this->last_result[1]++;

			if (this->last_result[1] != this->last_result[0]->second.end()) {
				this->last_result[2] = this->last_result[1]->second.begin();
			}
		}

		this->last_result[0]++;

		if (this->last_result[0] != this->file.end()) {
			this->last_result[1] = this->last_result[0]->second.begin();
			this->last_result[2] = this->last_result[1]->second.begin();
		}

	}
	return false;
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

void SearchEngine::add_header(std::string * text) {

	std::regex e("\\$\\&");
	*text = std::regex_replace(this->header_argument, e, this->last_result[0]->first.as<std::string>() + ", " +
																												this->last_result[1]->first.as<std::string>() + ", " +
																												this->last_result[2]->first.as<std::string>());

	*text += "\n\n";
}
