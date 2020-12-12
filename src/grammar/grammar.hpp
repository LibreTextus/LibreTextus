#ifndef LIBRE_GRAMMAR_MAP
#define LIBRE_GRAMMAR_MAP

#include <map>
#include <vector>
#include <string>

namespace Libre {
	class Grammar {
		private:
			typedef std::map<std::string, std::vector<std::string>> GrammarMap;
			GrammarMap grammar_map;
		public:
			Grammar();
			~Grammar() = default;
			GrammarMap * get_grammar_map() {
				return &this->grammar_map;
			}
	};
}

#endif
