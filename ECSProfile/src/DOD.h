#pragma once
#include <vector>

#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <glm/gtc/matrix_transform.hpp>

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
  virtual void tick(float deltaTime, void* components, int count) override {
    Transform* transformData = static_cast<Transform*>(components);

    for (int i = 0; i < count; i++) {
      Transform& trans = transformData[i];

      trans.mLocalToWorld = mat4(1);
      trans.mLocalToWorld =
          glm::translate(trans.mLocalToWorld, trans.mPosition);
      trans.mLocalToWorld *= glm::mat4_cast(trans.mRotation);
      trans.mLocalToWorld = glm::scale(trans.mLocalToWorld, trans.mScale);
    }
  }
};

class World {
 public:
  World(int entityCount) { mTransformData.resize(entityCount); }

  void tick(float deltaTime) {
    mSceneGraph.tick(deltaTime, &(mTransformData[0]),
                     (int)mTransformData.size());
  }

 private:
  SceneGraph mSceneGraph;
  vector<Transform> mTransformData;
};

}  // namespace DOD
