#ifndef __DRAW_TOOL__
#define __DRAW_TOOL__
#include <SDL2/SDL.h>
#include <string>
#include <cstdlib>
#include "header.hpp"
using namespace std;

class gbDrawTool{
public:
	gbDrawTool() = delete;
	gbDrawTool(SDL_Renderer*);
	void drawText(SDL_Texture*,string text,int x,int y,int ptsize,gbColor);
	void drawText(SDL_Texture*,string text,gbPoint point,ptsize,gbColor);
	void drawLine(SDL_Texture*,int x1,int x2,int y1,int y2,gbColor);
	void drawLine(SDL_Texture*,gbPoint p1,gbPoint p2,gbColor);
	void drawCircle(SDL_Texture*,int centerx,int centery,int radius,gbColor);
	void drawCircle(SDL_Texture*,gbPoint center,int radius,gbColor);
	void drawRect(SDL_Texture*,int x,int y,int w,int h,gbColor);
	void drawRect(SDL_Texture*,gbRect,gbColor);
	void drawRect(SDL_Texture*,gbPoint lt,gbSize size,gbColor);
	void fillRect(SDL_Texture*,int x,int y,int w,int h,gbColor);
	void fillRect(SDL_Texture*,gbRect,gbColor);
	void fillRect(SDL_Texture*,gbPoint p,gbSize size,gbColor);
	void drawSolidRect(SDL_Texture*,int x,int y,int w,int h,gbColor outline,gbColor fillColor);
private:
	gbColor startDraw(SDL_Texture* dst,gbColor color);
	void endDraw();
	SDL_Renderer* render;
};
#endif
