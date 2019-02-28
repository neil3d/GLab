#pragma once
#include <vector>

#include "../../thirdparty/glm/glm/ext.hpp"
#include "../../thirdparty/glm/glm/glm.hpp"

using namespace glm;
using namespace std;

namespace DOD {

struct Transform {
  vec3 mPosition;
  quat mRotation;
  vec3 mScale;

  mat4 mLocalToWorld;
};

class System {
 public:
  virtual void tick(float deltaTime, void* components, int count) = 0;
};

class SceneGraph : public System {
 public:
  virtual void tick(float deltaTime, void* components, int count) override;
};

class World {
 public:
  World(int entityCount);

  void tick(float deltaTime);

 private:
  SceneGraph mSceneGraph;
  vector<Transform> mTransformData;
};

}  // namespace DOD
