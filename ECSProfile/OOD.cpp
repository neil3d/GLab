#include "OOD.h"
#include "../thirdparty/glm/glm/gtc/matrix_transform.hpp"

namespace OOD {

void Transform::tick(float deltaTime) {
  mLocalToWorld = mat4(1);
  mLocalToWorld = glm::translate(mLocalToWorld, mPosition);
  mLocalToWorld *= glm::mat4_cast(mRotation);
  mLocalToWorld = glm::scale(mLocalToWorld, mScale);
}

void OOD::GameObject::tick(float deltaTime) {
  for (auto iter = mComponents.begin(); iter != mComponents.end(); ++iter) {
    (*iter)->tick(deltaTime);
  }
}

}  // namespace OOD