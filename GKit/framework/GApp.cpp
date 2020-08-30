#include "GApp.h"

#include <GLFW/glfw3.h>

#include <iostream>

#include "GException.h"

namespace GKit {

void GApp::init() {
  /* Initialize GLFW library */
  if (!glfwInit()) {
    throw GException("GLFW init FAILED!");
  }

  std::cout << "Runing against GLFW " << glfwGetVersionString() << std::endl;
}

void GApp::createWindow(int width, int height, const char* szTitle) {
  GLFWwindow* window = nullptr;

  window = glfwCreateWindow(width, height, szTitle, nullptr, nullptr);
  if (!window) {
    throw GException("GLFW window create FAILED!");
  }
  mWindow = window;
}

void GApp::mainLoop() {
  /* Loop until the user closes the window */
  while (!glfwWindowShouldClose(mWindow)) {
    glfwSwapBuffers(mWindow);
    glfwPollEvents();
  }
}

void GApp::shutdown() { glfwTerminate(); }

}  // namespace GKit