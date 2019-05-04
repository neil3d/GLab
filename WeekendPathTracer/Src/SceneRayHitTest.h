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

			HitRecord rec;
			bool hit = node->hit(mRay, 0, mClosest, rec);
			if (hit) {
				mHitAnything = true;
				mClosest = rec.t;
				mHitRecord = rec;
			}
		}

	public:
		float mClosest = std::numeric_limits<float>::max();

		Ray mRay;
		bool mHitAnything = false;
		HitRecord mHitRecord;
	};

}  // end of namespace Neil3D