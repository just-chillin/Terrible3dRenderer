#pragma once

#include <exception>
#include <vector>
#include <iostream>

#include <gmtl/Point.h>

class Vertex;

class RenderNode {
public:
	virtual void render() = 0;
};


class RenderObject : RenderNode {
	std::vector<Vertex> vertices{};
public:
	void consume(std::istream& line);
	void render();

	friend std::ostream& operator<<(std::ostream& os, RenderObject& r);
};

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


bool isObjectDefinition(std::string& line);