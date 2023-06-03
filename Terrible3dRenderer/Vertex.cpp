#include <format>
#include <iostream>

#include <SDL.h>

#include "Vertex.h"
#include "Exceptions.h"

Vertex::Vertex(std::istream& line) {
	float axes[3]{};
	for (int i = 0; i < 3; i++) {
		if (!line.good()) {
			throw MALFORMED_INPUT_EXCEPT;
		}

		line >> axes[i];
	}

	point = gmtl::Point3f(axes[0], axes[1], axes[2]);
}

float Vertex::x() { return point[0]; }
float Vertex::y() { return point[1]; }
float Vertex::z() { return point[2]; }

void Vertex::render(RenderContext *ctx) {
	float u = abs(100.f * (x() / z()));
	float v = abs(100.f * (y() / z()));
	std::cout << std::format("Rendering u = {}, v = {}", u, v) << std::endl;
	SDL_RenderDrawPoint(ctx->renderer, u, v);
}

std::ostream& operator<<(std::ostream& os, Vertex& v)
{
	return os << std::format("Point(x={}, y={}, z={})", v.x(), v.y(), v.z());
}