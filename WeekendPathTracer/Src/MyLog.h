/**
 *	A Happy Weekend Path Tracer
 *
 *	Author: Neil
 *	Date:	May, 2019
 *	See:	https://neil3d.github.io
 */

#pragma once

namespace Neil3D {

	enum LogPriority {
		Info,
		Debug,
		Warn,
		Error
	};

	void MyLogFunc(LogPriority log, const TCHAR* fmt, ...);

}  // end of namespace Neil3D

#define  MY_LOG Neil3D::MyLogFunc
