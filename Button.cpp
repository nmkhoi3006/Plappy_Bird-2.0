#include "Button.h"

Button::Button(int x, int y) {
	src = { x, y, 100, 100 };
	dest = { x, y, 100, 100 };
	intersect = false;
}

void Button::setPosition(int x, int y) {
	dest.x = x;
	dest.y = y;
}

void Button::handleIntersection(SDL_Event e) {
	if (e.type == SDL_MOUSEMOTION) {
		int x, y;
		SDL_GetMouseState(&x, &y);
		SDL_Rect* mouse = new SDL_Rect{ x, y, 100, 100 };
		if (SDL_HasIntersection(mouse, &dest)) {
			intersect = true;
		}
	}
}

void Button::Draw(SDL_Renderer* ren) {
	SDL_RenderCopy(ren, GetTexture(), NULL, &dest);
}