#ifndef _GAMEBODY_HPP_
#define _GAMEBODY_HPP_

#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
using namespace std;

class GameBody{
public:
	static bool isSDL_Init;
	GameBody(const string,int width,int height,Uint32,int delaytime);
	virtual void eventHandle();
	virtual void renderBegin();
	virtual void update(){};
	virtual void step();
	virtual void renderEnd();
	virtual void delay(int millisec);
	bool isQuit(){return gamequit;};
	virtual void clean(){};
	virtual ~GameBody();
protected:
	SDL_Window* win;
	SDL_Renderer* render;
	SDL_Event event;
	bool error;
	bool gamequit;
	int width;
	int height;
	int delaytime;
};

#endif
