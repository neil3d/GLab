/**
 *	A Happy Weekend Path Tracer
 *
 *	Author: Neil
 *	Date:	May, 2019
 *	See:	https://neil3d.github.io
 */

#pragma once
#include "MathDefine.h"

namespace Neil3D {

	struct HitRecord {
		float t;
		vec3 p;
		vec3 normal;
	};

	/*
	 * p(t) = origin + t*direction
	*/
	struct Ray {
		vec3 origin;
		vec3 direction;

		Ray() :origin(0, 0, 0), direction(0, 1, 0) {

		}

		Ray(const vec3& inOrigin, const vec3& inDir) {
			origin = inOrigin;
			direction = glm::normalize(inDir);
		}

		vec3 getPoint(float t) const {
			return origin + direction * t;
		}
	};

}  // end of namespace Neil3D