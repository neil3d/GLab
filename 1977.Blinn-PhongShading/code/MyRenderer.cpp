#define GL_SILENCE_DEPRECATION
#define GLFW_INCLUDE_GLCOREARB
#include "MyRenderer.h"

#include <GLFW/glfw3.h>

namespace GLab {

void MyRenderer::init() {
  // load shader files

  // create GL program
}

void MyRenderer::render(MyScene* pScene, MyCamera* pCamera) {
  glClearColor(0.2f, 0.4f, 0.8f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
}

}  // namespace GLab
