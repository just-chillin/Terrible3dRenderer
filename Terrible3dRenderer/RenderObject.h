#pragma once

#include <vector>

#include "Vertex.h"
#include "RenderContext.h"

class RenderNode;
class RenderContext;
class Vertex;

class RenderObject {
	std::vector<Vertex> vertices;
public:
	void consume(std::istream& line);
	void render(RenderContext *ctx);

	friend std::ostream& operator<<(std::ostream& os, RenderObject& r);
};
