#pragma once

#include <SDL.h>

// Container class for sdl related things and global scene management
class RenderContext
{
public:
	SDL_Renderer* renderer = nullptr;
	SDL_Window* window = nullptr;

	RenderContext();
	~RenderContext();
};

