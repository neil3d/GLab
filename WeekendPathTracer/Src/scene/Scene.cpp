#include "stdafx.h"
#include "Scene.h"

namespace Neil3D {

	Scene::Scene() {}


	Scene::~Scene() {}

	void Scene::visit(SceneVisitor * visitor) {
		for (auto& node : mRootNodes) {
			visitor->acceptSceneNode(this, node.get());
		}
	}

	bool Scene::hit(const Ray & ray, float tMin, float tMax, HitRecord & outRec) {

		bool hitAnything = false;
		float closestSoFar = tMax;
		HitRecord rec;

		for (auto& node : mRootNodes) {
			if (node->hit(ray, tMin, closestSoFar, rec)) {
				hitAnything = true;
				closestSoFar = rec.t;
				outRec = rec;
			}
		}// end of for

		return hitAnything;
	}

}  // end of namespace Neil3D