/**
 *	A Happy Weekend Path Tracer
 *
 *	Author: Neil
 *	Date:	May, 2019
 *	See:	https://neil3d.github.io
 */

#pragma once
#include <string>
#include <memory>
#include "../math/Ray.h"

namespace Neil3D {

	class SceneNode {
	public:
		typedef std::shared_ptr<SceneNode> Ptr;

		SceneNode(const std::wstring& name) :mName(name) {

		}

		virtual ~SceneNode() {

		}

		virtual bool hit(const Ray& ray, float tMin, float tMax, HitRecord& outRec) = 0;

	protected:
		std::wstring mName;
	};

}  // end of namespace Neil3D