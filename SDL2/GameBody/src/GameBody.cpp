#include "GameBody.hpp"
using namespace std;

GameBody::GameBody(const string title,int width,int height,Uint32 flag,int delaytime):error(false),gamequit(false),delaytime(delaytime),render(nullptr){
    win = new gbWindow(title,width,height,flag);
	render = win->getRender();
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
	SDL_SetRenderTarget(render,win->getCanva());
	SDL_SetRenderDrawColor(render,255,255,255,255);
	SDL_RenderClear(render);	
}

void GameBody::renderEnd(){
	SDL_SetRenderTarget(render,nullptr);
	SDL_RenderCopy(render,win->getCanva(),nullptr,nullptr);
	SDL_RenderPresent(render);
}

void GameBody::delay(int millisec){
	SDL_Delay(millisec);
}

void GameBody::step(){
	renderBegin();
	eventHandle();
	update();
	renderEnd();
	delay(delaytime);
}

GameBody::~GameBody(){
	clean();
    if(win != nullptr)
        delete win;
    win = nullptr;
    render = nullptr;
}
