#include "../package_manager.hpp"

void Libre::PackageManager::write_to_file() {
	std::ofstream fout(HOME("sources.xml"));
	if (fout.is_open()) {
		fout << this->sources_doc;
		fout.close();
	}
}
