#pragma once

#include <list>

#include "MyLight.h"
#include "MySceneObject.h"

namespace GLab {

/**
 * a simple test scene with three teapots
 */
class MyScene {
 public:
  void init();
  void tick();

 protected:
  std::list<MySceneObject::Ptr> mObjects;
  std::list<MyLight> mLights;
};

}  // namespace GLab
