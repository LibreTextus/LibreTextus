#include "SearchEngine.hpp"

SearchEngine::SearchEngine(std::string file_path, std::string names_path) {
	this->file = YAML::LoadFile(file_path);
	this->names = YAML::LoadFile(names_path);

	W = "[\\w\\u00C0-\\u024f]";
}


YAML::Node SearchEngine::search(std::string arg) {
	YAML::Node output = search_book(arg);

	if (!output.IsNull())
		return output;
	 else
		return search_word(arg);
}

YAML::Node SearchEngine::search_book(std::string arg) {
	YAML::Node output;

	YAML::Node positions = YAML::Load("book: []\nchapter: []\nverse: []"); //	RESULT RANGE

	std::regex e(",");	// REGEX ARGUMENT
	std::smatch m;			// REGEX MATCH

	int comma_count = 0;	// NUMBER OF COMMAS

	std::string arg_copy = arg;	// COPY ARG FOR COUNT COMMAS

	while (std::regex_search(arg_copy, m, e)) {	// WHILE COMMA FOUND
		comma_count++;														// ADD ONE TO COMMA_COUNT
		arg_copy = m.suffix().str();							// ARG_COPY TO STRING AFTER FOUND COMMA
	}

	for (YAML::const_iterator i = this->names.begin(); i != this->names.end(); i++) {	// FOR ALL POSSIBLE BOOK NAMES
		for (YAML::const_iterator x = i->second.begin(); x != i->second.end(); x++) {		// FOR ALL ALL POSSIBLE SPELLINGS
			e = "\\b" + x->as<std::string>() + "\\b";																			// FIND SPELLING
			arg = std::regex_replace(arg, e, i->first.as<std::string>());									// REPLACE SPELLING WITH DEFAULT SPELLING : 1Mo -> GEN
		}
	}

	e = " ";															// FIND ALL SPACES
	arg = std::regex_replace(arg, e, "");	// AND REPLACE THEM WITH NOTHING (DELETE)

	if (comma_count == 2) {	// IF THERE ARE TWO COMMAS; THE ARGUMENT LOOKS LIKE *GEN, 1, 1 - 2*
		e = "[\\w-]+";	// ALL WORD-CHARACTERS [a-zA-z0-9]
		arg_copy = arg;	// COPY ARGUMENT FOR FIND WORDS

		for (YAML::const_iterator i = positions.begin(); i != positions.end(); i++) {	// FOR EVERY ELEMENT OF POSITION-MAP
			std::regex_search(arg_copy, m, e);	// SEARCH NEXT WORD

			positions[i->first][0] = m.str();		// ADD POSITION
			arg_copy = m.suffix().str();				// ARG_COPY TO STRING AFTER FOUND WORD
		}

		e = "-";	// SEARCH ALL "-"

		std::string part;	// USED FOR REGEX_SEARCH

		for (YAML::const_iterator i = positions.begin(); i != positions.end(); i++) {
			part = i->second[0].as<std::string>();				// PART FOR LOOKING IF THERE IS AN "-"
			if (std::regex_search(part, m, e)) {					// IF THERE IS AN "-"
				positions[i->first][0] = m.prefix().str();	// POSITION RANGE STARTS BEFORE THE "-"
				positions[i->first][1] = m.suffix().str();	// POSITION RANGE STOPS AFTER THE "-"

			} else {
				positions[i->first][1] = i->second[0].as<std::string>();	// IF THERE ARE NO "-" END EQUALS STOP
			}
		}

	} else if (comma_count == 4) {	// IF THERA ARE FOUR COMMAS; THE ARGUMENT LOOKS LIKE *GEN, 1, 1 - GEN, 1, 2*
		e = "-";											// SEARCH ALL "-"
		std::regex_search(arg, m, e);

		std::string prefix = m.prefix().str();	// GET PART BEFORE "-"
		std::string suffix = m.suffix().str();	// GET PART AFTER "-"

		e = "\\w+";	// SEARCH EVERY WORD

		for (YAML::const_iterator i = positions.begin(); i != positions.end(); i++) {	// FOR EVERY POSITION
			std::regex_search(prefix, m, e);				// FIND EVERY WORD
			positions[i->first].push_back(m.str());	// PUSH BACK TO BOOK / CHAPTER / VERSE
			prefix = m.suffix().str();							// SET "PREFIX" TO STRING AFTER FOUND WORD

			std::regex_search(suffix, m, e);				// JUST SAME AS THE BEFORE BUT AFTER THE "-"
			positions[i->first].push_back(m.str());
			suffix = m.suffix().str();
		}
	}

	// 1Mo, 1, 2 - 4

	if (!positions["book"].as<std::vector<std::string>>().size() ||			// IF THERE IS SOMETHING MISSING EXIT
			!positions["chapter"].as<std::vector<std::string>>().size() ||	// TODO: ADD WHOLE CHAPTER IF VERSE MISSING
			!positions["verse"].as<std::vector<std::string>>().size()) {
		return output;
	}

	bool begin = false;
	bool end = false;

	for (YAML::const_iterator book = this->file.begin(); book != this->file.end() && !end; book++){
		for (YAML::const_iterator chapter = book->second.begin(); chapter != book->second.end() && !end; chapter++){
			for (YAML::const_iterator verse = chapter->second.begin(); verse != chapter->second.end() && !end; verse++){

				if (book->first.as<std::string>() == positions["book"][0].as<std::string>() &&
						chapter->first.as<std::string>() == positions["chapter"][0].as<std::string>() &&
						verse->first.as<std::string>() == positions["verse"][0].as<std::string>()) {
							begin = true;
				}

				if (begin) {
					output[book->first][chapter->first][verse->first] = verse->second;
				}

				if (book->first.as<std::string>() == positions["book"][1].as<std::string>() &&
						chapter->first.as<std::string>() == positions["chapter"][1].as<std::string>() &&
						verse->first.as<std::string>() == positions["verse"][1].as<std::string>()) {
							end = true;
				}
			}
		}
	}
	return output;
}

