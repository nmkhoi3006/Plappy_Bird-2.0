#ifndef BASE_OBJECT_H_
#define	BASE_OBJECT_H_

#include "Common_Funtions.h"

class BaseObject {
protected:
	SDL_Texture* tex;
	SDL_Rect src;
	SDL_Rect dest;

public:
	
	void CreateTexture(const char* file_name, SDL_Renderer* ren);
	void SetDest(int xPos, int yPOs, int width, int height);
	void SetSrc(int xPos, int yPos, int width, int height);
	void Free();

	SDL_Rect GetSrc();
	SDL_Rect GetDest();
	SDL_Texture* GetTexture();

	virtual void Draw(SDL_Renderer* ren);

};

#endif // !BASE_OBJECT_H_

