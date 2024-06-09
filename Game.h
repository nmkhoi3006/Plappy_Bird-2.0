#ifndef GAME_H_
#define GAME_H_

#include "Common_Funtions.h"

class BaseObject;
class Background;
class Bird;
class Pipe;
class Score;
class TextObject;
class Button;
class Menu;

class Game {
private:
	SDL_Window* window;
	SDL_Renderer* ren;

	int score_val;

	bool loading;

	BaseObject* background;

	Bird* bird;

	Menu* myMenu;

	Score* Coin;

	TextObject* T_Plappy;
	TextObject* T_Bird;
	TextObject* T_Score;
public:
	Mix_Music* Music;

	Mix_Chunk* wing;
	Mix_Chunk* die;
	Mix_Chunk* hit;
	Mix_Chunk* point;
	Mix_Chunk* click;

	bool isRunning;

	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int weidth, int hight);
	void initAudio();
	void update();
	void render();
	void close();

	void handleEvent();

	bool Running();

};

#endif // !GAME_H_