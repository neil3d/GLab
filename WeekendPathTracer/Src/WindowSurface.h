/**
 *	A Happy Weekend Path Tracer
 *
 *	Author: Neil
 *	Date:	May, 2019
 *	See:	https://neil3d.github.io
 */

#pragma once
#include <dxgi.h>
#include <d3d11.h>
#include <wrl/client.h>
#include <vector>
using Microsoft::WRL::ComPtr;

namespace Neil3D {

	struct Color32 {
		BYTE B;
		BYTE G;
		BYTE R;
		BYTE A;
	};

	class WindowSurface {
	public:

	public:
		WindowSurface();
		virtual ~WindowSurface();

		bool create(HWND hWnd);
		void destroy();

		void clear(const Color32& px);
		void writePixel(unsigned int x, unsigned int y, const Color32& px);
		void present(bool vSync);

	private:
		int mPitch;	// width in pixel
		int mWidth, mHeight;
		std::vector<Color32>	mDrawBuffer;

		ComPtr<ID3D11DeviceContext> mImmediateContext;
		ComPtr<IDXGISwapChain> mSwapChain;
		ComPtr<ID3D11Texture2D> mBackBufferTexture;
		ComPtr<ID3D11Texture2D> mDrawBufferTexture;
		ComPtr<IDXGISurface> mDrawSurface;
	};

}  // end of namespace Neil3D