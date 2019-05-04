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

	class SceneVisitor {
	public:
		virtual ~SceneVisitor() {}

		virtual void acceptSceneNode(SceneNode* node) = 0;
	};

}  // end of namespace Neil3D