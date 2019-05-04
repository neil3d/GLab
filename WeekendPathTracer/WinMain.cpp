// WeekendPathTracer.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Src/MyPathTracer.h"
#include "Src/MyLog.h"

Neil3D::MyPathTracer g_myApp;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	if (!g_myApp.create(hInstance, _T("My Path Tracer")))
		return FALSE;

	MY_LOG(Neil3D::Info, _T("My App created, run main loop..."));
	g_myApp.mainLoop();

	return 0L;
}