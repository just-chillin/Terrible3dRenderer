#include <string>

#include "Vertex.h"
#include "RenderObject.h"

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
