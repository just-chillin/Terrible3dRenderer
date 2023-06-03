#pragma once

#include <istream>

#include <gmtl/Point.h>

#include "RenderContext.h"

class RenderContext;

class Vertex {
	gmtl::Point3f point;
public:
	Vertex(std::istream& line);
	
	void render(RenderContext *ctx);

	float x();
	float y();
	float z();

	friend std::ostream& operator<<(std::ostream& os, Vertex& v);
};