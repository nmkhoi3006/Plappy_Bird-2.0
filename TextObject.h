#ifndef TEXT_OBJECT_H_
#define TEXT_OBJECT_H_
#include "Common_Funtions.h"

class TextObject : public BaseObject{
private:
	std::string content;

	TTF_Font* font;

	SDL_Color textColor;
public:
	TextObject();

	void Write(std::string content, const char* file_name, SDL_Renderer* ren, int size);
	void Draw(SDL_Renderer* ren) override;
};
#endif // !FRONT_TEXT_H_

