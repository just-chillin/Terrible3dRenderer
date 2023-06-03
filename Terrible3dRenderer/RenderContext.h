#pragma once

#include <SDL.h>

#include "RenderObject.h"
#include "RenderNode.h"

// Container class for sdl related things and global scene management
class RenderContext
{
	std::vector<std::unique_ptr<RenderObject>> renderObjects;
public:
	SDL_Renderer* renderer = nullptr;
	SDL_Window* window = nullptr;

	void Render();

	RenderContext(std::vector<std::unique_ptr<RenderObject>> objects);
	~RenderContext();
};

