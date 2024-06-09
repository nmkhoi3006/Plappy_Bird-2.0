#pragma once
#include "Button.h"
#include "Common_Funtions.h"

class Button;
class Game;

class Menu : public BaseObject {
private:
public:
	Button* button[4];
	enum buttonNames { PLAY, QUIT, SOUNDON, SOUNDOFF };
	Menu();
	void selectButton(SDL_Event e, bool loading, Bird* _bird, Game* _game);
	void Draw(SDL_Renderer* ren) override;
	void initMenu(SDL_Renderer* ren);
	bool sound;
	void Update();
	~Menu();
};