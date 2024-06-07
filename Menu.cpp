#include "Menu.h"

Menu::Menu() {
	button[PLAY] = new Button(200, 200);
	button[QUIT] = new Button(50, 50);
	button[HELP] = new Button(140, 129);
	button[SOUND] = new Button(200, 231);

	/*button[PLAY]->setPosition(230, 450);
	button[QUIT]->setPosition(241, 587);
	button[HELP]->setPosition(145, 278);
	button[SOUND]->setPosition(245, 100);*/
}

void Menu::selectButton(SDL_Event e, bool loading, bool& playing) {
	while (loading) {
		for (Button* b : button) {
			b->handleIntersection(e);
		}
		while (SDL_PollEvent(&e)) {
			switch (e.type) {
			case SDL_MOUSEBUTTONDOWN:
				if (e.button.state == SDL_BUTTON_LEFT) {
					if (button[PLAY]->intersect) {
						Update();
						playing = true;
						return;

					}
					if (button[QUIT]->intersect) {
						return;
					}
				}
				break;
			default:
				break;
			}

		}
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
	button[QUIT]->CreateTexture("IMG/play.png", ren);
}