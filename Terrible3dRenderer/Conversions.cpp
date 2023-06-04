#include<cmath>

#include<gmtl/gmtl.h>

#include "Conversions.h"


gmtl::Vec2i toScreenVec2f(const gmtl::Vec3f& vec) {
	float u = vec[0] / vec[2];
	float v = vec[1] / vec[2];
	return gmtl::Vec2i(round(u), round(v));
}

gmtl::Vec2i toScreenCoords(const gmtl::Vec3f& objectPos, const gmtl::Vec2i& screenCenter) {
	auto objectPosIn2d = toScreenVec2f(objectPos);
	return screenCenter - objectPosIn2d;
}
