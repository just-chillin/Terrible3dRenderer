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




bool isObjectDefinition(std::string& line);