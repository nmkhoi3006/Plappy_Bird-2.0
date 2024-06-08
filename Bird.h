#ifndef BIRD_H_
#define BIRD_H_

#include "Common_Funtions.h"

class Pipe;

class Bird : public BaseObject {
private:
	int width;
	int height;

	float bird_pos;
	double jumpHeight;
	float speed;
	double jumpTimer;
	double lastJump;

	SDL_Rect frameClip[3];
	int frameWidth;
	int frameHeight;
	int _frame;
public:
	bool playing;
	bool birdDie;
	bool Jumpping;
	bool start;

	bool movingPipe;

	Bird();
	~Bird();
	//void SetClip(BaseObject b0, BaseObject b1, BaseObject b2, SDL_Renderer* ren);
	void update();
	void HandleInput(SDL_Event e, Mix_Chunk* wing);

	void Draw(SDL_Renderer* ren) override;
	void Jump();
	double GetTimeJump();

	bool checkCollision(SDL_Rect Object);
	
	void SetClip();

	bool checkBirdDie();

};
#endif // !BIRD_H_
