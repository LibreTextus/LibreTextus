#ifndef PACKAGE_MANAGER
#define PACKAGE_MANAGER

#include <string>
#include <stdlib.h>
#include <yaml-cpp/yaml.h>
#include <experimental/filesystem>
#include "settings.hpp"
#include <iostream>

namespace Libre {
  class PackageManager {
  private:
    std::string root_path;
    Settings settings;
		YAML::Node sources;

  public:
    PackageManager() = default;
    virtual ~PackageManager() = default;

    void init(YAML::Node sources);
    void remove(std::string);
    void install(std::string);
    void disable(std::string);
    void enable(std::string);
		std::vector<std::string> get_packages();

		std::string get_root_path() {
			return this->root_path;
		}
  };
}

#endif
