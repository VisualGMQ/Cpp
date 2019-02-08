#include <iostream>
#include <SDL2/SDL.h>
using namespace std;

SDL_Window* window = nullptr;
SDL_Renderer* render = nullptr;
SDL_Event event;
bool isquit=false;

int main(int argc,char** argv){
	if(SDL_Init(SDL_INIT_EVERYTHING)<0){
		cerr<<"SDL not init";
		return -1;
	}
	SDL_Rect inputrect={0,0,300,100};
	SDL_CreateWindowAndRenderer(300,300,SDL_WINDOW_SHOWN,&window,&render);
	SDL_SetTextInputRect(&inputrect);	
	SDL_StartTextInput();
	while(!isquit){
		while(SDL_PollEvent(&event)){
			if(event.type==SDL_QUIT)
				isquit=true;
		}
	}
	SDL_StopTextInput();
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(render);
	SDL_Quit();
}
