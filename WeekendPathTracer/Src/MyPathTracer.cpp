#include "stdafx.h"
#include "MyPathTracer.h"
#include "math/Ray.h"

namespace Neil3D {

	MyPathTracer::MyPathTracer() {}


	MyPathTracer::~MyPathTracer() {}

	bool MyPathTracer::create(HINSTANCE hInstance, const std::wstring & strTitle) {
		bool succeed = MyWin32App::create(hInstance, strTitle);
		if (succeed)
			succeed = mSurface.create(mWnd);

		return succeed;
	}

	void MyPathTracer::update(float deltaTime) {}

	void MyPathTracer::render() {

		// draw background
		vec3 lowerLeftCorner(-2, -1, -1);
		vec3 horizontal(4, 0, 0);
		vec3 vertical(0, 2, 0);
		vec3 origin(0);

		vec3 colorA(1, 1, 1), colorB(0.5f, 0.7f, 1.0f);
		Color32 pixel = { 255,255,255,255 };

		SIZE clientSize = getClientSize();
		for (int y = clientSize.cy - 1; y >= 0; y--) {
			for (int x = 0; x < clientSize.cx; x++) {
				float u = float(x) / (float)(clientSize.cx);
				float v = float(y) / (float)(clientSize.cy);

				Ray r(origin, lowerLeftCorner + u * horizontal + v * vertical);
				float t = 0.5f*(r.direction.y + 1.0f);

				vec3 c = glm::lerp(colorA, colorB, t);

				pixel.R = BYTE(255 * c.x);
				pixel.G = BYTE(255 * c.y);
				pixel.B = BYTE(255 * c.z);
				mSurface.writePixel(x, y, pixel);
			}
		}// end of for


		mSurface.present(true);
	}

}// end of namespace Neil3D