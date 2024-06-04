#include "Pipe.h"

Pipe::Pipe(){
	Width = PIPE_WIDTH;
	Height = PIPE_HEIGHT;
}

void Pipe::Draw(SDL_Renderer* ren) {
	SDL_RenderCopy(ren, this->tex, NULL, &this->dest);
}

int Pipe::randomHeight() {
	return rand() * rand() % (330 - 100 + 1) + 100;
}

void Pipe::initPipe(int pos) {
	srand(time(NULL));
	g_xPosPipe[pos] = (pos + 4) * 320;
	g_heightTopPipe[pos] = randomHeight();
	g_heightBottomPipe[pos] = SCREEN_HEIGHT - g_heightTopPipe[pos] - SPACE;
}

void Pipe::updateTopPipe(int index, bool isPlaying, bool birdDie) {
	if (g_xPosPipe[index] <= -PIPE_WIDTH) {
		g_heightTopPipe[index] = randomHeight();
		g_xPosPipe[index] = 900;
	}
	else {
		if (isPlaying && !birdDie) {
			//moving pipe
			g_xPosPipe[index] -= MOVING_PIPE;
		}
	}
	this->SetDest(g_xPosPipe[index], 0, PIPE_WIDTH, g_heightTopPipe[index]);
}

void Pipe::updateBottomPipe(int index, bool isPlaying, bool birdDie) {
	g_heightBottomPipe[index] = g_heightTopPipe[index] + SPACE;
	this->SetDest(g_xPosPipe[index], g_heightBottomPipe[index], PIPE_WIDTH, SCREEN_HEIGHT - g_heightBottomPipe[index] - 56);
}