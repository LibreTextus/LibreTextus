#ifndef PACKAGE_MANAGER
#define PACKAGE_MANAGER

#include <string>
#include <stdlib.h>
#include <experimental/filesystem>
#include "settings.hpp"

namespace Libre {
  class PackageManager {
  private:
    std::string root_path;
    Settings settings;

  public:
    PackageManager() = default;
    virtual ~PackageManager() = default;

		void check_updates();
    void init();
    void remove();
    void install();
    void disable();
    void enable();

		std::string get_root_path() {
			return this->root_path;
		}
  };
}

#endif
