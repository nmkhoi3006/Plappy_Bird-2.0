#include "Score.h"

Score::Score() {
	coinWidth = COIN_WIDTH;
	coinHeight = COIN_HEIGHT;

	for (int i = 0; i < 3; i++) {
		eated[i] = false;
	}
}

void Score::Update(int i) {
	int x = (PIPE_WIDTH - COIN_WIDTH) / 2;
	int y = (SPACE - COIN_HEIGHT) / 2;

	xCoin[i] = g_xPosPipe[i] + x;
	yCoin[i] = g_heightTopPipe[i] + y;

	if (xCoin[i] <= -COIN_WIDTH)
		eated[i] = false;
}