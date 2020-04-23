#include "search_engine.hpp"

// SEARCHENGINE::SEARCHENGINE --------------------------------------------------
// THIS IS THE CONSTRUCTOR OF THE SEARCHENGINE. IT LOADS THE SOURCE + NAMESFILE
// -----------------------------------------------------------------------------

SearchEngine::SearchEngine(std::string file_path, std::string names_path) {
	this->file = this->source_handler.get_source(file_path);
	this->names = this->source_handler.get_names(names_path);
	this->last_result = this->file.begin();

	W = "[\\w\\u00C0-\\u024f]";
}

// SEARCHENGINE::SET_SEARCH_ARGUMENT -------------------------------------------
// FUNCTION TO SET THE SEARCH ARGUMENT. IT WILL RESET THE LAST SEARCH RESULT
// -----------------------------------------------------------------------------

void SearchEngine::set_search_argument(std::string arg) {
	this->search_argument = arg;
	this->interpreted_argument = arg;
	interpret_argument(&this->interpreted_argument);

	this->is_book = this->search_position();
	this->last_search_results.clear();
	this->last_result = this->file.begin();
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
	this->file.clear();
	this->file = this->source_handler.get_source(path);

	this->last_result = this->file.begin();
}

// SEARCHENGINE::GET_VERSE -----------------------------------------------------
// RETURNS VERSE THE ARGUMENT HAS TO BE IN THES FORM: *BOOK, CHAPTER, VERSE*
// -----------------------------------------------------------------------------

std::string SearchEngine::get_verse(std::string p) {
	if (this->file.find(p) != this->file.end()) {
		return this->file[p];
	}
	else {
		return "~~~";
	}
}

// SEARCHENGINE::GET_PROGRESS --------------------------------------------------
// GET THE SEARCH PROGRESS
// -----------------------------------------------------------------------------

float SearchEngine::get_progress() {
	if (this->file.size()) {
		return static_cast<float>(std::distance(this->file.begin(), this->last_result)) / this->file.size();
	}

	return 0;
}

// SEARCHENGINE::SEARCH ------------------------------------------------------­­­--
// THIS FUNCTION WILL CALL THE SEARCH_BOOK OR THE SEARCH_WORD FUNCTION
// -----------------------------------------------------------------------------

bool SearchEngine::search(std::string * text) {
	if (this->is_book) {
		return search_book(text);
	}
	else {
		return search_word(text);
	}
}

// SEARCHENGINE::SEARCH_BOOK ---------------------------------------------------
// THIS FUNCTION RETURNS EVERY VERSE LOCATED IN THE ASKED POSITION
// -----------------------------------------------------------------------------

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

			this->last_search_results.push_back(this->last_result->first);

			this->last_result++;

			if (end) {
				this->last_result = this->file.end();
			}

			return true;
		}
		this->last_result++;
	}
}

// SEARCHENGINE::SEARCH_WORD ---------------------------------------------------
// THIS FUNCTION ITERATES THRUE THE BOOMAP AT RETURNS THE REGEX MACHES
// -----------------------------------------------------------------------------

bool SearchEngine::search_word(std::string * text) {

	std::regex e(this->interpreted_argument);
	// -- BOOK LOOP

	while (this->last_result != this->file.end()) {
		if (std::regex_search(this->last_result.value(), e)) {	//	IF THERE IS THE EXPRESSION SEARCHED FOR
			*text += this->last_result.value();
			mark_result(text);

			this->last_search_results.push_back(this->last_result->first);
			
			this->last_result++;

			return true;
		}
		this->last_result++;
	}

	return false;
}

// SEARCHENGINE::SEARCH_POSITION -----------------------------------------------
// THIS FUNCTION CHECKES IF THE SEARCH ARGUMENT IS A BOOK POSITION OR A NORMAL
// SEARCH ARGUMENT. IF IT IS A BOOK POSITION SET THE POSITION AND RETURNS TRUE
// -----------------------------------------------------------------------------

