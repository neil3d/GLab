#define GL_SILENCE_DEPRECATION
#define GLFW_INCLUDE_GLCOREARB
#include <GLFW/glfw3.h>

#include <iostream>

#include "MyCamera.h"
#include "MyRenderer.h"
#include "MyScene.h"

int main(void) {
  // init glfw window & context
  if (!glfwInit()) return -1;

  constexpr int WIDTH = 1280;
  constexpr int HEIGHT = 720;

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

  GLFWwindow* window =
      glfwCreateWindow(WIDTH, HEIGHT, "Blinn-Phong Shading", nullptr, nullptr);
  if (!window) {
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window);

  // dump gl info
  std::cout << "GL_VENDOR: " << glGetString(GL_VENDOR) << std::endl
            << "GL_RENDERER: " << glGetString(GL_RENDERER) << std::endl
            << "GL_VERSION: " << glGetString(GL_VERSION) << std::endl
            << "GL_SHADING_LANGUAGE_VERSION: "
            << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;

  // init my scene, render, camera
  GLab::MyCamera camera;
  GLab::MyScene scene;
  GLab::MyRenderer renderer;

  scene.init();
  renderer.init();

  // main loop
  while (!glfwWindowShouldClose(window)) {
    renderer.render(&scene, &camera);
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  // shut down
  glfwTerminate();
  return 0;
}