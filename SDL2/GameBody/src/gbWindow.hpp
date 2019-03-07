#ifndef __GBWINDOW_HPP__
#define __GBWINDOW_HPP__
#include <SDL2/SDL.h>
#include "header.hpp"

/**
 * @class gbWindow
 * @brief 封装SDL_Window的类
 *
 * 这个类封装了SDL_Window
 */
class gbWindow{
public:
	gbWindow(SDL_Window*);
	gbWindow(string title,int width,int height,Uint8 type);
	SDL_Window* get();
	gbSize getSize();
	bool isFocus();
	const string getTitle();
	gbPoint getPosition();
	float getBrightness();
	float getOpacity();
	Uint8 getFlag();
	void setTitle(string);
	void setOpacity(float);
	void setBrightness(float);
	~gbWindow();
private:
	SDL_Window* window;
};

#endif
