/**
 *	A Happy Weekend Path Tracer
 *
 *	Author: Neil
 *	Date:	May, 2019
 *	See:	https://neil3d.github.io
 */

#pragma once
#include "Material.h"

namespace Neil3D {

	struct Lambert : public Material {
		typedef std::shared_ptr<Lambert> Ptr;

		vec3 albedo = vec3(0.5f, 0.5f, 0.5f);

		virtual bool scatter(const Ray& inRay, const HitRecord& rec, vec3& outAttenuation, Ray& outScattered) const {
			outAttenuation = albedo;

			vec3 randInUnitSphere = glm::sphericalRand(1.0f);
			vec3 target = rec.p + rec.normal + randInUnitSphere;
			outScattered = Ray(rec.p, target - rec.p);
			return true;
		}

	};

}  // end of namespace Neil3D