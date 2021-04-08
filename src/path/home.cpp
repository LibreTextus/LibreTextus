#include "path.hpp"

#if defined(__linux__) || defined(__APPLE__)
std::string HOME(const std::string & object) {
	std::string output;

	if (getenv("LIBRETEXTUS_DATA"))
		output = std::string(getenv("LIBRETEXTUS_DATA")) + "/" + object;
	else {
		output = (getenv("SNAP_USER_COMMON") == NULL ? getenv("HOME") : getenv("SNAP_USER_COMMON"));
		output += "/.libre_textus/" + object;
	}

	return output;
}

#else

std::string HOME(const std::string & object) {
	std::string output;

	output = getenv("HOME");
	output += "/.libre_textus/" + object;

	return output;
}

#endif
