/**
 *	A Happy Weekend Path Tracer
 *
 *	Author: Neil
 *	Date:	May, 2019
 *	See:	https://neil3d.github.io
 */

#pragma once
#include <string>
#include <memory>
#include "HitRecord.h"
#include "../math/Ray.h"
#include "../material/Material.h"

namespace Neil3D {

	class SceneNode {
	public:
		typedef std::shared_ptr<SceneNode> Ptr;

		SceneNode(const std::wstring& name) :mName(name) {}

		virtual ~SceneNode() {}

		virtual bool hit(const Ray& ray, float tMin, float tMax, HitRecord& outRec) = 0;

		template<typename T>
		std::shared_ptr<T> createMaterial() {
			mMtl.reset(new T());
			return std::dynamic_pointer_cast<T>(mMtl);
		}

		Material* getMaterial() const {
			return mMtl.get();
		}

	protected:
		std::wstring mName;
		Material::Ptr mMtl;
	};

}  // end of namespace Neil3D