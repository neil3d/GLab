/**
 *	A Happy Weekend Path Tracer
 *
 *	Author: Neil
 *	Date:	May, 2019
 *	See:	https://neil3d.github.io
 */

#pragma once
#include <chrono>

namespace Neil3D {

	class Time {
	public:
		Time() {
			auto nowTime = std::chrono::steady_clock::now();
			mStartupTime = nowTime;
			mLastFrameTime = nowTime;
		}

		void tick() {
			auto nowTime = std::chrono::steady_clock::now();

			mDeltaTime = std::chrono::duration_cast<std::chrono::duration<float>>(nowTime - mLastFrameTime).count();
			mLastFrameTime = nowTime;
		}

		float getDeltaTime() {
			return mDeltaTime;
		}

		float getTimeSinceStartup() {
			auto nowTime = std::chrono::steady_clock::now();
			return std::chrono::duration_cast<std::chrono::duration<float>>(nowTime - mStartupTime).count();
		}

	private:
		std::chrono::steady_clock::time_point mStartupTime;
		std::chrono::steady_clock::time_point mLastFrameTime;
		float mDeltaTime = 0.0001f;
	};

}  // end of namespace Neil3D