#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "GameBody.hpp"
using namespace std;

class OwnBody:public GameBody{
public:
	OwnBody(const string title,int w,int h,int flag,int time):GameBody(title,w,h,flag,time){};
	void update(){
		SDL_SetRenderDrawColor(render,0,0,0,255);
		SDL_RenderDrawLine(render,0,0,width,height);
		SDL_Rect rect={100,100,100,100};
		SDL_RenderDrawRect(render,&rect);
		SDL_Rect fillrect={300,300,100,100};
		SDL_SetRenderDrawColor(render,0,0,255,255);
		SDL_RenderFillRect(render,&fillrect);	
	}
};

int main(int argc,char* args[]){
	OwnBody body("Draw Shapes",700,700,SDL_WINDOW_RESIZABLE,60);
	while(!body.isQuit())
		body.step();	
	return 0;
}
