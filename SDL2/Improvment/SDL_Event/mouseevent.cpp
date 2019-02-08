#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
using namespace std;
SDL_Window* window = nullptr;
SDL_Renderer* render = nullptr;
SDL_Event event;
bool isquit=false;

int main(int argc,char** argv){
	if(SDL_Init(SDL_INIT_EVERYTHING)<0){
		cerr<<"SDL Init Error";
		return -1;
	}
	SDL_CreateWindowAndRenderer(700,700,SDL_WINDOW_SHOWN,&window,&render);
	while(!isquit){
		while(SDL_PollEvent(&event)){
			if(event.type==SDL_QUIT){
				SDL_Log("SDL Quit");
				isquit=true;
			}
			if(event.type==SDL_MOUSEMOTION)
				SDL_Log("mouse x:%d,mouse y:%d",event.motion.x,event.motion.y);
			if(event.type==SDL_MOUSEBUTTONDOWN)
				SDL_Log("mouse clicked %d,mouse button:%d",event.button.clicks,event.button.button);
			if(event.type==SDL_MOUSEBUTTONUP)
				SDL_Log("mouse clicked %d,mouse button:%d",event.button.clicks,event.button.button);
			
		}
	}
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(render);
	SDL_Quit();
}
