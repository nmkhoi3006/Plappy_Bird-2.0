#include "Menu.h"

Menu::Menu() {
	button[PLAY] = new Button(200, 300);
	button[QUIT] = new Button(200, 400);
	button[HELP] = new Button(350, 129);
	button[SOUND] = new Button(200, 231);

	/*button[PLAY]->setPosition(230, 450);
	button[QUIT]->setPosition(241, 587);
	button[HELP]->setPosition(145, 278);
	button[SOUND]->setPosition(245, 100);*/
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
				_bird->playing = true;
				return;
			}
			if (button[QUIT]->intersect) {
				_game->isRunning = false;
				return;
			}
		}
		break;
	case SDL_QUIT:
		_game->isRunning = false;
		break;
	default:
		return;
	}
}

void Menu::Update() {
	for (int i = 0; i < 2; i++) {
		button[i]->SetDest(0, 0, 0, 0);
	}
}

void Menu::Draw(SDL_Renderer* ren) {
	for (int i = 0; i < 2; i++) {
		SDL_Rect dst = button[i]->GetDest();
		SDL_RenderCopy(ren, button[i]->GetTexture(), NULL,&dst );
	}
}

Menu::~Menu() {
	delete button[PLAY];
	delete button[QUIT];
}

void Menu::initMenu(SDL_Renderer* ren) {
	button[PLAY]->CreateTexture("IMG/Play.png", ren);
	button[QUIT]->CreateTexture("IMG/Quit.png", ren);
}