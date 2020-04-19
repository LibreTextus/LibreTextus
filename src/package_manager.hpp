#ifndef PACKAGE_MANAGER
#define PACKAGE_MANAGER

#include <string>
#include <stdlib.h>
#include <experimental/filesystem>
#include "settings.hpp"
#include <iostream>

namespace Libre {
  class PackageManager {
  private:
    std::string root_path;
    Settings settings;

  public:
    PackageManager() = default;
    virtual ~PackageManager() = default;

    void init();
    void remove(std::string);
    void install(std::string);
    void disable(std::string);
    void enable(std::string);

		std::string get_root_path() {
			return this->root_path;
		}
  };
}

#endif
