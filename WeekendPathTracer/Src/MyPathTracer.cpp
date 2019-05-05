#include "stdafx.h"
#include "MyPathTracer.h"
#include "math/Ray.h"
#include "SampleSceneA.h"
#include "MyLog.h"

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

		showWindow();
		return succeed;
	}

	void MyPathTracer::update(float deltaTime) {}

	void MyPathTracer::render() {

		float startTime = mTime.getTimeSinceStartup();

		Color32 pixel = { 0,0,0,255 };

		SIZE clientSize = getClientSize();
		int width = clientSize.cx;
		int height = clientSize.cy;

		for (int y = height - 1; y >= 0; y--) {
			for (int x = 0; x < width; x++) {
				vec3 c = color(x, y, width, height);
				pixel.R = BYTE(255 * sqrt(c.x));
				pixel.G = BYTE(255 * sqrt(c.y));
				pixel.B = BYTE(255 * sqrt(c.z));

				mSurface.writePixel(x, y, pixel);
			}
		}// end of for

		// show
		mSurface.present(true);

		float frameTime = mTime.getTimeSinceStartup() - startTime;
		MY_LOG(Info, _T("Render Time = %.4f"), frameTime);
	}

	vec3 MyPathTracer::color(int x, int y, int width, int height) {

		vec3 lowerLeftCorner(-2, -1, -1);
		vec3 horizontal(4, 0, 0);
		vec3 vertical(0, 2, 0);
		vec3 origin(0);

		int ns = 64;
		vec3 c(0);

		for (int i = 0; i < ns; i++) {
			vec2 rand = glm::diskRand(1.0f);
			float u = float(x + rand.x) / (float)(width);
			float v = float(y + rand.y) / (float)(height);

			Ray ray(origin, lowerLeftCorner + u * horizontal + v * vertical);
			c += generateRay(ray, 1);
		}// end of for(s)

		return c / (float)ns;
	}

	vec3 MyPathTracer::generateRay(const Ray& ray, int depth) {

		const int MAX_DEPTH = 32;

		HitRecord rec;
		if (mSampleScene->hit(ray, 0.0001f, std::numeric_limits<float>::max(), rec)) {
			Ray scattered;
			vec3 attenuation;
			if (depth < MAX_DEPTH
				&& rec.mtl->scatter(ray, rec, attenuation, scattered)) {
				return attenuation * generateRay(scattered, depth + 1);
			}
			else {
				return vec3(0);
			}
		}
		else {
			float t = (ray.direction.y + 1.0f)*0.5f;
			return glm::lerp(vec3(1, 1, 1), vec3(0.5f, 0.7f, 1.0f), t);
		}
	}

}// end of namespace Neil3D