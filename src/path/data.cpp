#include "../path.hpp"

#ifdef __linux__
std::string DATA(const std::string & object) {
	std::string output;

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

	return output;
}

#else
std::string DATA(const std::string & object) {
	return "data/" + object;
}
#endif
