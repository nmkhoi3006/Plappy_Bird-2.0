#include "Common_Funtions.h"
#include "BaseObject.h"

BaseObject::BaseObject() {
	;
}

BaseObject::~BaseObject() {
	;
}

void BaseObject::CreateTexture(const char* file_name, SDL_Renderer* ren) {
	SDL_Surface* load_img = IMG_Load(file_name);

	SDL_Texture* newTexture = NULL;

	if (load_img != NULL) {
		newTexture = SDL_CreateTextureFromSurface(ren, load_img);
	}

	this->tex = newTexture;
}

void BaseObject::SetDest(int xPos, int yPos, int width, int height) {
	dest.x = xPos;
	dest.y = yPos;
	dest.w = width;
	dest.h = height;
}

void BaseObject::SetSrc(int xPos, int yPos, int width, int height) {
	src.x = xPos;
	src.y = yPos;
	src.w = width;
	src.h = height;
}

SDL_Rect BaseObject::GetDest() {
	return dest;
}

SDL_Rect BaseObject::GetSrc() {
	return src;
}

SDL_Texture* BaseObject::GetTexture() {
	return tex;
}

void BaseObject::Draw(SDL_Renderer* ren) {
	SDL_RenderCopy(ren, tex, &src, &dest);
}