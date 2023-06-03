#pragma once

#include "RenderNode.h"

class Vertex : RenderNode {
	gmtl::Point3f point;
public:
	Vertex(std::istream& line);
	void render();

	float x();
	float y();
	float z();

	friend std::ostream& operator<<(std::ostream& os, Vertex& v);
};