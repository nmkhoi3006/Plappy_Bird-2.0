#ifndef GAME_H_
#define GAME_H_

#include "Common_Funtions.h"

class BaseObject;
class Background;
class Bird;
class Pipe;
class Score;
class TextObject;

class Game {
private:
	SDL_Window* window;
	SDL_Renderer* ren;

	int score_val;

	bool isRunning;

	BaseObject* background;

	Bird* bird;

	Score* Coin;

	Mix_Music* Music;

	Mix_Chunk* wing;
	Mix_Chunk* die;
	Mix_Chunk* hit;
	Mix_Chunk* point;

	TextObject* T_Plappy;
	TextObject* T_Bird;
	TextObject* T_Score;
public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int weidth, int hight);
	void update();
	void render();
	void close();

	void handleEvent();

	bool Running();

};

#endif // !GAME_H_
