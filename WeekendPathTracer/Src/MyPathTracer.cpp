#include "stdafx.h"
#include "MyPathTracer.h"
#include "math/Ray.h"
#include "SampleSceneA.h"
#include "SceneRayHitTest.h"

namespace Neil3D {

	MyPathTracer::MyPathTracer() {}


	MyPathTracer::~MyPathTracer() {}

	bool MyPathTracer::create(HINSTANCE hInstance, const std::wstring & strTitle) {
		bool succeed = MyWin32App::create(hInstance, strTitle);
		if (succeed)
			succeed = mSurface.create(mWnd);

		std::shared_ptr<SampleSceneA> sampleScene(new SampleSceneA());
		sampleScene->initSceneContent();
		mSampleScene = sampleScene;

		return succeed;
	}

	void MyPathTracer::update(float deltaTime) {}

	void MyPathTracer::render() {

		// clear background
		Color32 clearColor = { (BYTE)(255 * 0.5f),(BYTE)(255 * 0.7f),255,255 };
		mSurface.clear(clearColor);

		// ray cast
		vec3 lowerLeftCorner(-2, -1, -1);
		vec3 horizontal(4, 0, 0);
		vec3 vertical(0, 2, 0);
		vec3 origin(0);

		Color32 pixel = { 250,5,5,255 };

		SIZE clientSize = getClientSize();
		for (int y = clientSize.cy - 1; y >= 0; y--) {
			for (int x = 0; x < clientSize.cx; x++) {
				float u = float(x) / (float)(clientSize.cx);
				float v = float(y) / (float)(clientSize.cy);

				Ray r(origin, lowerLeftCorner + u * horizontal + v * vertical);
				float t = 0.5f*(r.direction.y + 1.0f);

				SceneRayHitTest hitTest;
				hitTest.mRay = r;
				mSampleScene->visit(&hitTest);
				if (hitTest.mHit)
					mSurface.writePixel(x, y, pixel);
			}
		}// end of for

		// show
		mSurface.present(true);
	}

}// end of namespace Neil3D