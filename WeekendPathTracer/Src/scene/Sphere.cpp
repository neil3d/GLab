#include "stdafx.h"
#include "Sphere.h"

namespace Neil3D {

	Sphere::Sphere(const std::wstring& name) :SceneNode(name) {}


	Sphere::~Sphere() {}

	bool Sphere::hit(const Ray & ray, float tMin, float tMax, HitRecord & outRec) {

		vec3 center = mCenter;	// world space center position
		float radius = mRadius;

		vec3 oc = ray.origin - center;
		float a = glm::dot(ray.direction, ray.direction);
		float b = glm::dot(oc, ray.direction);
		float c = glm::dot(oc, oc) - radius * radius;

		float disc = b * b - a * c;
		if (disc > 0) {
			float temp = (-b - sqrt(b*b - a * c)) / a;
			if (temp < tMax && temp > tMin) {
				outRec.t = temp;
				outRec.p = ray.getPoint(temp);
				outRec.normal = (outRec.p - center) / radius;
				return true;
			}
		}

		return false;
	}

}  // end of namespace Neil3D