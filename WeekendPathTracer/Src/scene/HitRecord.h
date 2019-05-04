/**
 *	A Happy Weekend Path Tracer
 *
 *	Author: Neil
 *	Date:	May, 2019
 *	See:	https://neil3d.github.io
 */

#pragma once
#include "../math/MathDefine.h"

namespace Neil3D {

	class SceneNode;
	struct Material;

	struct HitRecord {
		float t = 0;
		vec3 p;
		vec3 normal;
		Material* mtl = nullptr;
		SceneNode* node = nullptr;
	};

}  // end of namespace Neil3D