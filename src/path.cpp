#include "path.hpp"

std::string DATA(const std::string & object) {
	std::string output;
	#ifndef __LINUX__
	output = "data/" + object;
	if (getenv("SNAP")) {
		output = getenv("SNAP") + ("/" + output);
	}
	#endif

	std::cout << output << '\n';
	return output;
}
