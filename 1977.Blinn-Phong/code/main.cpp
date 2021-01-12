#include <iostream>

#include "framework/GApp.h"

using namespace GKit;

int main(void) {
  constexpr char* APP_NAME = "Blinn-Phong Shading";
  GApp app;
  app.init(APP_NAME);
  app.createWindow(1280, 720, APP_NAME);
  app.mainLoop();
  app.shutdown();
  return 0;
}