#pragma once

#include <gmtl/gmtl.h>

struct ScreenCoords {
	int u, v;

	ScreenCoords() = default;
};

gmtl::Vec2i toScreenCoords(const gmtl::Vec3f& vec, const gmtl::Vec2i& screenCenter);