#include "stdafx.h"
#include "WindowSurface.h"
#include "MyLog.h"

#pragma comment( lib, "DXGI")
#pragma comment( lib, "D3D11")

namespace Neil3D {

	WindowSurface::WindowSurface()
	{
	}


	WindowSurface::~WindowSurface()
	{
	}

	bool WindowSurface::create(HWND hWnd)
	{
		HRESULT hr;
		ComPtr<IDXGIFactory> pFactory;

		// create DXGI Factory
		hr = CreateDXGIFactory(__uuidof(IDXGIFactory), (LPVOID*)(pFactory.GetAddressOf()));
		if (FAILED(hr)) {
			MY_LOG(Error, _T("WindowSurface: Create IDXGIFactory FAILED!"));
			return false;
		}

		// enum adapters
		UINT adapterIndex = 0;
		ComPtr<IDXGIAdapter> pAdapter;
		while (pFactory->EnumAdapters(adapterIndex, pAdapter.GetAddressOf()) != DXGI_ERROR_NOT_FOUND)
		{
			adapterIndex++;
			DXGI_ADAPTER_DESC desc;
			pAdapter->GetDesc(&desc);

			MY_LOG(Info, _T("WindowSurface: Adapter[%d]-[%s]."),
				adapterIndex,
				desc.Description
			);
		}

		// create swap chain
		RECT rc;
		::GetClientRect(hWnd, &rc);
		UINT width = rc.right - rc.left;
		UINT height = rc.bottom - rc.top;

		DXGI_SWAP_CHAIN_DESC sd;
		ZeroMemory(&sd, sizeof(sd));
		sd.BufferCount = 1;
		sd.BufferDesc.Width = width;
		sd.BufferDesc.Height = height;
		sd.BufferDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
		sd.BufferDesc.RefreshRate.Numerator = 60;
		sd.BufferDesc.RefreshRate.Denominator = 1;
		sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		sd.OutputWindow = hWnd;
		sd.SampleDesc.Count = 1;
		sd.SampleDesc.Quality = 0;
		sd.Windowed = TRUE;

		UINT createDeviceFlags = D3D11_CREATE_DEVICE_DEBUG;

		ComPtr<IDXGISwapChain> pSwapChain;
		ComPtr<ID3D11Device> pDevice;
		ComPtr<ID3D11DeviceContext> pImmediateContext;

		hr = D3D11CreateDeviceAndSwapChain(nullptr,
			D3D_DRIVER_TYPE_HARDWARE,
			nullptr,
			createDeviceFlags,
			nullptr,
			0,
			D3D11_SDK_VERSION,
			&sd,
			pSwapChain.GetAddressOf(),
			pDevice.GetAddressOf(),
			nullptr,
			pImmediateContext.GetAddressOf()
		);

		if (FAILED(hr)) {
			MY_LOG(Error, _T("WindowSurface: D3D11CreateDeviceAndSwapChain FAILED!"));
			return false;
		}

		ComPtr<ID3D11Texture2D> pBackBufferTexture;
		hr = pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)(pBackBufferTexture.GetAddressOf()));

		if (FAILED(hr)) {
			MY_LOG(Error, _T("WindowSurface: Get Back Buffer FAILED!"));
			return false;
		}

		//-- create temp surface
		D3D11_TEXTURE2D_DESC backBufferDesc;
		pBackBufferTexture->GetDesc(&backBufferDesc);

		backBufferDesc.BindFlags = 0;
		backBufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
		backBufferDesc.Usage = D3D11_USAGE_STAGING;

		ComPtr<ID3D11Texture2D> pTempBufferTexture;
		hr = pDevice->CreateTexture2D(&backBufferDesc, NULL, &pTempBufferTexture);
		
		if (FAILED(hr)) {
			MY_LOG(Error, _T("WindowSurface: Create Temp Buffer FAILED!"));
			return false;
		}

		ComPtr<IDXGISurface> pSurface;
		hr = pTempBufferTexture->QueryInterface(__uuidof(IDXGISurface), (LPVOID*)(pSurface.GetAddressOf()));

		if (FAILED(hr)) {
			MY_LOG(Error, _T("WindowSurface: Query Back Buffer Surface FAILED!"));
			return false;
		}

		//--
		DXGI_MAPPED_RECT mapRc;
		hr = pSurface->Map(&mapRc, DXGI_MAP_WRITE);

		if (FAILED(hr)) {
			MY_LOG(Error, _T("WindowSurface: Map Back Buffer Surface FAILED!"));
			return false;
		}

		mWidth = width;
		mHeight = height;
		mPitch = mapRc.Pitch / 4;	// DXGI_FORMAT_R8G8B8A8_UNORM
		if (mPitch * 4 != mapRc.Pitch) {
			MY_LOG(Error, _T("WindowSurface: Pixel Size ERROR!"));
			return false;
		}
		mDrawBuffer.resize(mPitch*height, { 0,0,0,255 });

		hr = pSurface->Unmap();
		if (FAILED(hr)) {
			MY_LOG(Error, _T("WindowSurface: Unmap Back Buffer Surface FAILED!"));
			return false;
		}

		// --
		mImmediateContext = pImmediateContext;
		mSwapChain = pSwapChain;
		mBackBufferTexture = pBackBufferTexture;
		mDrawBufferTexture = pTempBufferTexture;
		mDrawSurface = pSurface;

		return true;
	}

	void WindowSurface::destroy()
	{
		mDrawSurface.Reset();
		mSwapChain.Reset();
	}

	void WindowSurface::writePixel(unsigned int x, unsigned int y, const Color32 & px)
	{
		unsigned int index = y * mPitch + x;
		if (index < mDrawBuffer.size()) {
			mDrawBuffer[index] = px;
		}
		else {
			MY_LOG(Warn, _T("WindowSurface: Write pixel FAILED!"));
		}
	}

	void WindowSurface::present(bool vSync)
	{
		HRESULT hr;

		// copy memory pixel to draw surface(texture)
		DXGI_MAPPED_RECT mapRc;
		hr = mDrawSurface->Map(&mapRc, DXGI_MAP_WRITE);
		if (SUCCEEDED(hr)) {
			memcpy(mapRc.pBits, &mDrawBuffer[0], mapRc.Pitch*mHeight);
			hr = mDrawSurface->Unmap();

			// copy draw texture to back buffer
			mImmediateContext->CopyResource(mBackBufferTexture.Get(), mDrawBufferTexture.Get());
		}
		else {
			MY_LOG(Warn, _T("WindowSurface: Write Back Buffer Surface FAILED!"));
		}

		// present
		mSwapChain->Present(
			vSync ? 1 : 0,
			0);
	}

}  // end of namespace Neil3D