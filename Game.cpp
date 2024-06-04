#include "Game.h"

Pipe topPipe[3];
Pipe bottomPipe[3];

Game::Game() {
	window = NULL;
	ren = NULL;

	isRunning = false;

	background = new Background();

	bird = new Bird();

	Coin = NULL;

	Music = NULL;

	wing = NULL;
	die = NULL;
	hit = NULL;
	point = NULL;
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

	for (int i = 0; i < 3; i++) {
		topPipe[i].CreateTexture("IMG/pipeTop.png", ren);
		bottomPipe[i].CreateTexture("IMG/pipeBottom.png", ren);

		topPipe[i].initPipe(i);
	}

	background->CreateTexture("IMG/bg.png", ren);

	bird->CreateTexture("IMG/bird0.png", ren);


	//init SDL_mixer;
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		isRunning = false;
		return;
	}

	//load music
	Music = Mix_LoadMUS("Sound/gameLoop2.wav");
	if (Music == NULL) {
		isRunning = false;
		return;
	}

	//load sound effect
	wing = Mix_LoadWAV("Sound/wing.wav");
	if (wing == NULL) {
		isRunning = false;
		return;
	}
	die = Mix_LoadWAV("Sound/die.wav");
	if (die == NULL) {
		isRunning = false;
		return;
	}
	hit = Mix_LoadWAV("Sound/hit.wav");
	if (hit == NULL) {
		isRunning = false;
		return;
	}
	point = Mix_LoadWAV("Sound/point.wav");
	if(point == NULL){
		isRunning = false;
		return;
	}

	isRunning = true;

}

void Game::update() {
	bird->update();

	for (int i = 0; i < 3; i++) {
		topPipe[i].updateTopPipe(i, bird->PlayerIsPlaying(), bird->checkBirdDie());
		bottomPipe[i].updateBottomPipe(i, bird->PlayerIsPlaying(), bird->checkBirdDie());
		Coin->Update(i);
	}

	for (int i = 0; i < 3; i++) {
		if (bird->checkCollision(topPipe[i].GetDest()) || bird->checkCollision(bottomPipe[i].GetDest())) {
			Mix_PlayChannel(-1, hit, 0);
			Mix_PlayChannel(-1, die, 0);
			bird->gameOver();

		}
		int xBird = bird->GetDest().x;
		int yBird = bird->GetDest().y;
		if (xBird == xCoin[i] && yBird == yCoin[i]) {
			eated[i] = true;
			Mix_PlayChannel(-1, point, 0);
		}
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
	case SDL_KEYDOWN:
	{
		bird->HandleInput(e, wing);
		Mix_FreeMusic(Music);
		Music = NULL;
	}
	default:
		if (Mix_PlayingMusic() == 0)
		{
			//Play the music
			Mix_PlayMusic(Music, -1);
		}
		//If music is being played
		else
		{
			//If the music is paused
			if (Mix_PausedMusic() == 1)
			{
				//Resume the music
				Mix_ResumeMusic();
			}
			//If the music is playing
			else// C?N FIX
			{
				//Pause the music
				//Mix_PauseMusic();
			}
		}
		break;
	}
}

bool Game::Running() {
	return isRunning;
}