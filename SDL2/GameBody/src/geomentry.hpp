#ifndef __GEOMENTRY_HPP__
#define __GEOMENTRY_HPP__
#include <SDL2/SDL.h>
#include "header.hpp"

class gbRect{
public:
	gbRect();
	gbRect(int x,int y,int w,int h);
	SDL_Rect& get();
	GB_CREATE_GETSETFUNC(int,X,rect.x)
	GB_CREATE_GETSETFUNC(int,Y,rect.y)
	GB_CREATE_GETSETFUNC(int,Width,rect.w)
	GB_CREATE_GETSETFUNC(int,Height,rect.h)
private:
	SDL_Rect rect;
};

class gbPoint{
public:
	gbPoint();
	gbPoint(int x,int y);
	GB_CREATE_GETSETFUNC(int,X,point.x)
private:
	SDL_Point point;
};
#endif
