#include "search_engine.hpp"

void SearchEngine::interpret_argument(std::string * arg) {
	this->remove_unneeded_spaces(arg);
	this->cancel_out_regex_characters(arg);
	

	std::vector<std::string> static_expressions;
	this->create_placeholders(arg, &static_expressions);
	
	this->add_boundries(arg);
	
	this->replace_any_character_expression(arg);

	this->replace_and_expression(arg);
	
	this->replace_placeholders_with_argument(arg, &static_expressions);

	this->shorten_strong_expression(arg);
	this->remove_quotes(arg);
}

void SearchEngine::remove_unneeded_spaces(std::string * arg) {
	while (arg->back() == ' ') {
		arg->pop_back();
	}

	while (arg->front() == ' ') {
		*arg = arg->substr(1, std::string::npos);
	}
}

void SearchEngine::cancel_out_regex_characters(std::string * arg) {
	boost::regex e("[\\+\\*\\?\\^\\$\\.\\(\\)\\[\\]\\{\\}&\\|\\\\]");
	boost::smatch m;
	*arg = boost::regex_replace(*arg, e, "\\\\$&");
}

void SearchEngine::create_placeholders(std::string * arg, std::vector<std::string> * static_expressions) {
	boost::regex e = boost::regex("(\"|\\[str.*)[^\"]*(\"|\\])", boost::regex::icase);
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

		if (m.str() != "_INSERT_") {
			*arg += "((?<=[^\\w\u00C0-\uffff])|\\A)" + m.str() + "(?=[^\\w\u00C0-\uffff]|$)";
		} else {
			*arg += m.str();
		}

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
		*arg = boost::regex_replace(*arg, e, "&");
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

void SearchEngine::shorten_strong_expression(std::string * arg) {
	boost::regex e;
	boost::smatch m;

	e = "\\\\\\[str.*\\\\\\]";
	while(boost::regex_search(*arg, m, e)) {
		*arg = m.prefix().str() + "[" + m.str().substr(6, m.str().size() - 8) + "]" + m.suffix().str();
	}
}

void SearchEngine::remove_quotes(std::string * arg) {
	boost::regex e = boost::regex("\"");
	*arg = boost::regex_replace(*arg, e, "");
}
