#include <iostream>

#include <SDL.h>

#include "RenderContext.h"


RenderContext::RenderContext(std::vector<std::unique_ptr<RenderObject>> objects) : renderObjects(std::move(objects)) {
	// Initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::cerr << "SDL could not initialize! " << SDL_GetError() << std::endl;;
		return;
	}

	SDL_CreateWindowAndRenderer(1920, 1080, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC, &window, &renderer);
	SDL_SetWindowTitle(window, "Corrina's Shitty 3d Renderer");

	// Clear the screen
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
}

RenderContext::~RenderContext() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
}

void RenderContext::render() {
	for (auto& renderObject : renderObjects) {
		renderObject->render(this);
	}
	SDL_RenderPresent(renderer);
}

void RenderContext::pollExit() {
	SDL_Event evt{};
	while (true) {
		SDL_PollEvent(&evt);
		if (evt.type == SDL_QUIT) {
			return;
		}
	}
}