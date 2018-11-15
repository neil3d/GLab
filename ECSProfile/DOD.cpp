#include "../External/glm/glm/gtc/matrix_transform.hpp"
#include "DOD.h"

namespace DOD {

World::World(int entityCount) { mTransformData.resize(entityCount); }

void World::tick(float deltaTime) {
  mSceneGraph.tick(deltaTime, &(mTransformData[0]), (int)mTransformData.size());
}

void SceneGraph::tick(float deltaTime, void* components, int count) {
  Transform* transformData = static_cast<Transform*>(components);

  for (int i = 0; i < count; i++) {
    Transform& trans = transformData[i];

    trans.mLocalToWorld = mat4(1);
    trans.mLocalToWorld = glm::translate(trans.mLocalToWorld, trans.mPosition);
    trans.mLocalToWorld *= glm::mat4_cast(trans.mRotation);
    trans.mLocalToWorld = glm::scale(trans.mLocalToWorld, trans.mScale);
  }
}

}  // namespace DOD