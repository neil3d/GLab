/**
 *	A Happy Weekend Path Tracer
 *
 *	Author: Neil
 *	Date:	May, 2019
 *	See:	https://neil3d.github.io
 */

#pragma once
#include <memory>
#include "../math/Ray.h"
#include "../scene/HitRecord.h"

namespace Neil3D {

	struct Material {
		typedef std::shared_ptr<Material> Ptr;

		virtual bool scatter(const Ray& inRay, const HitRecord& rec, vec3& outAttenuation, Ray& outScattered) const = 0;
	};
}  // end of namespace Neil3D