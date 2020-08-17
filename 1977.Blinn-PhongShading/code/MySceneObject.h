#pragma once

#include <glm/glm.hpp>
#include <memory>

#include "GLMesh.h"
#include "MyMaterial.h"

namespace GLab {

/**
 * an object in scene
 */
class MySceneObject {
 public:
  typedef std::shared_ptr<MySceneObject> Ptr;

  const glm::mat4& getModelMatrix() const { return mModelMatrix; }

 protected:
  glm::mat4 mModelMatrix;
};

}  // namespace GLab