YAML::Node SearchEngine::search_word(std::string arg) {

	interpret_argument(arg);

	std::regex e(arg);

	YAML::Node output;																		//	NODE WHICH WILL BE RETURNED

	// -- BOOK LOOP

	for (YAML::const_iterator book = this->file.begin(); book != this->file.end(); book++) {

		// -- CHAPTER LOOP

		for (YAML::const_iterator chapter = book->second.begin(); chapter != book->second.end(); chapter++) {

			// -- VERSE LOOP

			for (YAML::const_iterator verse = chapter->second.begin(); verse != chapter->second.end(); verse++) {

				if (std::regex_search(verse->second.as<std::string>(), e)) {	//	IF THERE IS THE EXPRESSION SEARCHED FOR
					output[book->first.as<std::string>()][chapter->first.as<std::string>()]		//	INSERT VERSE UNDER [BOOK][CHAPTER][VERSE]
								[verse->first.as<std::string>()] = verse->second.as<std::string>();	//	IN OUTPUT NODE
				}
			}
		}
	}

	return output;	// RETURN NODE
}

void SearchEngine::interpret_argument(std::string & arg) {

	// -- CHECK QUOTES

	std::regex e("\".[^\"]*\"");	//	EVERYTHING WHICH HAS QUOTES AS BORDERS AND DOES NOT CONTAIN BORDERS
	std::smatch m;
	std::vector<std::string> static_expressions;	//	EVERY EXPRESSION WITH QUOTES BELONGS INTO THIS VECTOR

	std::string arg_copy = arg;										//	COPY ARGUMENTS FOR SEARCHING THE QUOTES

	while (std::regex_search(arg_copy, m, e)) {		//	WHILE REGEX_SEARCH FINDS SOMETHING
		static_expressions.push_back(m.str());			//	ADD QUOTED STRINGS TO THIS VECTOR
		arg_copy = m.suffix().str();								//	USE STRING AFTER FOUND PART FOR NEXT SEARCH STATEMENT
	}

	arg = regex_replace(arg, e, "&ç&€");		//	REPLACE EVERY QUOTED PART WITH "&ç&€"

	// -- WORD SUBDIVISION

	e = "[\\w\\*]+";	//	SELECT EVERY WORD (WITH FOLLOWING "*") EXCEPT "&ç&€"
	arg = std::regex_replace(arg, e, "\\b$&\\b");		//	ADD "\b" AT THE END AND BEGINNING

	e = "\\*";																		//	SELECT EVERY "*"
	arg = std::regex_replace(arg, e, W + "*");		//	REPLACE IT WHITH [:WORD_CONTAINING_UMLAUTS:]*

	e = " ";																			//	SELECT EVERY [:SPACE:]

	if (std::regex_search(arg, e)) {							//	IF THERE ARE SPACES
		arg = "(" + arg + ")";											//	PUT STRING IN PARANTHESES
		arg = std::regex_replace(arg, e, "|");			//	PUT A "OR"-SIGN BETWEEN EVERY WORD
	}

	// -- FOR EVERY ELEMENT IN VECTOR INSERT IN THE OLD PLACE

	for (std::vector<std::string>::iterator i = static_expressions.begin(); i != static_expressions.end(); i++) {
		e = "\\b" + W + "+\\b";															//	SELECT EVERY WORD
		*i = regex_replace(*i, e, "\\b$&\\b");							//	PUT "\b" AT THE END AND BEGINNING

		e = "\\*";																					//	SEARCH FOR EVERY "*"
		*i = regex_replace(*i, e, "\\*");										//	REPLACE WITH "\*"

		e = "&ç&€";																	//	SELECT EVERY "&ç&€"

		if (std::regex_search(arg, m, e))	{									//	IF THERE ARE ANY "&ç&€"
			arg = m.prefix().str() + *i + m.suffix().str();		//	REPLACE IT WITH THE QUOTED STATEMENT
		}
	}

	e = "\"";																							//	SELECT EVERY QUOTE
	arg = std::regex_replace(arg, e, "");									// 	DELETE THE QUOTE
}

std::string SearchEngine::mark_result(std::string text, std::string arg, std::string mark_start, std::string mark_end) {
	interpret_argument(arg);

	std::regex e(arg);
	text = std::regex_replace(text, e, mark_start + "$&" + mark_end);

	return text;
}
