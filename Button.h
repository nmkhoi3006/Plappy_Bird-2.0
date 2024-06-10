#ifndef BUTTON_H_
#define BUTTON_H_
#include "Common_Funtions.h"

class Button : public BaseObject {
public:
	SDL_Rect frame_clip[2];
	bool intersect;
	Button();
	Button(int x, int y);
	void Draw(SDL_Renderer* ren) override;
	void handleIntersection();

	void freeButton();
	
};

#endif // !BUTTON_H_