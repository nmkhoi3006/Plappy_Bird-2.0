#ifndef SCORE_H_
#define SCORE_H_

#include "Common_Funtions.h"

static int xCoin[3];
static int yCoin[3];
static bool eated[3];

class Score : public BaseObject {
private: 
	int coinWidth;
	int coinHeight;
public:

	Score();
	void Update(int i, Pipe* a);
	void checkEated(int i, Bird* a, Mix_Chunk* point, int &p_score);
	void Draw(SDL_Renderer* ren);

	int GetXCoin(int i);
	int GetYCoin(int i);
};

#endif // !SCORE_H_
