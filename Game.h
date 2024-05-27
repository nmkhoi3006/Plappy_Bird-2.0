#ifndef GAME_H_
#define GAME_H_

#include "Common_Funtions.h"

class BaseObject;
class Background;
class Bird;
class Pipe;

class Game {
private:
	SDL_Window* window;
	SDL_Renderer* ren;

	bool isRunning;

	BaseObject* background;

	Bird* bird;

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
