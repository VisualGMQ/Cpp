#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
using namespace std;
const int WIDTH=700;
const int HEIGHT=700;
const int DELAYTIME=30;
SDL_Window* mainwindow = nullptr;
SDL_Renderer* render = nullptr;
SDL_Surface* surface = nullptr;
SDL_Texture* texture = nullptr;
SDL_Event event;
SDL_Rect imgRect,destRect;
bool isquit=false;

bool init();
void renderScreen();
void handleEvent();
void update();
void clean();

int main(int argc,char** argv){
	if(init()==false){
		SDL_Log("Init faliled");
		return -1;
	}else
		SDL_Log("Init success");
	while(isquit==false){
		renderScreen();
		update();
		SDL_Delay(DELAYTIME);
	}
	SDL_Log("Window is quit\n");
	clean();
	SDL_Log("SDL quit");
	return 0;
}

bool init(){	
	if(SDL_Init(SDL_INIT_EVERYTHING)<0){
		cerr<<"SDL2 can't be init!";
		return -1;
	}
	mainwindow=SDL_CreateWindow("hello world",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WIDTH,HEIGHT,SDL_WINDOW_RESIZABLE);
	if(mainwindow==nullptr){
		cerr<<"can't create window!";
		return -1;
	}
	render = SDL_CreateRenderer(mainwindow,-1,0);
	if(render == nullptr){
		cerr<<"can't create renderer!";
		return -1;
	}
	surface = IMG_Load("1.jpeg");
	if(surface==nullptr){
		cerr<<"1.jpeg is not found";
		SDL_Log("img is not loaded");
	}else{
		texture = SDL_CreateTextureFromSurface(render,surface);
		SDL_QueryTexture(texture,nullptr,nullptr,&imgRect.w,&imgRect.h);
		destRect=imgRect;
		imgRect.x=imgRect.y=0;
		SDL_Log("the image width and height is:%d,%d",imgRect.w,imgRect.h);
	}
	return 1;
}

void renderScreen(){
		SDL_RenderClear(render);
		SDL_SetRenderDrawColor(render,0,200,0,255);
}

void handleEvent(){
	while(SDL_PollEvent(&event)){
		if(event.type == SDL_QUIT)
			isquit=true;
	}	
}

void update(){
	handleEvent();
	destRect.x=destRect.y=100;
	SDL_RenderCopy(render,texture,&imgRect,&destRect);
	SDL_RenderPresent(render);
}

void clean(){
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
	SDL_DestroyWindow(mainwindow);
	SDL_Quit();
}
