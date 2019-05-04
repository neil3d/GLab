#include "stdafx.h"
#include "WindowSurface.h"

namespace Neil3D {

	WindowSurface::WindowSurface()
	{
	}


	WindowSurface::~WindowSurface()
	{
	}

	bool WindowSurface::create(HWND hWnd)
	{
		return true;
	}

	void WindowSurface::destroy()
	{
	}

	void WindowSurface::writePixel(unsigned int x, unsigned int y, const Pixel & px)
	{
	}

}  // end of namespace Neil3D