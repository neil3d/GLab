#pragma once
struct GLFWwindow;

namespace GKit {
class GApp {
 public:
  GApp() = default;
  ~GApp() = default;

  void init();
  void createWindow(int width, int height, const char* szTitle);
  void mainLoop();
  void shutdown();

 private:
  GLFWwindow* mWindow = nullptr;

 public:
  GApp(const GApp&) = delete;
  GApp& operator=(const GApp&) = delete;
};
}  // namespace GKit