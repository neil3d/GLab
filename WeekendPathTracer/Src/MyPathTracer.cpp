#include "stdafx.h"
#include "MyPathTracer.h"

namespace Neil3D {

	MyPathTracer::MyPathTracer()
	{
	}


	MyPathTracer::~MyPathTracer()
	{
	}

	bool MyPathTracer::create(HINSTANCE hInstance, const std::wstring & strTitle)
	{
		bool succeed = MyWin32App::create(hInstance, strTitle);
		if (succeed)
			succeed = mSurface.create(mWnd);

		return succeed;
	}

	void MyPathTracer::update(float deltaTime)
	{
	}

	void MyPathTracer::render()
	{
	}

}// end of namespace Neil3D