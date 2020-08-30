#include <iostream>

#include "framework/GApp.h"

using namespace GKit;

int main(void) {
  GApp app;
  app.init();
  app.createWindow(1280, 720, "Blinn-Phong Shading");
  app.mainLoop();
  app.shutdown();
  return 0;
}