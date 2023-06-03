#include <SDL.h>

#include "RenderContext.h"


RenderContext::RenderContext() {
	SDL_CreateWindowAndRenderer(1920, 1080, NULL, &window, &renderer);
}

RenderContext::~RenderContext() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
}