#ifndef SEQ_HPP
#define SEQ_HPP

#include <string>

namespace MD {

	enum STYLE {
		NORMAL = 0x0000,
		ITALIC = 0x0001,
		BOLD = 0x0002,
		STRIKETHROUGH = 0x0004,
		H1 = 0x0008,
		H2 = 0x0010,
		H3 = 0x0020,
		H4 = 0x0040,
		H5 = 0x0080,
		H6 = 0x0100,
		CODE = 0x0200,
		BLOCKQUOTES = 0x0400,
		HIDDEN = 0x0800
	};

	struct tagged_char {
		char c;
		int tag;

		tagged_char(const char & s, const int & i) {
			c = s;
			tag = i;
		}

		bool has_tag(const int & i) {
			return ((tag | i) == tag);
		}

		int get_tags() {
			return tag;
		}
	};
}

#endif
