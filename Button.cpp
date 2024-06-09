#include "Button.h"

Button::Button(int x, int y) {
	dest = { x, y, 100, 100 };
	intersect = false;
}


void Button::handleIntersection(SDL_Event e) {
	int x, y;
	SDL_GetMouseState(&x, &y);
	SDL_Rect* mouse = new SDL_Rect{ x, y, 30, 30 };
	if (SDL_HasIntersection(mouse, &dest)) {
		this->intersect = true;
	}
}

void Button::Draw(SDL_Renderer* ren) {
	SDL_RenderCopy(ren, GetTexture(), NULL, &dest);
}

void Button::freeButton() {
	SDL_DestroyTexture(this->tex);
}