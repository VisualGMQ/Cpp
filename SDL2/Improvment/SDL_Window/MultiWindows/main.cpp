#include <SDL2/SDL.h>
#include <thread>
#include <iostream>
using namespace std;

void runWindow(int argc,char** argv){
	SDL_Window* win = SDL_CreateWindow("MultiWindow", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 700, 700, SDL_WINDOW_SHOWN);
	SDL_Renderer* render = SDL_CreateRenderer(win, -1, 0);
	SDL_Event event;
	bool isQuit = false;
	SDL_SetRenderDrawColor(render ,255,255,255,255);
	while(!isQuit){
		SDL_RenderClear(render);
		while(SDL_PollEvent(&event)){
			if(event.type == SDL_QUIT)
					isQuit = true;
		}
		SDL_RenderPresent(render);	
	}
}

int main(int argc, char** args){
	SDL_Init(SDL_INIT_EVERYTHING);
	//thread th(runWindow,argc,args);
	SDL_Window* win1 = SDL_CreateWindow("MultiWindow1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 700, 700, SDL_WINDOW_SHOWN);
	SDL_Window* win2 = SDL_CreateWindow("MultiWindow2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 700, 700, SDL_WINDOW_SHOWN);
	SDL_Renderer* render1 = SDL_CreateRenderer(win1, -1, 0);
	SDL_Renderer* render2 = SDL_CreateRenderer(win2, -1, 0);
	SDL_Event event;
	bool isQuit = false;
	SDL_SetRenderDrawColor(render2 ,255,255,255,255);
	SDL_SetRenderDrawColor(render1 ,0,255,0,255);
	while(!isQuit){
		SDL_RenderClear(render1);
		SDL_RenderClear(render2);
		while(SDL_PollEvent(&event)){
			if(event.window.event == SDL_WINDOWEVENT_CLOSE)
					isQuit = true;
		}
		//SDL_UpdateWindowSurface(win1);
		//SDL_UpdateWindowSurface(win2);
		SDL_RenderPresent(render1);
		SDL_RenderPresent(render2);
		SDL_Delay(30);
	}
	SDL_Quit();
	return 0;
}
