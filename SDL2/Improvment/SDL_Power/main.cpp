#include <iostream>
#include <SDL2/SDL.h>
using namespace std;

int main(int argc,char** argv){
	int sec,per;
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_PowerState ps;
	ps = SDL_GetPowerInfo(&sec,&per);
	SDL_Log("the power state is:%d.It will run %d seconds and remaining %d percent",ps,sec,per);
	return 0;
}
