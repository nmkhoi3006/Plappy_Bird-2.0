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
class MenuOver;

class Game {
private:
	SDL_Window* window;

	int score_val;

	int hscore_val;

	bool loading;

	BaseObject* background;

	Bird* bird;

	Pipe* topPipe[3];
	Pipe* bottomPipe[3];

	Menu* myMenu;

	Score* Coin;

	TextObject* T_Plappy;
	TextObject* T_Bird;
	TextObject* T_Score;


	MenuOver* over;

public:

	SDL_Renderer* ren;
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

	void newGame();
};

#endif // !GAME_H_