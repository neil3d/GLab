#pragma once

#include <glm/glm.hpp>

namespace GLab {
class MyScene;
class MyCamera;
/**
 * a simple GL renderer implement Blinn-Phong shading model
 */
class MyRenderer {
    public:
    void init();
    void render(MyScene* pScene, MyCamera* pCamera);
};

}  // namespace GLab
