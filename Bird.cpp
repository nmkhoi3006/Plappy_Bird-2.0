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

	frameWidth = 92;
	frameHeight = 64;
	_frame = 0;

	for (int i = 0; i < 3; i++) {
		frameClip[i].x = i * frameWidth;
		frameClip[i].y = 0;
		frameClip[i].w = frameWidth;
		frameClip[i].h = frameHeight;
	}

	//this->src = this->SetScr()
}

Bird::~Bird() {
	;
}

void Bird::update() {
	if (!playing) {
		SetDest(0, 0, 0, 0);
		return;
	}

	if (birdDie) {
		Jumpping = false;
	}

	if (Jumpping) {
		speed = jumpHeight;
		Jumpping = false;
	}

	if (bird_pos >= SCREEN_HEIGHT - BIRD_HEIGHT - 56) {
		birdDie = true;
		bird_pos = SCREEN_HEIGHT - BIRD_HEIGHT - 56;
		speed = 0;
	}

	bird_pos += speed/4.55;
	speed += G/2.5;
	SetDest(110, (int)bird_pos, BIRD_WIDTH, BIRD_HEIGHT);
}

void Bird::SetClip() {
	++_frame;
	if (_frame >= 3)
		_frame = 0;
	this->src = frameClip[_frame];
}

void Bird::Draw(SDL_Renderer* ren) {
	SDL_RenderCopy(ren, this->tex, &this->src, &this->dest);
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

bool Bird::checkBirdDie() {
	return birdDie;
}
