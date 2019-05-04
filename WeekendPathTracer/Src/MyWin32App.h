/**
 *	A Happy Weekend Path Tracer
 *
 *	Author: Neil
 *	Date:	May, 2019
 *	See:	https://neil3d.github.io
 */

#pragma once
#include <string>
#include "Time.h"

namespace Neil3D {

	/*
	 * Win32 API Desktop App class
	 */
	class MyWin32App {
	public:
		MyWin32App();
		virtual ~MyWin32App();

		virtual bool create(HINSTANCE hInstance, const std::wstring& strTitle);
		virtual void mainLoop();
		virtual void update(float deltaTime) = 0;
		virtual void render() = 0;
		virtual void destroy();

		SIZE getClientSize() const;

	protected:
		Time mTime;

		HINSTANCE mWin32Instance = nullptr;
		HWND mWnd = nullptr;

	private:
		static LRESULT CALLBACK windowProc(HWND hWnd, UINT message, WPARAM wParam,
			LPARAM lParam);

	private:
		MyWin32App(const MyWin32App&) = delete;             // disable copy ctor
		MyWin32App& operator=(const MyWin32App&) = delete;  // disable assignment operator
	};

}  // end of namespace Neil3D