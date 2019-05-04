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

	class Sphere : public SceneNode {
	public:
		typedef std::shared_ptr<Sphere> Ptr;

		Sphere(const std::wstring& name);
		virtual ~Sphere();

		void setParam(const vec3& center, float radius) {
			mCenter = center;
			mRadius = radius;
		}

		virtual bool hit(const Ray& ray, float tMin, float tMax, HitRecord& outRec) override;

	private:
		vec3 mCenter;
		float mRadius = 1;
	};

}  // end of namespace Neil3D