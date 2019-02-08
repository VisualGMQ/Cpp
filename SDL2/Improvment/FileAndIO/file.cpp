#include <iostream>
#include <SDL2/SDL.h>
using namespace std;

int main(int argc,char** argv){
	SDL_Init(SDL_INIT_EVERYTHING);
	cout<<"get based path:"<<SDL_GetBasePath()<<endl;
	return 0;
}
