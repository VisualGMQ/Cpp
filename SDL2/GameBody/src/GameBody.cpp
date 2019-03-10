#include "GameBody.hpp"
using namespace std;

GameBody::GameBody(const string title,int width,int height,Uint32 flag,int delaytime):error(false),gamequit(false),delaytime(delaytime),render(nullptr){
    win = new gbWindow(title,width,height,flag);
    this->render = SDL_CreateRenderer(win->get(),-1,0);
    if(this->render == nullptr)
		error=true;
	else
		globaleRenderer = render;
}

void GameBody::eventHandle(){
	while(SDL_PollEvent(&event)){
		if(event.type==SDL_QUIT){
			gamequit=true;
			SDL_Quit();
		}
	}
}

void GameBody::renderBegin(){
	SDL_SetRenderDrawColor(render,255,255,255,255);
	SDL_RenderClear(render);	
}

void GameBody::renderEnd(){
	SDL_RenderPresent(render);
}

void GameBody::delay(int millisec){
	SDL_Delay(millisec);
}

void GameBody::step(){
	renderBegin();
	eventHandle();
	gbInput::step();
	update();
	renderEnd();
	delay(delaytime);
}

GameBody::~GameBody(){
	clean();
	SDL_DestroyRenderer(render);
    if(win != nullptr)
        delete win;
    win = nullptr;
    render = nullptr;
	globaleRenderer = nullptr;
}
