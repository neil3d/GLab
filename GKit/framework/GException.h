#pragma once

#include <exception>
#include <string>

namespace GKit {
class GException : public std::exception {
 public:
  GException(const std::string& szMessage) : mMessage(szMessage) {}

  virtual const char* what() const noexcept override {
    return mMessage.c_str();
  }

 private:
  std::string mMessage;
};
}  // namespace GKit