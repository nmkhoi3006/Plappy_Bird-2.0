#include "Game.h"

Pipe topPipe[3];
Pipe bottomPipe[3];

Game::Game() {
	window = NULL;
	ren = NULL;

	isRunning = false;

	loading = false;

	background = new Background();

	bird = new Bird();

	myMenu = new Menu();

	Coin = new Score();

	Music = NULL;

	wing = NULL;
	die = NULL;
	hit = NULL;
	point = NULL;
	click = NULL;

	T_Plappy = new TextObject();
	T_Bird = new TextObject();
	T_Score = new TextObject();
	score_val = 0;
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

	if (ren != NULL)
		SDL_SetRenderDrawColor(ren, 255, 0, 0, 255);

	for (int i = 0; i < 3; i++) {
		topPipe[i].CreateTexture("IMG/pipeTop.png", ren);
		bottomPipe[i].CreateTexture("IMG/pipeBottom.png", ren);

		topPipe[i].initPipe(i);
	}

	background->CreateTexture("IMG/bg.png", ren);

	bird->CreateTexture("IMG/bird.png", ren);

	myMenu->initMenu(ren);

	T_Plappy->Write("Plappy", "FontText/abc.ttf", ren, 300);
	T_Bird->Write("Bird", "FontText/abc.ttf", ren, 300);
	T_Plappy->SetDest(20, 20, 500, 100);
	T_Bird->SetDest(100, 150, 300, 100);

	T_Score->Write("Score:", "FontText/123.ttf", ren, 72);

	initAudio();

	isRunning = true;

}

void Game::initAudio() {
	//init SDL_mixer;
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		isRunning = false;
		return;
	}

	//load music
	Music = Mix_LoadMUS("Sound/gameLoop2.wav");
	if (Music == NULL) {
		Mix_VolumeMusic(100);
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
	if (point == NULL) {
		isRunning = false;
		return;
	}
	click = Mix_LoadWAV("Sound/click.wav");
	if (click == NULL) {
		isRunning = false;
		return;
	}
}

void Game::update() {
	bird->update(this);
	bird->SetClip();

	for (int i = 0; i < 3; i++) {
		topPipe[i].updateTopPipe(i, bird->playing, bird->checkBirdDie(), bird->movingPipe);
		bottomPipe[i].updateBottomPipe(i, bird->playing, bird->checkBirdDie(), bird->movingPipe);
		Coin->Update(i, topPipe[i]);
	}

	for (int i = 0; i < 3; i++) {
		if (bird->checkCollision(topPipe[i].GetDest()) || bird->checkCollision(bottomPipe[i].GetDest())) {
			bird->birdDie = true;

		}
		Coin->checkEated(i, bird, point, score_val);
	}

	if (bird->birdDie) {
		Mix_PlayChannel(-1, hit, 0);
		Mix_PlayChannel(-1, die, 0);
		hit = NULL;
		die = NULL;
	}

	std::string tmp = "Score:";
	tmp += std::to_string(score_val);
	T_Score->Write(tmp, "FontText/123.ttf", ren, 72);
}

void Game::render() {
	SDL_RenderClear(ren);

	background->Draw(ren);

	bird->Draw(ren);

	for (int i = 0; i < 3; i++) {
		topPipe[i].Draw(ren);
		bottomPipe[i].Draw(ren);
	}

	T_Plappy->Draw(ren);
	T_Bird->Draw(ren);

	T_Score->Draw(ren);

	myMenu->Draw(ren);
	loading = true;

	SDL_RenderPresent(ren);
}

void Game::close() {
	SDL_DestroyWindow(window);

	SDL_DestroyRenderer(ren);

	SDL_Quit();
}

void Game::handleEvent() {
	SDL_Event e;
	while (SDL_PollEvent(&e)) {

		switch (e.type) {
		case SDL_QUIT:
			isRunning = false;
			break;
		case SDL_KEYDOWN:
		{
			bird->HandleInput(e, wing);
			Mix_FreeMusic(Music);
			T_Score->SetDest((SCREEN_WIDTH - SCORE_WIDTH) / 2, 0, SCORE_WIDTH, SCORE_HEIGHT);
			T_Plappy->SetDest(0, 0, 0, 0);
			T_Bird->SetDest(0, 0, 0, 0);
			Music = NULL;
			break;
		}
		default:
			myMenu->selectButton(e, loading, bird, this);

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

				}
			}
			break;
		}
	}
}

bool Game::Running() {
	return isRunning;
}