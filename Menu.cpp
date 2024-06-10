#include "Menu.h"

Menu::Menu() {

	help = new BaseObject();
	for (int i = 0; i < 60; i++) {
		if (i<30)
			frame_clip[i] = { 0, 0, 169, 34 };
		else 
			frame_clip[i] = { 0, 34, 169, 34 };
		
	}
	//frame_clip[0] = { 0, 0, 169, 34 };
	//frame_clip[1] = { 0, 34, 169, 34 };
	_frame = 0;

	button[PLAY] = new Button(200, 300);
	button[QUIT] = new Button(200, 450);
	button[SOUNDON] = new Button();
	button[SOUNDOFF] = new Button();
	button[HELP] = new Button();
	button[BACK] = new Button();
	sound = true;

	//button[PLAY]->setPosition(230, 450);
	//button[QUIT]->setPosition(241, 587);
	button[SOUNDON]->SetDest(500, 600, 100, 100);
	button[SOUNDOFF]->SetDest(500, 600, 100, 100);
}

void Menu::selectButton(SDL_Event e, bool loading, Bird* _bird, Game* _game) {
		for (Button* b : button) {
			b->handleIntersection();
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
					Mix_PlayChannel(-1, _game->click, 0);
					if (sound) {
						Mix_PauseMusic();
						Mix_Pause(-1);
						Mix_VolumeMusic(0);
						sound = false;
						button[SOUNDON]->SetDest(-100, -100, 0, 0);
						button[SOUNDOFF]->SetDest(500, 600, 100, 100);

					}
					else {
						Mix_VolumeMusic(300);
						Mix_ResumeMusic();
						Mix_Resume(-1);
						sound = true;
						button[SOUNDOFF]->SetDest(-100, -100, 0, 0);
						button[SOUNDON]->SetDest(500, 600, 100, 100);
					}
				}
				if (button[HELP]->intersect) {
					button[HELP]->intersect = false;
					Mix_PlayChannel(-1, _game->click, 0);
					Update();
					int x = (SCREEN_WIDTH - 300) / 2;
					int y = (SCREEN_HEIGHT - 100) / 2;

					help->SetDest(x, y, 300, 100);

					button[BACK]->SetDest(200, 450, 100, 100);
				}
				if (button[BACK]->intersect) {
					button[BACK]->intersect = false;
					Mix_PlayChannel(-1, _game->click, 0);

					initMenu(_game->ren);
				}
			}
			break;
		}
	}

void Menu::Update() {
	for (int i = 0; i < 5; i++) {
		button[i]->SetDest(-100, -100, 0, 0);
	}
}

void Menu::Draw(SDL_Renderer* ren) {
	for (int i = 0; i < 5; i++) {
		SDL_Rect dst = button[i]->GetDest();
		button[i]->Draw(ren);
		//SDL_RenderCopy(ren, button[i]->GetTexture(), NULL, &dst);
	}
	SDL_Rect dst;
	if (sound) {
		dst = button[SOUNDON]->GetDest();
		button[SOUNDON]->handleIntersection();
		SDL_Rect _src = button[SOUNDON]->GetSrc();
		SDL_RenderCopy(ren, button[SOUNDON]->GetTexture(), &_src, &dst);
	}
	else {
		dst = button[SOUNDOFF]->GetDest();
		button[SOUNDON]->handleIntersection();
		SDL_Rect _src = button[SOUNDON]->GetSrc();
		SDL_RenderCopy(ren, button[SOUNDOFF]->GetTexture(), &_src, &dst);
  }
}

Menu::~Menu() {
	delete button[PLAY];
	delete button[QUIT];
}

void Menu::initMenu(SDL_Renderer* ren) {
	button[PLAY]->CreateTexture("IMG/Play1.png", ren);
	button[QUIT]->CreateTexture("IMG/Quit1.png", ren);
	button[SOUNDON]->CreateTexture("IMG/SoundOn1.png", ren);
	button[SOUNDOFF]->CreateTexture("IMG/SoundOff1.png", ren);

	button[HELP]->CreateTexture("IMG/1.png", ren);
	button[BACK]->CreateTexture("IMG/Back.png", ren);
	help->CreateTexture("IMG/help.png", ren);

	button[SOUNDON]->SetDest(500, 600, 100, 100);
	button[SOUNDOFF]->SetDest(500, 600, 100, 100);
	button[PLAY]->SetDest(200, 300, 100, 100);
	button[QUIT]->SetDest(200, 450, 100, 100);

	button[HELP]->SetDest(-50, 570, 100, 100);
	button[BACK]->SetDest(-100, -100, 0, 0);
	help->SetDest(-100, -100, 0, 0);
}

void Menu::Free() {
	for (int i = 0; i < 4; i++) {
		button[i]->freeButton();
	}
}

void Menu::setClip(SDL_Event e) {
	for (Button* b : button) {
		b->handleIntersection();
	}
}

void Menu::setClipHelp() {
	++_frame;
	if (_frame > 60)
		_frame = 0;

}

void Menu::DrawHelp(SDL_Renderer* ren) {
	SDL_Rect tmp = help->GetDest();
	SDL_RenderCopy(ren, help->GetTexture(), &frame_clip[_frame], &tmp);
}