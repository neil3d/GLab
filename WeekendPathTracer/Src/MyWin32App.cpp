#include "stdafx.h"
#include "MyWin32App.h"

namespace Neil3D {

	MyWin32App* g_instance = nullptr;

	MyWin32App::MyWin32App() {
		g_instance = this;
	}

	MyWin32App::~MyWin32App() {}

	MyWin32App * MyWin32App::instance() {
		return g_instance;
	}

	bool MyWin32App::create(HINSTANCE hInstance, const std::wstring& strTitle) {
		const TCHAR* szWindowClass = _T("Neil3DWin32App");

		// Step 1: Registers the window class.
		WNDCLASSEXW wcex;

		wcex.cbSize = sizeof(WNDCLASSEX);
		wcex.style = CS_HREDRAW | CS_VREDRAW;
		wcex.lpfnWndProc = MyWin32App::windowProc;
		wcex.cbClsExtra = 0;
		wcex.cbWndExtra = 0;
		wcex.hInstance = hInstance;
		wcex.hIcon = nullptr;
		wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
		wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
		wcex.lpszMenuName = nullptr;
		wcex.lpszClassName = szWindowClass;
		wcex.hIconSm = nullptr;

		ATOM win32Class = RegisterClassExW(&wcex);

		// Step 2: creates main window
		HWND hWnd = CreateWindowW(
			szWindowClass, strTitle.c_str(),
			WS_OVERLAPPED | WS_SYSMENU,
			CW_USEDEFAULT, 0,
			CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

		if (!hWnd) return false;

		//--
		mWin32Instance = hInstance;
		mWnd = hWnd;

		return true;
	}

	void MyWin32App::mainLoop() {
		MSG msg = { 0 };
		while (WM_QUIT != msg.message) {
			if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else {
				if (mRealtime) {
					mTime.tick();
					update(mTime.getDeltaTime());
					render();
				}
			}
		}
	}

	void MyWin32App::destroy() {}

	void MyWin32App::showWindow() {
		ShowWindow(mWnd, SW_SHOWNORMAL);
		UpdateWindow(mWnd);
	}

	SIZE MyWin32App::getClientSize() const {
		SIZE ret = { 0,0 };
		if (mWnd) {
			RECT rc;
			::GetClientRect(mWnd, &rc);
			ret.cx = rc.right - rc.left;
			ret.cy = rc.bottom - rc.top;
		}
		return ret;
	}

	LRESULT CALLBACK MyWin32App::windowProc(HWND hWnd, UINT message, WPARAM wParam,
		LPARAM lParam) {

		PAINTSTRUCT ps;
		HDC hdc;

		switch (message) {
		case WM_PAINT:
			hdc = BeginPaint(hWnd, &ps);
			if (g_instance) {
				g_instance->mTime.tick();
				g_instance->update(g_instance->mTime.getDeltaTime());
				g_instance->render();
			}
			EndPaint(hWnd, &ps);
			break;

		case WM_DESTROY:
			PostQuitMessage(0);
			break;

		case WM_ERASEBKGND:
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}

		return 0;
	}

}  // end of namespace Neil3D