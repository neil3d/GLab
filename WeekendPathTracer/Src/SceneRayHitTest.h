/**
 *	A Happy Weekend Path Tracer
 *
 *	Author: Neil
 *	Date:	May, 2019
 *	See:	https://neil3d.github.io
 */

#pragma once
#include "math/Ray.h"
#include "scene/SceneVisitor.h"

namespace Neil3D {

	class SceneRayHitTest : public SceneVisitor {
	public:
		SceneRayHitTest() {}
		virtual ~SceneRayHitTest() {}

		virtual void acceptSceneNode(SceneNode* node) override {
			float tMax = std::numeric_limits<float>::max();

			mHit = node->hit(mRay, 0, tMax, mHitRecord);
		}

	public:
		Ray mRay;
		bool mHit = false;
		HitRecord mHitRecord;
	};

}  // end of namespace Neil3D