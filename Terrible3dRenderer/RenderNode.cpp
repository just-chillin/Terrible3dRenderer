#include <memory>
#include <string>
#include <iostream>
#include <format>

#include "RenderNode.h"

#define MALFORMED_INPUT_EXCEPT std::exception("malformed input")

bool isObjectDefinition(std::string& line) {
	if (line.length() < 0) {
		return false;
	}

	return line[0] == 'o';
}

void RenderObject::consume(std::istream& line) {
	std::string verb;
	std::getline(line, verb, ' ');

	if (verb == "v") {
		vertices.push_back(Vertex(line));
	}
	else if (verb == "#") {
		std::cout << "comment" << std::endl;
	}
	else {
		std::cout << "ignoring vreb " << verb << " because it is not supported" << std::endl;
	}
}

void RenderObject::render() {

}

std::ostream& operator<<(std::ostream& os, RenderObject& r) {
	os << "RenderObject" << std::endl;
	os << "\tVertices:" << std::endl;
	for (auto& vertex : r.vertices) {
		os << "\t\t" << vertex << std::endl;
	}
	return os;
}

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

void Vertex::render() {

}

std::ostream& operator<<(std::ostream& os, Vertex& v)
{
	return os << std::format("Point(x={}, y={}, z={})", v.x(), v.y(), v.z());
}