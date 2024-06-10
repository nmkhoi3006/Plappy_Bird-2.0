#include "MenuOver.h"
#include <algorithm>

MenuOver::MenuOver() {
	board = new BaseObject();

	s_val = 0;
	hs_val = 0;

	s = new TextObject();
	hs = new TextObject();

	button[REPLAY] = new Button();
	button[QUIT] = new Button();
}

void MenuOver::initMenuOver(SDL_Renderer* ren) {
	board->CreateTexture("IMG/board.png", ren);

	button[REPLAY]->CreateTexture("IMG/Replay2.png", ren);
	button[QUIT]->CreateTexture("IMG/Quit1.png", ren);

	int xPos = (SCREEN_WIDTH - BOARD_WIDTH) / 2;
	int yPos = (SCREEN_HEIGHT - BOARD_HEIGHT) / 2;

	board->SetDest(xPos, yPos, BOARD_WIDTH, BOARD_HEIGHT);

	button[REPLAY]->SetDest(xPos, yPos+330, 100, 100);
	button[QUIT]->SetDest(xPos+200, yPos+330, 100, 100);

	int x = (BOARD_WIDTH - SCORE_WIDTH) / 2 + xPos;
	int y = (BOARD_HEIGHT - SCORE_HEIGHT) / 2 + yPos;

	s->SetDest(x-45, y, SCORE_WIDTH, SCORE_HEIGHT);
	hs->SetDest(x+70, y-35, SCORE_WIDTH, SCORE_HEIGHT);
}

void MenuOver::Draw(SDL_Renderer* ren) {
	board->Draw(ren);
	
	s->Write(std::to_string(s_val), "FontText/123.ttf", ren, 72);
	hs->Write(std::to_string(hs_val), "FontText/123.ttf", ren, 72);

	s->Draw(ren);
	hs->Draw(ren);

	button[REPLAY]->Draw(ren);
	button[QUIT]->Draw(ren);
}

void MenuOver::Update(int _s_val, int _hs_val) {
	this->s_val = _s_val;
	this->hs_val = _hs_val;
}

void MenuOver::handleInput(SDL_Event e, Game* _game, Bird* _bird) {
	for (Button* b : button) {
		b->handleIntersection();
	}

	switch (e.type) {
	case SDL_MOUSEBUTTONDOWN:
		if (e.button.state == SDL_BUTTON_LEFT) {
			if (button[REPLAY]->intersect) {
				Mix_PlayChannel(-1, _game->click, 0);

				_game->newGame();

				button[REPLAY]->intersect = false;
			}
			else if (button[QUIT]->intersect) {
				_game->isRunning = false;
				Mix_PlayChannel(-1, _game->click, 0);
				button[QUIT]->intersect = false;
				return;
			}
		}
		break;
	}
}

void MenuOver::FreeMenu() {
	board->Free();
	s->Free();
	hs->Free();
	button[REPLAY]->freeButton();
	button[QUIT]->freeButton();

	board->SetDest(-100, -100, 0, 0);
	s->SetDest(-100, -100, 0, 0);
	hs->SetDest(-100, -100, 0, 0);
	button[REPLAY]->SetDest(-100, -100, 0, 0);
	button[QUIT]->SetDest(-100, -100, 0, 0);
}

void MenuOver::setClip() {
	for (Button* b : button) {
		b->handleIntersection();
	}
}