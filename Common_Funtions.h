#ifndef COMMON_FUNTIONS_H_
#define COMMON_FUNTIONS_H_

#include <Windows.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <string>
#include "BaseObject.h"
#include "Bird.h"
#include "Game.h"
#include "Pipe.h"
#include "Background.h"
#include "Score.h"
#include <ctime>

//screen
const int SCREEN_WIDTH = 540;
const int SCREEN_HEIGHT = 720;

//bird 
const int BIRD_WIDTH = 50;
const int BIRD_HEIGHT = 50;
const float G = 0.3;

//pipe
const int PIPE_WIDTH = 50;
const int PIPE_HEIGHT = 300;
const int SPACE = 190;
const int MOVING_PIPE = 1;

// coin
const int COIN_WIDTH = 55;
const int COIN_HEIGHT = 55;

#endif // !COMMON_FUNTIONS_H_
 
