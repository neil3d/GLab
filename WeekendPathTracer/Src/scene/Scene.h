/**
 *	A Happy Weekend Path Tracer
 *
 *	Author: Neil
 *	Date:	May, 2019
 *	See:	https://neil3d.github.io
 */

#pragma once
#include <list>
#include "SceneVisitor.h"
#include "SceneNode.h"

namespace Neil3D {

	/*
	* A simple, old school scene graph class
	*/
	class Scene {
	public:
		typedef std::shared_ptr<Scene> Ptr;

		Scene();
		virtual ~Scene();

		template<class T>
		std::shared_ptr<T> createNode(const std::wstring& name) {
			std::shared_ptr<T> newNode(new T(name));
			mRootNodes.push_back(newNode);
			return newNode;
		}
		void visit(SceneVisitor* visitor);

	protected:
		std::list<SceneNode::Ptr>	mRootNodes;
	};

}  // end of namespace Neil3D