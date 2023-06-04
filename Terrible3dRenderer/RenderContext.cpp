#include <iostream>

#include <SDL.h>

#include "RenderContext.h"


RenderContext::RenderContext(std::vector<std::unique_ptr<RenderObject>> objects) : renderObjects(std::move(objects)) {
	// Initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::cerr << "SDL could not initialize! " << SDL_GetError() << std::endl;;
		return;
	}

	SDL_CreateWindowAndRenderer(SCREEN_W, SCREEN_H, SDL_RENDERER_ACCELERATED, &window, &renderer);
	SDL_SetWindowTitle(window, "Corrina's Shitty 3d Renderer");

	// Clear the screen
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);

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
		switch (evt.type) {
		case SDL_QUIT:
			return;
		}
		SDL_RenderPresent(renderer);

	}
}