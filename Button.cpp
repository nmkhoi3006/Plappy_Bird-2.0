#include "Button.h"

Button::Button(int x, int y) {
	dest = { x, y, 100, 100 };
	intersect = false;
	frame_clip[0] = { 0, 0, 49, 21 };
	frame_clip[1] = { 49, 0, 49, 21 };
	this->src = frame_clip[0];
}

Button::Button() {
	intersect = false;
	frame_clip[0] = { 0, 0, 49, 21 };
	frame_clip[1] = { 49, 0, 49, 21 };
	//this->src = frame_clip[0];
}

void Button::handleIntersection() {
	int x, y;
	SDL_GetMouseState(&x, &y);
	SDL_Rect* mouse = new SDL_Rect{ x, y, 30, 30 };
	if (SDL_HasIntersection(mouse, &dest)){
		this->src = frame_clip[1];
		this->intersect = true;
	}
	else {
		this->src = frame_clip[0];
		this->intersect = false;
	}
}

void Button::Draw(SDL_Renderer* ren) {
	SDL_RenderCopy(ren, this->tex, &src, &dest);
}

void Button::freeButton() {
	SDL_DestroyTexture(this->tex);
}