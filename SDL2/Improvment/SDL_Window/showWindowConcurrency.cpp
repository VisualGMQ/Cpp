#include <SDL2/SDL.h>
#include <thread>
using namespace std;

int thread_func(int argc,char** argv){
	SDL_Window* window = SDL_CreateWindow("window1",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,500,500,SDL_WINDOW_RESIZABLE);
	SDL_Renderer* render = SDL_CreateRenderer(window,-1,0);
	SDL_Event event;
	bool isquit = false;
	while(!isquit){
		while(SDL_PollEvent(&event)){
			SDL_SetRenderDrawColor(render,255,255,255,255);
			SDL_RenderClear(render);
			if(event.type == SDL_QUIT)
				isquit = true;
			SDL_RenderPresent(render);
		}
	}
	return 0;	
}

int main(int argc,char** argv){
	thread t1(thread_func,argc,argv);
	thread t2(thread_func,argc,argv);
	t1.join();
	t2.join();
	SDL_Log("app finished");
	return 0;
}
