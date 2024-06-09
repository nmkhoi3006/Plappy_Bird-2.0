#include "MenuOver.h"
#include <algorithm>

MenuOver::MenuOver() {
	board = new BaseObject();

	s_val = 0;
	hs_val = 0;

	s = new TextObject();
	hs = new TextObject();

	button[REPLAY] = new Button();
	button[EXIT] = new Button();
}

void MenuOver::initMenuOver(SDL_Renderer* ren) {
	board->CreateTexture("IMG/board.png", ren);
	board->SetDest((SCREEN_WIDTH - 300) / 2, (SCREEN_HEIGHT - 300) / 2, 300, 300);

	button[REPLAY]->CreateTexture("IMG/Replay.png", ren);
	button[EXIT]->CreateTexture("IMG/Quit.png", ren);

	button[REPLAY]->SetDest(200, 450, 100, 100);
	button[EXIT]->SetDest(350, 450, 100, 100);

	s->SetDest(100, 300, SCORE_WIDTH, SCORE_HEIGHT);
	hs->SetDest(250, 300, SCORE_WIDTH, SCORE_HEIGHT);
}

void MenuOver::Draw(SDL_Renderer* ren) {
	board->Draw(ren);
	
	s->Write(std::to_string(s_val), "FontText/123.ttf", ren, 72);
	hs->Write(std::to_string(hs_val), "FontText/123.ttf", ren, 72);

	s->Draw(ren);
	hs->Draw(ren);

	button[REPLAY]->Draw(ren);
	button[EXIT]->Draw(ren);
}

void MenuOver::Update(int _s_val, int _hs_val) {
	this->s_val = _s_val;
	this->hs_val = _hs_val;
}

void MenuOver::handleInput(SDL_Event e, Game* _game, Bird* _bird) {
	for (Button* b : button) {
		b->handleIntersection(e);
	}

	switch (e.type) {
	case SDL_MOUSEBUTTONDOWN:
		if (e.button.state == SDL_BUTTON_LEFT) {
			if (button[REPLAY]->intersect) {
				_bird->birdDie = false;
			}
			else if (button[EXIT]->intersect) {
				//to do
				;
			}
		}
		break;
	}
}