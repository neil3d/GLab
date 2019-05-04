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

	struct Metal : public Material {
		typedef std::shared_ptr<Metal> Ptr;

		vec3 albedo = vec3(1, 0.765557f, 0.336057f);

		virtual bool scatter(const Ray& inRay, const HitRecord& rec, vec3& outAttenuation, Ray& outScattered) const {
			outAttenuation = albedo;

			vec3 reflected = glm::reflect(inRay.direction, rec.normal);
			outScattered = Ray(rec.p, reflected);

			return glm::dot(outScattered.direction, rec.normal) > 0;
		}
	};

}  // end of namespace Neil3D