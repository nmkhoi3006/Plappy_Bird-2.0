#ifndef BUTTON_H_
#define BUTTON_H_
#include "Common_Funtions.h"

class Button : public BaseObject {
public:
	bool intersect;
	Button() : intersect(false) {}
	Button(int x, int y);
	void setPosition(int x, int y);
	void Draw(SDL_Renderer* ren) override;
	void handleIntersection(SDL_Event *e);
	
};

#endif // !BUTTON_H_

