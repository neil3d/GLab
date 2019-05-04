/**
 *	A Happy Weekend Path Tracer
 *
 *	Author: Neil
 *	Date:	May, 2019
 *	See:	https://neil3d.github.io
 */

#pragma once
#include <wrl/client.h>
using Microsoft::WRL::ComPtr;

namespace Neil3D {

	class WindowSurface
	{
	public:
		struct Pixel
		{
			BYTE B;
			BYTE G;
			BYTE R;
			BYTE A;
		};
	public:
		WindowSurface();
		virtual ~WindowSurface();

		bool create(HWND hWnd);
		void destroy();

		void writePixel(unsigned int x, unsigned int y, const Pixel& px);

	private:
	};

}  // end of namespace Neil3D