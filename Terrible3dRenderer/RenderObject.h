#pragma once

#include "RenderNode.h"

class RenderObject : RenderNode {
	std::vector<Vertex> vertices{};
public:
	void consume(std::istream& line);
	void render();

	friend std::ostream& operator<<(std::ostream& os, RenderObject& r);
};
