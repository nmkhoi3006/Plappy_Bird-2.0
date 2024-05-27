#include "Game.h"

Pipe topPipe[3];
Pipe bottomPipe[3];

Game::Game() {
	window = NULL;
	ren = NULL;

	isRunning = false;

	background = new Background();

	bird = new Bird();
}

Game::~Game() {
	;
}

void Game::init(const char* title, int xpos, int ypos, int weidth, int hight) {
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
		isRunning = false;
		return;
	}


	window = SDL_CreateWindow(title, 
							  SDL_WINDOWPOS_UNDEFINED,
		                      SDL_WINDOWPOS_UNDEFINED, 
		                      SCREEN_WIDTH, SCREEN_HEIGHT, 
		                      SDL_WINDOW_SHOWN);

	ren = SDL_CreateRenderer(window, -1, 0);

	if(ren != NULL)
		SDL_SetRenderDrawColor(ren, 255, 0, 0, 255);

	background->CreateTexture("IMG/bg.png", ren);

	bird->CreateTexture("IMG/bird0.png", ren);

	for (int i = 0; i < 3; i++) {
		topPipe[i].CreateTexture("IMG/pipeTop.png", ren);
		bottomPipe[i].CreateTexture("IMG/pipeBottom.png", ren);

		topPipe[i].initPipe(i);
	}


	isRunning = true;

}

void Game::update() {
	bird->update();

	for (int i = 0; i < 3; i++) {
		topPipe[i].updateTopPipe(i, bird->checkBirdDie());
		bottomPipe[i].updateBottomPipe(i, bird->checkBirdDie());
	}
}

void Game::render() {
	SDL_RenderClear(ren);

	background->Draw(ren);

	bird->Draw(ren);

	for (int i = 0; i < 3; i++) {
		topPipe[i].Draw(ren);
		bottomPipe[i].Draw(ren);
	}

	SDL_RenderPresent(ren);
}

void Game::close() {
	SDL_DestroyWindow(window);

	SDL_DestroyRenderer(ren);

	SDL_Quit();
}

void Game::handleEvent() {
	SDL_Event e;
	SDL_PollEvent(&e);
	switch (e.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	}
	bird->HandleInput(e);
	for (int i = 0; i < 3; i++) {
		if (bird->checkCollision(topPipe[i].GetDest()) || bird->checkCollision(bottomPipe[i].GetDest())) 
			bird->gameOver();	
	}
	
}

bool Game::Running() {
	return isRunning;
}