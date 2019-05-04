/**
*	A Happy Weekend Path Tracer
*
*	Author: Neil
*	Date:	May, 2019
*	See:	https://neil3d.github.io
*/

#pragma once
#include "MyWin32App.h"

namespace Neil3D {

	/*
	 * My Path Tracer App class
	*/
	class MyPathTracer : public Win32App
	{
	public:
		MyPathTracer();
		virtual ~MyPathTracer();

		virtual void update(float deltaTime) override;
		virtual void render() override;
	};

}// end of namespace Neil3D