/**
 *	A Happy Weekend Path Tracer
 *
 *	Author: Neil
 *	Date:	May, 2019
 *	See:	https://neil3d.github.io
 */

#pragma once
#include "scene/Scene.h"

namespace Neil3D {

	class SampleSceneA : public Scene {
	public:
		SampleSceneA();
		virtual ~SampleSceneA();

		void initSceneContent();
	};

}  // end of namespace Neil3D