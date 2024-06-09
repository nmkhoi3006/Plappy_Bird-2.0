#pragma once
#include "Button.h"
#include "Common_Funtions.h"

class Button;
<<<<<<< HEAD
class Game;
=======
>>>>>>> 8e5f4d90d09fd94ed5a9cedc180ee1dfdc6984fa
class Menu : public BaseObject {
private:
public:
	Button* button[4];
<<<<<<< HEAD
	enum buttonNames { PLAY, QUIT, SOUNDON, SOUNDOFF };
	Menu();
	void selectButton(SDL_Event e, bool loading, Bird* _bird, Game* _game);
	void Draw(SDL_Renderer* ren) override;
	void initMenu(SDL_Renderer* ren);
	bool sound;
	void Update();
=======
	enum buttonNames { PLAY, QUIT, HELP, SOUND };
	Menu();
	bool selectButton(SDL_Event e, bool loading);
	void Draw(SDL_Renderer* ren) override;
	void initMenu(SDL_Renderer* ren);
>>>>>>> 8e5f4d90d09fd94ed5a9cedc180ee1dfdc6984fa
	~Menu();
};