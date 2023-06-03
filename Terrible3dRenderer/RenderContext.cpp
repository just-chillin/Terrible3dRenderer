#include <SDL.h>

#include "RenderContext.h"


RenderContext::RenderContext(std::vector<std::unique_ptr<RenderObject>> objects) : renderObjects(objects) {
	SDL_CreateWindowAndRenderer(1920, 1080, NULL, &window, &renderer);
}

RenderContext::~RenderContext() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
}

void RenderContext::Render() {
	for (auto& renderObject : renderObjects) {
		renderObject->render(this);
	}
}