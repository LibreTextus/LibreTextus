#include "path.hpp"

std::string DATA(const std::string & object) {
	std::string output;

#ifdef __linux__
	std::vector<char> buf(400);
	ssize_t len;
	
	do {
		buf.resize(buf.size() + 100);
		len = readlink("/proc/self/exe", &(buf[0]), buf.size());
	} while (buf.size() == len);

	buf[len] = '\0';
	output = std::string(&(buf[0]));

	output = output.substr(0, output.find_last_of("/") + 1);
	output += "data/" + object;
#else	
	output = "data/" + object;
#endif

	return output;
}

std::string HOME(const std::string & object) {
	std::string output;
	#ifdef __linux__
	output = (getenv("SNAP_USER_COMMON") == NULL ? getenv("HOME") : getenv("SNAP_USER_COMMON"));
	output += "/.libre_textus/" + object;
	#endif

	return output;
}
