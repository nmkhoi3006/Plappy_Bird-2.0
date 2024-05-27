#undef main
#include "Common_Funtions.h"
#include "Game.h"

Game* game = NULL;

int main(int arc, char* argv[]) {
	game = new Game();

	const int FPS = 280;
	const int DELAY_TIME = 1000 / FPS;

	Uint64 frameStart;
	Uint64 frameTime;

	game->init("game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT);

	while (game->Running()) {

		frameStart = SDL_GetTicks();

		game->handleEvent();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;
		if (frameTime < DELAY_TIME)
		{
			SDL_Delay(DELAY_TIME - frameTime);
		}

	}
	game->close();
	return 0;
}