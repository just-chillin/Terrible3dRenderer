#pragma once

#include <istream>

#include <gmtl/gmtl.h>

#include "RenderContext.h"

class RenderContext;

class Vertex {
	gmtl::Vec3f vtx;
public:
	Vertex(std::istream& line);
	
	void render(RenderContext *ctx);

	friend std::ostream& operator<<(std::ostream& os, Vertex& v);
};