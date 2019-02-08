#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
using namespace std;
const int WindowWidth=300, WindowHeight=300;

void showWindow(SDL_Renderer*);

int main(int argc,char* args[]){
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window1,*window2,*window3;
	SDL_Renderer* render1,*render2,*render3;
	SDL_CreateWindowAndRenderer(WindowWidth,WindowHeight,SDL_WINDOW_FULLSCREEN,&window1,&render1);
	SDL_CreateWindowAndRenderer(WindowWidth,WindowHeight,SDL_WINDOW_BORDERLESS,&window2,&render2);
	SDL_CreateWindowAndRenderer(WindowWidth,WindowHeight,SDL_WINDOW_RESIZABLE,&window3,&render3);
	showWindow(render1);	
	SDL_DestroyWindow(window1);
	SDL_DestroyRenderer(render1);
	cout<<"full screen window"<<endl;
	showWindow(render2);
	SDL_DestroyWindow(window2);
	SDL_DestroyRenderer(render2);
	cout<<"no broder window"<<endl;
	showWindow(render3);
	SDL_DestroyWindow(window3);
	SDL_DestroyRenderer(render3);
	cout<<"resizable window"<<endl;
	return 0;
}

void showWindow(SDL_Renderer* render){
	SDL_Event event;
	bool isquit = false;
	while(!isquit){
		SDL_SetRenderDrawColor(render,255,255,255,255);
		SDL_RenderClear(render);
		while(SDL_PollEvent(&event)){
			if(event.type==SDL_QUIT)
				isquit=true;
			if(event.type==SDL_KEYDOWN)
				if(event.key.keysym.scancode==SDL_SCANCODE_ESCAPE)
					isquit=true;
		}
		SDL_RenderPresent(render);
		SDL_Delay(50);
	}
}
