#ifndef PIPE_H_
#define PIPE_H_

#include "Common_Funtions.h"
#include <ctime>

static int g_heightBottomPipe[3];
static int g_heightTopPipe[3];
static int g_xPos[3];

class Pipe : public BaseObject {
public:
	Pipe() { ; }
	~Pipe() { ; }

	void Draw(SDL_Renderer* ren) override;

	void initPipe(int xPos);

	int randomHeight();

	void updateTopPipe(int index, bool birdDie);
	void updateBottomPipe(int index, bool birdDie);

};
#endif // !PIPE_H_

