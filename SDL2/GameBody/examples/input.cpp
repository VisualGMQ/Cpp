#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "../src/GameBody.hpp"
using namespace std;

class OwnGame : public GameBody{
public:
	OwnGame():GameBody("test",700,700,SDL_WINDOW_SHOWN,30){};
	void update() override{
		cout<<gbInput::	
	}
};

RUN_APP(OwnGame)
