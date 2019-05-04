/**
 *	A Happy Weekend Path Tracer
 *
 *	Author: Neil
 *	Date:	May, 2019
 *	See:	https://neil3d.github.io
 */
#pragma once

#include "SceneNode.h"

namespace Neil3D {

	class Plane : public SceneNode {
	public:
		typedef std::shared_ptr<Plane> Ptr;

		Plane(const std::wstring& name);
		virtual ~Plane();

		virtual bool hit(const Ray& ray, float tMin, float tMax, HitRecord& outRec) override;

	private:
		// (p-p0)¡¤n = 0
		vec3 mP0 = vec3(0, 0.5f, 0);
		vec3 mNormal = vec3(0, 1, 0);
	};

}  // end of namespace Neil3D