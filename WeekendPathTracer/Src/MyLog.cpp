#include "stdafx.h"
#include "MyLog.h"

namespace Neil3D {

	static TCHAR _FORMAT_BUFFER[4096] = { 0 };
	const TCHAR* const LogPriorityNames[] = {
		_T("Info: "),
		_T("Debug: "),
		_T("Warn: "),
		_T("Error: ")
	};

	void MyLogFunc(LogPriority log, const TCHAR * fmt, ...) {
		va_list argptr;

		va_start(argptr, fmt);
		_vstprintf(_FORMAT_BUFFER, sizeof(_FORMAT_BUFFER) - 1, fmt, argptr);
		va_end(argptr);

		::OutputDebugStringW(LogPriorityNames[log]);
		::OutputDebugStringW(_FORMAT_BUFFER);
		::OutputDebugStringW(_T("\r\n"));
	}

}  // end of namespace Neil3D