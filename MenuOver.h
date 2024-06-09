#pragma once
#include "Common_Funtions.h"

class Button;
class Game;
class Bird;
class TextObject;
class MenuOver : public BaseObject {
private:
	BaseObject* board;

	int s_val;
	int hs_val;

	TextObject* s;
	TextObject* hs;

public:
	MenuOver();
	Button* button[2];
	enum buttonNames { REPLAY, EXIT };

	void Draw(SDL_Renderer* ren) override;
	void initMenuOver(SDL_Renderer* ren);
	void Update(int _s_val, int _hs_val);

	void handleInput(SDL_Event e, Game* _game, Bird*_bird);
	void FreeMenu();
};