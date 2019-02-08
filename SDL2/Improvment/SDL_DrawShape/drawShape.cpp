#include <iostream>
#include <cmath>
#include <SDL2/SDL.h>
using namespace std;
SDL_Window* window = nullptr;
SDL_Renderer* render = nullptr;
SDL_Event event;
SDL_Rect rect={100,100,100,100};
bool isquit=false;

void SDL_RenderDrawCircle(SDL_Renderer* render,int x,int y,int radius){
	const double PI=3.1415926;
	const double EOP = 250;
	double exp = 2*PI/EOP;
	SDL_Point point={x,y},oldpoint={point.x+radius,point.y},newpoint;
	for(int i=0;i<=EOP;i++){
		newpoint.x = point.x + radius*cos(exp*i);
		newpoint.y = point.y + radius*sin(exp*i);
		SDL_RenderDrawLine(render,oldpoint.x,oldpoint.y,newpoint.x,newpoint.y);
		oldpoint=newpoint;
	}
}

int main(int argc,char** argv){
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_CreateWindowAndRenderer(500,500,SDL_WINDOW_SHOWN,&window,&render);
	while(!isquit){
		SDL_RenderClear(render);
		SDL_SetRenderDrawColor(render,0,0,0,255);
		SDL_RenderDrawLine(render,0,0,400,400);
		SDL_RenderDrawRect(render,&rect);
		SDL_RenderDrawCircle(render,200,200,10);
		while(SDL_PollEvent(&event)){
			if(event.type==SDL_QUIT)
				isquit=true;
		}
		SDL_SetRenderDrawColor(render,255,255,255,255);
		SDL_RenderPresent(render);
	}
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(render);
	SDL_Quit();
	return 0;
}
