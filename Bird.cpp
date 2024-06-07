#include "Bird.h"
#include "Pipe.h"

Bird::Bird() {
	width = BIRD_WIDTH;
	height = BIRD_HEIGHT;

	Jumpping = false;
	playing = false;
	birdDie = false;

	jumpHeight = -10;
	bird_pos = 0;
	speed = 0;
	lastJump = 0;

	//this->src = this->SetScr()
}

Bird::~Bird() {
	;
}

//animation
//void Bird::SetClip(BaseObject b0, BaseObject b1, BaseObject b2, SDL_Renderer* ren) {
//	b0.CreateTexture("IMG/bird0.png", ren);
//	b1.CreateTexture("IMG/bird1.png", ren);
//	b2.CreateTexture("IMG/bird2.png", ren);
//}

void Bird::update() {
	if (birdDie) {
		Jumpping = false;
	}
	if (Jumpping) {
		speed = jumpHeight;
		Jumpping = false;
	}

	if (!playing) {
		bird_pos = 300;
		speed = 0;
	}
	if (bird_pos >= SCREEN_HEIGHT - BIRD_HEIGHT) {
		gameOver();
		bird_pos = SCREEN_HEIGHT - BIRD_HEIGHT;
		speed = 0;
	}

	bird_pos += speed/4.55;
	speed += G/2.5;
	SetDest(110, (int)bird_pos, BIRD_WIDTH, BIRD_HEIGHT);
}

void Bird::Draw(SDL_Renderer* ren) {
	SDL_RenderCopy(ren, this->tex, NULL, &this->dest);
}

double Bird::GetTimeJump() {
	return SDL_GetTicks();
}

void Bird::Jump() {
	jumpTimer = GetTimeJump();
	if (jumpTimer - lastJump > 165)
	{
		Jumpping = true;
		lastJump = jumpTimer;
	}
	else
	{
		Jumpping = false;
	}
}

void Bird::HandleInput(SDL_Event e, Mix_Chunk* wing) {
	switch (e.key.keysym.sym)
	{
	case SDLK_SPACE:
		//Jump();
		playing = true;
		Jumpping = true;
		Mix_PlayChannel(-1, wing, 0);
		break;
	default:
		break;
	}
}

bool Bird::PlayerIsPlaying() {
	return playing;
}

bool Bird::checkCollision(SDL_Rect Object) {
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	leftA = this->dest.x;
	rightA = leftA + this->dest.w;
	topA = this->dest.y;
	bottomA = topA + this->dest.h;

	leftB = Object.x;
	rightB = leftB + Object.w;
	topB = Object.y;
	bottomB = topB + Object.h;

	if (bottomA <= topB)
		return false;
	if (topA >= bottomB)
		return false;
	if (rightA <= leftB)
		return false;
	if (leftA >= rightB)
		return false;
	return true;
}

void Bird::gameOver() {
	birdDie = true;
}

bool Bird::checkBirdDie() {
	return birdDie;
}