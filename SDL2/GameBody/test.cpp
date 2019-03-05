#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "GameBody.hpp"

class OwnGame : public GameBody{
	public:
	OwnGame():GameBody("test",700,700,SDL_WINDOW_RESIZABLE,30){};
};

/*
int main(int argc,char* args[]){
	OwnGame body;
	while(body.isQuit()==false)
		body.step();
	return 0;
}
*/
RUN_APP(OwnGame)
