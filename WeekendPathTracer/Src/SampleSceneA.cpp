#include "stdafx.h"
#include "SampleSceneA.h"
#include "scene/Sphere.h"
#include "scene/Plane.h"
#include "material/Lambert.h"
#include "material/Metal.h"

namespace Neil3D {

	SampleSceneA::SampleSceneA() {}


	SampleSceneA::~SampleSceneA() {}

	void SampleSceneA::initSceneContent() {

#if 0
		Plane::Ptr ground = createNode<Plane>(_T("GroundPlane"));
		ground->createMaterial<Lambert>();
#endif

		{
			Sphere::Ptr sphere = createNode<Sphere>(_T("Sphere_01"));
			sphere->setParam(vec3(0, 0, -1), 0.5f);
			sphere->createMaterial<Lambert>();

		}
		{
			Sphere::Ptr sphere = createNode<Sphere>(_T("Sphere_02"));
			sphere->setParam(vec3(0, -100.5f, -1), 100);
			sphere->createMaterial<Lambert>();
		}
		{
			Sphere::Ptr sphere = createNode<Sphere>(_T("Sphere_03"));
			sphere->setParam(vec3(1, 0, -1), 0.5f);
			sphere->createMaterial<Metal>();
		}
		{
			Sphere::Ptr sphere = createNode<Sphere>(_T("Sphere_04"));
			sphere->setParam(vec3(-1, 0, -1), 0.5f);
			sphere->createMaterial<Metal>();
		}
	}
}  // end of namespace Neil3D