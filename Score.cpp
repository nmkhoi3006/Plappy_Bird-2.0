#include "Score.h"

Score::Score() {
	coinWidth = COIN_WIDTH;
	coinHeight = COIN_HEIGHT;

	for (int i = 0; i < 3; i++) {
		eated[i] = false;
	}
}

void Score::Update(int i, Pipe a) {
	int x = (PIPE_WIDTH - COIN_WIDTH) / 2;
	int y = (SPACE - COIN_HEIGHT) / 2;

	xCoin[i] = a.getXPos(i) + x;
	yCoin[i] = a.GetHeightTopPipe(i) + y;

	if (xCoin[i] <= -COIN_WIDTH)
		eated[i] = false;

}
void Score::checkEated(int i, Bird* a, Mix_Chunk* point) {
	int x = a->GetDest().x;
	int y = a->GetDest().y;
	if (xCoin[i] == x) {
		eated[i] = true;
		Mix_PlayChannel(-1, point, 0);
	}
}

int Score::GetXCoin(int i) {
	return xCoin[i];
}

int Score::GetYCoin(int i) {
	return yCoin[i];
}
