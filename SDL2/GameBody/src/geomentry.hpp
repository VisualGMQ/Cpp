#ifndef __GEOMENTRY_HPP__
#define __GEOMENTRY_HPP__
/**
 * @file geomentry.hpp
 * @author VisualGMQ
 * @brief 一些小的几何类
 *
 * 这里面有一些类来表示几何概念，比如大小，点和矩形
 */
#include <SDL2/SDL.h>
#include "header.hpp"

/**
 * @class gbRect
 * @brief 矩形类
 */
class gbRect{
public:
	gbRect(int x,int y,int w,int h);
	bool operator==(gbRect) const;
	bool operator!=(gbRect) const;
	GB_GET_BASIC_SOURCE(SDL_Rect&,rect)
	GB_CREATE_GETSETFUNC(int,X,rect.x)
	GB_CREATE_GETSETFUNC(int,Y,rect.y)
	GB_CREATE_GETSETFUNC(int,Width,rect.w)
	GB_CREATE_GETSETFUNC(int,Height,rect.h)
private:
	SDL_Rect rect;
};

/**
 * @class gbPoint
 * @brief 点类
 */
class gbPoint{
public:
	gbPoint(int x,int y);
	bool operator==(gbPoint) const;
	bool operator!=(gbPoint) const;
	GB_GET_BASIC_SOURCE(SDL_Point&,point)
	GB_CREATE_GETSETFUNC(int,X,point.x)
	GB_CREATE_GETSETFUNC(int,Y,point.y)
private:
	SDL_Point point;
};

/**
 * @class gbSize
 * @brief 大小类
 *
 * 这个类的定义其实和gbPoint类是一模一样的，只不过将x,y变成了w,h
 */
class gbSize{
public:
	gbSize(int w,int h);
	bool operator==(gbSize) const;
	bool operator!=(gbSize) const;
	GB_GET_BASIC_SOURCE(SDL_Point&,size)
	GB_CREATE_GETSETFUNC(int,Width,size.x);
	GB_CREATE_GETSETFUNC(int,Height,size.y);
private:
	SDL_Point size;
};
#endif
