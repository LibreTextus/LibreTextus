#ifndef PACKAGE_MANAGER
#define PACKAGE_MANAGER

#include <string>
#include <gtkmm.h>
#include "settings.hpp"

namespace Libre {
  class PackageManager {
  private:
    std::string root_path;
    Settings settings;

  public:
    PackageManager() = default;
    virtual ~PackageManager() = default;

    void init();
    void remove();
    void install();
    void disable();
    void enable();
  };
}

#endif
