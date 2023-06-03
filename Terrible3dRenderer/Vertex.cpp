#include <format>

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
	SDL_RenderDrawPoint(ctx->renderer, x() / z(), y() / z());
}

std::ostream& operator<<(std::ostream& os, Vertex& v)
{
	return os << std::format("Point(x={}, y={}, z={})", v.x(), v.y(), v.z());
}