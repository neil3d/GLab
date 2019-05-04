/**
*	A Happy Weekend Path Tracer
*
*	Author: Neil
*	Date:	May, 2019
*	See:	https://neil3d.github.io
*/

#pragma once
#include <string>

namespace Neil3D {
	/*
	 * Win32 API Desktop App class
	*/
	class Win32App
	{
	public:
		Win32App();
		virtual ~Win32App();

		virtual bool create(HINSTANCE hInstance, const std::wstring& strTitle);
		virtual void mainLoop();

		virtual void update(float deltaTime) = 0;
		virtual void render() = 0;

		virtual void destroy();

	protected:
		HINSTANCE	mWin32Instance = nullptr;
		HWND		mWnd = nullptr;
		bool		mRunning = true;

	private:
		static LRESULT CALLBACK windowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	private:
		Win32App(const Win32App&) = delete;	// disable copy ctor
		Win32App& operator = (const Win32App&) = delete;	// disable assignment operator
	};

}// end of namespace Neil3D