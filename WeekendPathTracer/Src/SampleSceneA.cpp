#include "stdafx.h"
#include "SampleSceneA.h"
#include "scene/Sphere.h"

namespace Neil3D {

	SampleSceneA::SampleSceneA() {}


	SampleSceneA::~SampleSceneA() {}

	void SampleSceneA::initSceneContent() {

		Sphere::Ptr sphere = createNode<Sphere>(_T("Sphere_01"));
		sphere->setParam(vec3(0, 0, -1), 0.5f);
	}
}  // end of namespace Neil3D