#pragma once

#include <memory>
#include <vector>

#include <SDL.h>

#include "RenderObject.h"

// TODO: Make this dynamic
constexpr int SCREEN_W = 1920;
constexpr int SCREEN_H = 1080;

class RenderObject;

// Container class for sdl related things and global scene management
class RenderContext
{
	std::vector<std::unique_ptr<RenderObject>> renderObjects;
public:
	SDL_Renderer* renderer = nullptr;
	SDL_Window* window = nullptr;
	
	// TODO: Make this dynamic
	const gmtl::Vec2i screenCenter = gmtl::Vec2i(SCREEN_W/2, SCREEN_H/2);

	void render();
	void pollExit();

	RenderContext(std::vector<std::unique_ptr<RenderObject>> objects);
	~RenderContext();
};
