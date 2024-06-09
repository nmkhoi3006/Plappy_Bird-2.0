#include "Menu.h"

Menu::Menu() {
<<<<<<< HEAD
	button[PLAY] = new Button(200, 300);
	button[QUIT] = new Button(200, 450);
	button[SOUNDON] = new Button(450, 600);
	button[SOUNDOFF] = new Button(450, 600);
	sound = true;

	//button[PLAY]->setPosition(230, 450);
	//button[QUIT]->setPosition(241, 587);
	button[SOUNDON]->SetDest(450, 600, 70, 70);
	button[SOUNDOFF]->SetDest(450, 600, 70, 70);
}

void Menu::selectButton(SDL_Event e, bool loading, Bird* _bird, Game* _game) {
		for (Button* b : button) {
			b->handleIntersection(e);
		}

		switch (e.type) {
		case SDL_MOUSEBUTTONDOWN:
			if (e.button.state == SDL_BUTTON_LEFT) {
				if (button[PLAY]->intersect) {
					Update();
					Mix_PlayChannel(-1, _game->click, 0);
					_bird->playing = true;
					button[PLAY]->intersect = false;
					return;
				}
				else if (button[QUIT]->intersect) {
					_game->isRunning = false;
					Mix_PlayChannel(-1, _game->click, 0);
					button[QUIT]->intersect = false;
					return;
				}
				if (button[SOUNDON]->intersect || button[SOUNDOFF]->intersect) {
					if (sound) {
						Mix_PauseMusic();
						Mix_Pause(-1);
						Mix_VolumeMusic(0);
						sound = false;
						button[SOUNDON]->SetDest(-100, -100, 0, 0);
						button[SOUNDOFF]->SetDest(450, 600, 70, 70);

					}
					else {
						Mix_VolumeMusic(100);
						Mix_ResumeMusic();
						Mix_Resume(-1);
						sound = true;
						button[SOUNDOFF]->SetDest(-100, -100, 0, 0);
						button[SOUNDON]->SetDest(450, 600, 70, 70);
					}
				}
				if (_bird->birdDie) {

				}
			}
			break;
		}
	}


void Menu::Update() {
	for (int i = 0; i < 4; i++) {
		button[i]->SetDest(-100, -100, 0, 0);
		button[i]->freeButton();
	}
}

void Menu::Draw(SDL_Renderer* ren) {
	for (int i = 0; i < 2; i++) {
		SDL_Rect dst = button[i]->GetDest();
		SDL_RenderCopy(ren, button[i]->GetTexture(), NULL, &dst);
	}
	SDL_Rect dst;
	if (sound) {
		dst = button[SOUNDON]->GetDest();
		SDL_RenderCopy(ren, button[SOUNDON]->GetTexture(), NULL, &dst);
	}
	else {
		dst = button[SOUNDOFF]->GetDest();
		SDL_RenderCopy(ren, button[SOUNDOFF]->GetTexture(), NULL, &dst);
=======
	button[PLAY] = new Button(200, 200);
	button[QUIT] = new Button(50, 50);
	button[HELP] = new Button(140, 129);
	button[SOUND] = new Button(200, 231);

	/*button[PLAY]->setPosition(230, 450);
	button[QUIT]->setPosition(241, 587);
	button[HELP]->setPosition(145, 278);
	button[SOUND]->setPosition(245, 100);*/
}

bool Menu::selectButton(SDL_Event e, bool loading) {
	while (loading) {
		for (Button* b : button) {
			b->handleIntersection(e);
		}
		while (SDL_PollEvent(&e)) {
			switch (e.type) {
			case SDL_MOUSEBUTTONDOWN:
				if (e.button.state == SDL_BUTTON_LEFT) {
					if (button[PLAY]->intersect)
						return true;
					if (button[QUIT]->intersect) {
						return false;
					}
				}
				break;
			}
		}
	}
}
void Menu::Draw(SDL_Renderer* ren) {
	for (int i = 0; i < 2; i++) {
		SDL_Rect dst = button[i]->GetDest();
		SDL_RenderCopy(ren, button[i]->GetTexture(), NULL,&dst );
>>>>>>> 8e5f4d90d09fd94ed5a9cedc180ee1dfdc6984fa
	}
}

Menu::~Menu() {
	delete button[PLAY];
	delete button[QUIT];
}

void Menu::initMenu(SDL_Renderer* ren) {
	button[PLAY]->CreateTexture("IMG/play.png", ren);
<<<<<<< HEAD
	button[QUIT]->CreateTexture("IMG/quit.png", ren);
	button[SOUNDON]->CreateTexture("IMG/sound on.png", ren);
	button[SOUNDOFF]->CreateTexture("IMG/sound off.png", ren);
=======
	button[QUIT]->CreateTexture("IMG/play.png", ren);
>>>>>>> 8e5f4d90d09fd94ed5a9cedc180ee1dfdc6984fa
}