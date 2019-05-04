#include "stdafx.h"
#include "MyWin32App.h"

namespace Neil3D {

	MyWin32App::MyWin32App() {}

	MyWin32App::~MyWin32App() {}

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
			szWindowClass, strTitle.c_str(), WS_OVERLAPPED | WS_SYSMENU, CW_USEDEFAULT, 0,
			CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

		if (!hWnd) return false;

		ShowWindow(hWnd, SW_SHOWNORMAL);
		UpdateWindow(hWnd);

		//--
		mWin32Instance = hInstance;
		mWnd = hWnd;

		return true;
	}

	void MyWin32App::mainLoop() {
		MSG msg;

		// Main message loop:
		while (mRunning) {
			if (::PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE)) {
				if (!::GetMessage(&msg, NULL, 0, 0)) {
					mRunning = false;
					break;
				}

				::TranslateMessage(&msg);
				::DispatchMessage(&msg);
			}

			mTime.tick();
			update(mTime.getDeltaTime());
			render();
		}
	}

	void MyWin32App::destroy() {}

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
		switch (message) {
		case WM_PAINT:
		case WM_ERASEBKGND:
			break;
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		return 0;
	}

}  // end of namespace Neil3D