bool SearchEngine::search_position() {

	std::string arg_backup = this->search_argument;

	// ------------------------------------------
	// CREATE A TEMPORARY POSITION ARRAY
	// THIS ARRAY HAS THE FOLLOWING CONTENTS:
	// 	* { BOOK START, BOOK END }
	// 	* { CHAPTER START, CHAPTER END }
	// 	* { VERSE START, VERSE END }
	// ------------------------------------------

	std::string pos[3][2];

	for (int i = 0; i < 3; i++) {
		for (int x = 0; x < 2; x++) {
			pos[i][x] = "";
		}
	}

	// ------------------------------------------
	// COUNT THE NUMBER OF COMMAS TO KNOW IF THE
	// ARGUMENT HAS THIS FORM:
	//	*B, C, V - V*
	// OR THIR FORM:
	//	*B, C, V - B, C, V*
	// ------------------------------------------

	std::regex e(",");
	std::smatch m;

	int comma_count = 0;

	std::string arg_copy = this->search_argument;

	while (std::regex_search(arg_copy, m, e)) {
		comma_count++;
		arg_copy = m.suffix().str();
	}

	// -----------------------------------------
	// CHANGE THE POSSIBLE BOOK SHORTCUT TO THE
	// STANDART SHORTCUT. E.G. 1Mo -> GEN
	// -----------------------------------------

	for (Libre::NameMap::iterator i = this->names.begin(); i != this->names.end(); i++) {
		for (std::vector<std::string>::iterator x = i.value().begin(); x != i.value().end(); x++) {
			e = "\\b" + *x + "\\b";
			this->search_argument = std::regex_replace(this->search_argument, e, i->first);
		}
	}

	// ------------------------------------------
	// REMOVE ALL SPACES
	// ------------------------------------------

	e = " ";
	this->search_argument = std::regex_replace(this->search_argument, e, "");

	// ------------------------------------------
	// DIFFER BETWEEN TWO COMMAS AND FOUR COMMAS
	// ------------------------------------------

	if (comma_count == 2) {

		// ------------------------------------------
		// SPLIT THE ARGUMENT IN BOOK, CHAPTER, VERSE
		// BUT ALWAY TO THE 0 OF THE ARRAYS
		// ------------------------------------------

		e = "[\\w-]+";
		arg_copy = this->search_argument;

		for (int i = 0; i < 3; i++) {
			std::regex_search(arg_copy, m, e);

			pos[i][0] = m.str();
			arg_copy = m.suffix().str();
		}

		// ------------------------------------------
		// IF THERE IS A *-* SPLIT IT UP IN START END
		// IF THER IS NO *-* TAKE IT FOR START & END
		// ------------------------------------------

		e = "-";

		std::string part;

		for (int i = 0; i < 3; i++) {
			part = pos[i][0];
			if (std::regex_search(part, m, e)) {
				pos[i][0] = m.prefix().str();
				pos[i][1] = m.suffix().str();

			} else {
				pos[i][1] = pos[i][0];
			}
		}
	} else if (comma_count == 4) {

		// ------------------------------------------
		// SEARCH THE *-* FOR SPLITTING IT UP
		// ------------------------------------------

		e = "-";
		std::regex_search(this->search_argument, m, e);

		std::string prefix = m.prefix().str();
		std::string suffix = m.suffix().str();

		// ------------------------------------------
		// SET VARIABLE *PREFIX* AS START POSITION
		// SET VARIABLE *SUFFIX* AS END POSITION
		// ------------------------------------------

		e = "\\w+";

		for (int i = 0; i < 3; i++) {
			std::regex_search(prefix, m, e);
			pos[i][0] = m.str();
			prefix = m.suffix().str();

			std::regex_search(suffix, m, e);
			pos[i][1] = m.str();
			suffix = m.suffix().str();
		}
	}

	// ------------------------------------------
	// SET THE POSITION AND IF EVERY POSITION IS
	// KNOWN RETURN TRUE ELSE RESET SEARCH
	// ARGUMENT AND RETURN FALSE
	// ------------------------------------------

	this->positions[0] = pos[0][0] + ", " + pos[1][0] + ", " + pos[2][0];
	this->positions[1] = pos[0][1] + ", " + pos[1][1] + ", " + pos[2][1];

	if (pos[0][1] == "" || pos[1][1] == "" || pos[2][1] == "") {
		this->search_argument = arg_backup;
		return false;
	}

	return true;
}

// SEARCHENGINE::INTERPRET_ARGUMENT --------------------------------------------
// THIS FUNCTION TURNS THE SEARCH ARGUMENT INTO A REGEX ARGUMENT
// -----------------------------------------------------------------------------

void SearchEngine::interpret_argument(std::string * arg) {

	// ------------------------------------------
	// IF THERE ARE QUOTED WORDS REPLACE IT WITH
	// *&ç&€* AND AFTER EVERY MANIPULATION
	// INSERT THE QUOTED WORDS IN ITS PLACE
	// THE REPLACE STRING HAS TO BE NON-WORD
	// CHARACTERS THAT THEY WONT BE SELECTED
	// IN THE FOLLOWING PROCESS
	// ------------------------------------------

	std::regex e("\".[^\"]*\"");
	std::smatch m;
	std::vector<std::string> static_expressions;

	std::string arg_copy = *arg;

	while (std::regex_search(arg_copy, m, e)) {
		static_expressions.push_back(m.str());
		arg_copy = m.suffix().str();
	}

	*arg = regex_replace(*arg, e, "&ç&€");

	// ------------------------------------------
	// SELECT EVERY WORD AND LIST THEM IN
	// PARANTHESES WITH *OR* OPERATORS
	// ------------------------------------------

	e = "[\\w\\*]+";
	*arg = std::regex_replace(*arg, e, "\\b$&\\b");

	e = "\\*";
	*arg = std::regex_replace(*arg, e, "\\w*");

	e = " ";

	if (std::regex_search(*arg, e)) {
		*arg = "(" + *arg + ")";
		*arg = std::regex_replace(*arg, e, "|");
	}

	// ------------------------------------------
	// INSERT THE QUOTED WORDS ON THEIR POSITION
	// AND DELETE THE QUOTES
	// ------------------------------------------

	for (std::vector<std::string>::iterator i = static_expressions.begin(); i != static_expressions.end(); i++) {
		e = "\\b" + W + "+\\b";
		*i = regex_replace(*i, e, "\\b$&\\b");

		e = "\\*";
		*i = regex_replace(*i, e, "\\*");

		e = "&ç&€";

		if (std::regex_search(*arg, m, e))	{
			*arg = m.prefix().str() + *i + m.suffix().str();
		}
	}

	e = "\"";
	*arg = std::regex_replace(*arg, e, "");
}

// SEARCHENGINE::MARK_RESULT ---------------------------------------------------
// THIS FUNCTION REPLACES THE RESULT WITH THE RESULT WITH MARKS
// -----------------------------------------------------------------------------

void SearchEngine::mark_result(std::string * text) {
	std::regex e(this->interpreted_argument);
	*text = std::regex_replace(*text, e, this->mark_argument);
}
