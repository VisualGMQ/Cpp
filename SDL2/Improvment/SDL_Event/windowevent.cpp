#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
using namespace std;
SDL_Window* window = nullptr;
SDL_Renderer* render = nullptr;
SDL_Event event;
bool isquit = false;

int main(int argc,char** argv){
	if(SDL_Init(SDL_INIT_EVERYTHING)<0){
		SDL_Log("SDL init error");
		return -1;
	}		
	SDL_CreateWindowAndRenderer(700,700,SDL_WINDOW_SHOWN,&window,&render);
	while(!isquit){
		while(SDL_PollEvent(&event)){
			if(event.type==SDL_APP_WILLENTERBACKGROUND)
				SDL_Log("SDL Will Enter Background");
			if(event.type==SDL_APP_DIDENTERBACKGROUND)
				SDL_Log("SDL Did Enter Background");
			if(event.type==SDL_APP_WILLENTERFOREGROUND)
				SDL_Log("SDL Will Enter Foreground");
			if(event.type==SDL_APP_DIDENTERFOREGROUND)
				SDL_Log("SDL Did enter foreground");
			if(event.type==SDL_WINDOWEVENT)
				switch(event.window.event){
					case SDL_WINDOWEVENT_SHOWN:
					    SDL_Log("Window %d shown", event.window.windowID);
					    break;
					case SDL_WINDOWEVENT_HIDDEN:
					    SDL_Log("Window %d hidden", event.window.windowID);
					    break;
					case SDL_WINDOWEVENT_EXPOSED:
					    SDL_Log("Window %d exposed", event.window.windowID);
					    break;
					case SDL_WINDOWEVENT_MOVED:
					    SDL_Log("Window %d moved to %d,%d",
						    event.window.windowID, event.window.data1,
						    event.window.data2);
					    break;
					case SDL_WINDOWEVENT_RESIZED:
					    SDL_Log("Window %d resized to %dx%d",
						    event.window.windowID, event.window.data1,
						    event.window.data2);
					    break;
					case SDL_WINDOWEVENT_SIZE_CHANGED:
					    SDL_Log("Window %d size changed to %dx%d",
						    event.window.windowID, event.window.data1,
						    event.window.data2);
					    break;
					case SDL_WINDOWEVENT_MINIMIZED:
					    SDL_Log("Window %d minimized", event.window.windowID);
					    break;
					case SDL_WINDOWEVENT_MAXIMIZED:
					    SDL_Log("Window %d maximized", event.window.windowID);
					    break;
					case SDL_WINDOWEVENT_RESTORED:
					    SDL_Log("Window %d restored", event.window.windowID);
					    break;
					case SDL_WINDOWEVENT_ENTER:
					    SDL_Log("Mouse entered window %d",
						    event.window.windowID);
					    break;
					case SDL_WINDOWEVENT_LEAVE:
					    SDL_Log("Mouse left window %d", event.window.windowID);
					    break;
					case SDL_WINDOWEVENT_FOCUS_GAINED:
					    SDL_Log("Window %d gained keyboard focus",
						    event.window.windowID);
					    break;
					case SDL_WINDOWEVENT_FOCUS_LOST:
					    SDL_Log("Window %d lost keyboard focus",
						    event.window.windowID);
					    break;
					case SDL_WINDOWEVENT_CLOSE:
					    SDL_Log("Window %d closed", event.window.windowID);
					    break;
				}
			if(event.type==SDL_APP_TERMINATING)
				SDL_Log("SDL Terminated");
			if(event.type==SDL_QUIT){
				SDL_Log("SDL Quit");
				isquit=true;
			}
		}	
	}
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(render);	
	SDL_Quit();
}
