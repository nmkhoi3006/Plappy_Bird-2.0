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

	void Update(int i);
	Score();

};

#endif // !SCORE_H_
