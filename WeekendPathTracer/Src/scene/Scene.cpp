#include "stdafx.h"
#include "Scene.h"

namespace Neil3D {

	Scene::Scene() {}


	Scene::~Scene() {}

	void Scene::visit(SceneVisitor * visitor) {
		for (auto& node : mRootNodes) {
			visitor->acceptSceneNode(node.get());
		}
	}

}  // end of namespace Neil3D