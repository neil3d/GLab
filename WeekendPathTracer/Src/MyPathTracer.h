/**
*	A Happy Weekend Path Tracer
*
*	Author: Neil
*	Date:	May, 2019
*	See:	https://neil3d.github.io
*/

#pragma once
#include "MyWin32App.h"
#include "WindowSurface.h"

namespace Neil3D {

	/*
	 * My Path Tracer App class
	*/
	class MyPathTracer : public MyWin32App {
	public:
		MyPathTracer();
		virtual ~MyPathTracer();

		virtual bool create(HINSTANCE hInstance, const std::wstring& strTitle) override;
		virtual void update(float deltaTime) override;
		virtual void render() override;

	private:
		WindowSurface mSurface;
	};

}// end of namespace Neil3D