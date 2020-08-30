#pragma once
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

namespace GKit {
class GApp {
 public:
  GApp() = default;
  virtual ~GApp() = default;

  void init(const char* szAppName);
  void createWindow(int width, int height, const char* szTitle);
  void mainLoop();
  void shutdown();

 protected:
  VkInstance _createVkInstance(const char* szAppName);
  VkPhysicalDevice _selectPhysicalDevice(bool dumpInfo);

 protected:
  VkInstance mVkInstance = VK_NULL_HANDLE;
  VkPhysicalDevice mVkPhysicalDevice = VK_NULL_HANDLE;

  GLFWwindow* mWindow = nullptr;

 public:
  GApp(const GApp&) = delete;
  GApp& operator=(const GApp&) = delete;
};
}  // namespace GKit