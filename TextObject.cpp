#include "TextObject.h"

TextObject::TextObject() {
	this->tex = NULL;
	this->content = "";
	this->font = NULL;
	this->textColor = { 0, 0, 0 };
}

void TextObject::Write(std::string content, const char* file_name, SDL_Renderer* ren, int size) {

	if (TTF_Init() == -1){
		return;
	}

	font = TTF_OpenFont(file_name, size);

	if (this->font == NULL)
		return;

	SDL_Surface* tmp = TTF_RenderText_Solid(this->font, content.c_str(), this->textColor);

	if (tmp == NULL)
		return;

	this->tex = SDL_CreateTextureFromSurface(ren, tmp);

	if (this->tex == NULL)
		return;

	SDL_FreeSurface(tmp);
}

void TextObject::Draw(SDL_Renderer* ren) {
	SDL_RenderCopy(ren, this->tex, NULL, &this->dest);
}