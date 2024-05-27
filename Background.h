#ifndef BACKGROUND_H_
#define BACKGROUND_H_

#include "Common_Funtions.h"

class Background : public BaseObject {
public:
	Background() { ; }
	~Background() { ; }

	void Draw(SDL_Renderer* ren) override;
};
#endif // !BACKGROUND_H_
