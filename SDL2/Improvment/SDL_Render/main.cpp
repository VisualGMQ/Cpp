#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
using namespace std;

SDL_Window* window = nullptr;
SDL_Renderer* render = nullptr;
SDL_Event event;
bool isquit=false;

void PrintRenderInfo(SDL_Renderer* render){
	SDL_RendererInfo info;
	SDL_GetRendererInfo(render,&info);
	SDL_Log("render name:%s",info.name);
	SDL_Log("render flag:%u",info.flags);
	SDL_Log("max_texture_width:%d",info.max_texture_width);
	SDL_Log("min_texture_width:%d",info.max_texture_height);
	int x,y;
	SDL_GetRendererOutputSize(render,&x,&y);
	SDL_Log("render output size:%d,%d",x,y);
	SDL_Log("render target supported:%d",SDL_RenderTargetSupported(render));
}

int main(int argc,char** argv){
	if(SDL_Init(SDL_INIT_EVERYTHING)<0){
		SDL_Log("SDL Init Falled");
		return -1;
	}
	//window = SDL_CreateWindow("window",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,700,700,SDL_WINDOW_SHOWN);
	//render = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
	SDL_CreateWindowAndRenderer(700,700,SDL_WINDOW_SHOWN,&window,&render);
	PrintRenderInfo(render);
	SDL_Renderer* render2 = SDL_CreateRenderer(window,0,SDL_RENDERER_ACCELERATED);
	PrintRenderInfo(render2);
	SDL_Log("Number of Renderer Drivers:%d",SDL_GetNumRenderDrivers());
	SDL_SetRenderDrawColor(render,255,255,255,255);
	while(!isquit){
		SDL_RenderClear(render);

		while(SDL_PollEvent(&event)){
			if(event.type == SDL_QUIT){
				SDL_Log("App quited");
				isquit=true;
			}
		}
		SDL_RenderPresent(render);
	}	
	SDL_DestroyWindow(window);
	SDL_Quit();
}
