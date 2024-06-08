#pragma once
#include "Button.h"
#include "Common_Funtions.h"

class Button;
class Menu : public BaseObject {
private:
public:
	Button* button[4];
	enum buttonNames { PLAY, QUIT, HELP, SOUND };
	Menu();
	void selectButton(SDL_Event e, bool loading, bool &playing, bool &running);
	void Draw(SDL_Renderer* ren) override;
	void initMenu(SDL_Renderer* ren);
	void Update();
	~Menu();
};