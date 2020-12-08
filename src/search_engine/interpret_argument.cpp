#include "search_engine.hpp"

void SearchEngine::interpret_argument(std::string arg) {
	this->pop_strong_expressions(&arg);

	this->remove_unneeded_spaces(&arg);

	this->create_search_index(arg);

	this->cancel_out_regex_characters(&arg);

	std::vector<std::string> static_expressions;
	this->create_placeholders(&arg, &static_expressions);
	
	this->add_boundries(&arg);
	
	this->replace_any_character_expression(&arg);

	this->replace_and_expression(&arg);
	
	this->replace_placeholders_with_argument(&arg, &static_expressions);

	this->remove_quotes(&arg);

	this->search_argument.set_regex_string(arg);
}

void SearchEngine::pop_strong_expressions(std::string * arg) {
	boost::regex e("\\[str.*\\]");
	boost::smatch m;

	while(boost::regex_search(*arg, m, e)) {
		this->search_argument.append_strong(m.str().substr(5, m.str().size() - 6));
		*arg = m.prefix().str() + m.suffix().str();
	}
}

void SearchEngine::remove_unneeded_spaces(std::string * arg) {
	while (arg->back() == ' ') {
		arg->pop_back();
	}

	while (arg->front() == ' ') {
		*arg = arg->substr(1, std::string::npos);
	}

	boost::regex e(" [ ]+");
	*arg = boost::regex_replace(*arg, e, "");
}

void SearchEngine::cancel_out_regex_characters(std::string * arg) {
	boost::regex e("[\\+\\*\\?\\^\\$\\.\\(\\)\\[\\]\\{\\}&\\|\\\\]");
	*arg = boost::regex_replace(*arg, e, "\\\\$&");
}

void SearchEngine::create_placeholders(std::string * arg, std::vector<std::string> * static_expressions) {
	boost::regex e = boost::regex("\"[^\"]*\"", boost::regex::icase);
	boost::smatch m;

	std::string arg_copy = *arg;

	while (boost::regex_search(arg_copy, m, e)) {
		static_expressions->push_back(m.str());
		arg_copy = m.suffix().str();
	}

	*arg = boost::regex_replace(*arg, e, "_INSERT_");
}

void SearchEngine::add_boundries(std::string * arg) {
	boost::regex e = boost::regex("([\\w\u00C0-\uffff]|\\\\\\*)+", boost::regex::icase);
	boost::smatch m;

	std::string arg_copy = *arg;
	arg->clear();
	while (boost::regex_search(arg_copy, m, e)) {
		*arg += m.prefix();

		*arg += "((?<=[^\\w\u00C0-\uffff])|\\A)" + m.str() + "(?=[^\\w\u00C0-\uffff]|$)";

		arg_copy = m.suffix().str();
	}
}

void SearchEngine::replace_any_character_expression(std::string * arg) {
	boost::regex e = boost::regex("\\\\\\*");
	*arg = boost::regex_replace(*arg, e, "[\\\\w\u00C0-\uffff]*");
}

void SearchEngine::replace_and_expression(std::string * arg) {
	boost::regex e = boost::regex("[ ]+");

	if (boost::regex_search(*arg, e)) {
		*arg = "(" + boost::regex_replace(*arg, e, "|") + ")";
	}
}

void SearchEngine::replace_placeholders_with_argument(std::string * arg, std::vector<std::string> * static_expressions) {
	boost::regex e;
	boost::smatch m;

	for (std::vector<std::string>::iterator i = static_expressions->begin(); i != static_expressions->end(); i++) {
		if (i->front() != '[' && i->back() != ']') {
			e = "((?<=[^\\\\w\u00C0-\uffff])|\\\\A)$&(?=[^\\\\w\u00C0-\uffff]|$)";
			*i = boost::regex_replace(*i, e, "((?<=[^\\\\w\u00C0-\uffff])|\\\\A)$&(?=[^\\\\w\u00C0-\uffff]|$)");

			e = "\\*";
			*i = boost::regex_replace(*i, e, "\\*");
		}

		e = "_INSERT_";

		if (boost::regex_search(*arg, m, e))	{
			*arg = m.prefix().str() + *i + m.suffix().str();
		}
	}
}

void SearchEngine::remove_quotes(std::string * arg) {
	boost::regex e = boost::regex("\"");
	*arg = boost::regex_replace(*arg, e, "");
}

void SearchEngine::create_search_index(const std::string & arg) {
	boost::regex e("\"");
	boost::smatch m;
	std::string rarg(boost::regex_replace(arg, e, ""));
	uint2048_t idx = 1;

	std::string temp;

	for (char c : rarg) {
		if (c == ' ' && !temp.empty()) {
			this->search_argument.append_word(temp);
			temp.clear();
		} else if (c != ' ') {
			temp += c;
		}
	}

	if (!temp.empty())
		this->search_argument.append_word(temp);

	for (const std::string & w : this->search_argument.get_words()) {
		std::string word = w;
		std::transform(word.begin(), word.end(), word.begin(), [](char c) { return std::tolower(c);});
		if (this->matrix->get_words().find(word) != this->matrix->get_words().end()) {
			if (idx % this->matrix->get_words().at(word) != 0) {
				idx *= this->matrix->get_words().at(word);
			}
		} else {
			e = "\\*";
			
			if (boost::regex_search(w, m, e)) {
				this->search_argument.append_snippet(boost::regex_replace(w, e, "([\\w\u00C0-\uffff]|\\\\\\*)*"));
			} else {
				idx = 0;
			}

			break;
		}
	}

	this->search_argument.set_idx(idx);
}
