#include "../log.hpp"

void LOG(const std::string & message) {
	std::ofstream log_file;
	log_file.open(HOME("session.log"), std::ios_base::app);
	log_file << message << '\n';
	log_file.close();
}

void LOG_RESET() {
	std::ofstream log_file;
	log_file.open(HOME("session.log"), std::ofstream::out | std::ofstream::trunc);
	log_file.close();
}
