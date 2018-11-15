#pragma once

#include <list>
#include <memory>
#include <string>

#include "../External/glm/glm/ext.hpp"
#include "../External/glm/glm/glm.hpp"

using namespace std;
using namespace glm;

namespace OOD {

class GameObject;

class Component {
 public:
  typedef shared_ptr<Component> Ptr;

  Component(GameObject* obj) : mObject(obj) {}

  virtual void tick(float deltaTime) = 0;

 private:
  GameObject* mObject;
};

class Transform : public Component {
 public:
  typedef shared_ptr<Transform> Ptr;

  Transform(GameObject* obj) : Component(obj), mScale(1), mLocalToWorld(1) {}

  virtual void tick(float deltaTime) override;

 private:
  vec3 mPosition;
  quat mRotation;
  vec3 mScale;

  mat4 mLocalToWorld;
};

class GameObject {
 public:
  typedef shared_ptr<GameObject> Ptr;

  GameObject() {}

  template <typename T>
  shared_ptr<T> addComponent() {
    shared_ptr<T> component(new T(this));
    mComponents.push_back(component);
    return component;
  }

  void tick(float deltaTime);

 private:
  list<Component::Ptr> mComponents;

  const GameObject& operator=(const GameObject& other) = delete;
  GameObject(const GameObject& other) = delete;
};

}  // namespace OOD