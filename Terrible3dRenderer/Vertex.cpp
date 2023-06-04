#include <format>
#include <iostream>

#include <SDL.h>
#include <gmtl/gmtl.h>

#include "Vertex.h"
#include "Exceptions.h"
#include "Conversions.h"

Vertex::Vertex(std::istream& line) {
	float axes[3]{};
	for (int i = 0; i < 3; i++) {
		if (!line.good()) {
			throw MALFORMED_INPUT_EXCEPT;
		}

		line >> axes[i];
	}
	vtx = gmtl::Vec3f(axes[0], axes[1], axes[2]);
}

void Vertex::render(RenderContext *ctx) {
	auto screenCoords = toScreenCoords(vtx, ctx->screenCenter);
	int u = screenCoords[0], v = screenCoords[1];
	std::cout << std::format("Rendering u = {}, v = {}", u, v) << std::endl;
	SDL_RenderDrawPoint(ctx->renderer, u, v);
}

std::ostream& operator<<(std::ostream& os, Vertex& v)
{
	return os << std::format("Point(x={}, y={}, z={})", v.vtx[0], v.vtx[1], v.vtx[2]);
}