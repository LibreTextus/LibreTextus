#include "path.hpp"
#include <iostream>

std::string DATA(const std::string & object) {
	std::string output;
	output = "data/" + object;
	#ifndef __LINUX__
	if (getenv("SNAP")) {
		output = getenv("SNAP") + ("/" + output);
	}
	#endif

	return output;
}

std::string HOME(const std::string & object) {
	std::string output;
	#ifndef __LINUX__
	output = (getenv("SNAP_USER_COMMON") == NULL ? getenv("HOME") : getenv("SNAP_USER_COMMON"));
	output += "/.libre_textus/" + object;
	#endif

	return output;
}

std::string HOME() {
	return HOME("");
}
