#ifndef _XCODE_PROJECT_
#define _XCODE_PROJECT_
#endif

#ifdef _XCODE_PROJECT_
#include <SDL2_image/SDL_image.h>
#else
#include <SDL2/SDL_image.h>
#endif
#include "GameBody.hpp"
#include <SDL2/SDL.h>
#include <string>
#include <iostream>
using namespace std;

bool GameBody::isSDL_Init = false;

GameBody::GameBody(const string title,int width,int height,Uint32 flag,int delaytime):error(false),gamequit(false),delaytime(delaytime){
	if(GameBody::isSDL_Init == false)
		if(SDL_Init(SDL_INIT_EVERYTHING)==0)
			GameBody::isSDL_Init=true;
	if((win = SDL_CreateWindow(title.c_str(),SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,width,height,flag))==nullptr){
		error=true;	
	}else
		if((render = SDL_CreateRenderer(win,-1,0))==nullptr)
			error=true;
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
	update();
	renderEnd();
	delay(delaytime);
}

GameBody::~GameBody(){
	clean();
	SDL_DestroyWindow(win);
	if(GameBody::isSDL_Init == true){
		SDL_Quit();	
		GameBody::isSDL_Init=false;
	}
}
