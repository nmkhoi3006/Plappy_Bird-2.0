#include "Background.h"

void Background::Draw(SDL_Renderer* ren) {
	SDL_RenderCopy(ren, tex, NULL, NULL);
}