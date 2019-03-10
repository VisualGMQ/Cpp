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
			if(event.type==SDL_KEYDOWN)
				SDL_Log("you pressed %d,and the key repeated %d times",event.key.keysym.scancode,event.key.repeat);
			if(event.type==SDL_KEYUP)
				SDL_Log("you released %d,and the key repeated %d times",event.key.keysym.scancode,event.key.repeat);

		}
	SDL_Delay(30);
	}
}
