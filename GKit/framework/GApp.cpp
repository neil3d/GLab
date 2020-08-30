#include "GApp.h"

#include <iostream>
#include <vector>

#include "GException.h"

namespace GKit {

void GApp::init(const char* szAppName) {
  // initialize GLFW library
  if (!glfwInit()) {
    throw GException("GLFW init FAILED!");
  }
  std::cout << "Runing against GLFW " << glfwGetVersionString() << std::endl;

  if (!glfwVulkanSupported()) {
    throw GException("GLFW Vulkan UNAVAILABLE!");
  }

  // vulkan
  mVkInstance = _createVkInstance(szAppName);
  mVkPhysicalDevice = _selectPhysicalDevice(true);
}

void GApp::createWindow(int width, int height, const char* szTitle) {
  GLFWwindow* window = nullptr;

  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  window = glfwCreateWindow(width, height, szTitle, nullptr, nullptr);
  if (!window) {
    throw GException("GLFW window create FAILED!");
  }
  mWindow = window;

  VkSurfaceKHR surface;
  VkResult res =
      glfwCreateWindowSurface(mVkInstance, window, nullptr, &surface);
}

void GApp::mainLoop() {
  /* Loop until the user closes the window */
  while (!glfwWindowShouldClose(mWindow)) {
    glfwSwapBuffers(mWindow);
    glfwPollEvents();
  }
}

void GApp::shutdown() {
  if (mVkInstance) {
    vkDestroyInstance(mVkInstance, nullptr);
    mVkInstance = VK_NULL_HANDLE;
  }
  mVkPhysicalDevice = VK_NULL_HANDLE;

  glfwTerminate();
}

VkInstance GApp::_createVkInstance(const char* szAppName) {
  // initialize the VkApplicationInfo structure
  VkApplicationInfo appInfo = {};
  appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
  appInfo.pNext = nullptr;
  appInfo.pApplicationName = szAppName;
  appInfo.applicationVersion = 1;
  appInfo.pEngineName = szAppName;
  appInfo.engineVersion = 1;
  appInfo.apiVersion = VK_API_VERSION_1_0;

  // initialize the VkInstanceCreateInfo structure
  VkInstanceCreateInfo instInfo = {};
  instInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
  instInfo.pNext = nullptr;
  instInfo.flags = 0;
  instInfo.pApplicationInfo = &appInfo;
  instInfo.enabledExtensionCount = 0;
  instInfo.ppEnabledExtensionNames = nullptr;
  instInfo.enabledLayerCount = 0;
  instInfo.ppEnabledLayerNames = nullptr;

  VkInstance inst = VK_NULL_HANDLE;
  VkResult res = vkCreateInstance(&instInfo, nullptr, &inst);
  if (res == VK_ERROR_INCOMPATIBLE_DRIVER) {
    throw GException("vkCreateInstance FAILED: NO compatible ICD.");
  } else if (res != VK_SUCCESS) {
    throw GException("vkCreateInstance FAILED.");
  }
  return inst;
}

VkPhysicalDevice GApp::_selectPhysicalDevice(bool dumpInfo) {
  uint32_t deviceCount = 0;
  VkResult res = vkEnumeratePhysicalDevices(mVkInstance, &deviceCount, nullptr);
  if (res != VK_SUCCESS) throw GException("vkEnumeratePhysicalDevices FAILED.");

  std::vector<VkPhysicalDevice> devices(deviceCount);
  res = vkEnumeratePhysicalDevices(mVkInstance, &deviceCount, devices.data());
  if (res != VK_SUCCESS) throw GException("vkEnumeratePhysicalDevices FAILED.");

  for (auto gpu : devices) {
    VkPhysicalDeviceProperties prop;
    vkGetPhysicalDeviceProperties(gpu, &prop);
    if (dumpInfo) {
      std::cout << "Vulkan physical device: " << prop.deviceName;
    }
  }  // end of for

  return devices[0];
}

}  // namespace GKit