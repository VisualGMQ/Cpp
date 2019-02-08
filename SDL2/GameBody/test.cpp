#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "GameBody.hpp"

int main(int argc,char* args[]){
	GameBody body("test",700,700,SDL_WINDOW_RESIZABLE,30);
	while(body.isQuit()==false)
		body.step();
	return 0;
}
