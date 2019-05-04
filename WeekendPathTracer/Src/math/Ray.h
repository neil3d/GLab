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

	/*
	 * p(t) = origin + t*direction
	*/
	struct Ray {
		vec3 origin;
		vec3 direction;

		Ray(const vec3& inOrigin, const vec3& inDir) {
			origin = inOrigin;
			direction = glm::normalize(inDir);
		}

		vec3 getPoint(float t) {
			return origin + direction * t;
		}
	};

}  // end of namespace Neil3D