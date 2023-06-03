#pragma once

#include <memory>
#include <vector>

#include <SDL.h>

#include "RenderObject.h"

class RenderObject;

// Container class for sdl related things and global scene management
class RenderContext
{
	std::vector<std::unique_ptr<RenderObject>> renderObjects;
public:
	SDL_Renderer* renderer = nullptr;
	SDL_Window* window = nullptr;

	void render();
	void pollExit();

	RenderContext(std::vector<std::unique_ptr<RenderObject>> objects);
	~RenderContext();
};

