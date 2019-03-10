#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../src/GameBody.hpp"

class OwnGame : public GameBody{
public:
	OwnGame():GameBody("test",700,700,SDL_WINDOW_SHOWN,30){};
};

RUN_APP(OwnGame)
