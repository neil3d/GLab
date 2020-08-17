#pragma once
#include <string>

namespace GLab {

class MyFileLoader {
 public:
  MyFileLoader& instance() {
    static MyFileLoader g_instance;
    return g_instance;
  }

  void addSearchPath(const std::string& szPath) {}

  std::string loadFileAsString(const std::string& szPath) {}
};
}  // namespace GLab