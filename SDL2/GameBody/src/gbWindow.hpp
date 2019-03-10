#ifndef __GBWINDOW_HPP__
#define __GBWINDOW_HPP__
/** @file gbWindow.hpp
 * @author VisualGMQ
 * @brief 一个封装了窗口的类
 */
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "geomentry.hpp"
#include "header.hpp"
using namespace std;

/**
 * @class gbWindow
 * @brief 封装SDL_Window的类
 *
 * 这个类封装了SDL_Window
 */
class gbWindow{
public:
	enum MODE{
		WINDOW_BORDERED,
		WINDOW_RESIZABLE,
		WINDOW_FULLSCREEN,
	};
	gbWindow(SDL_Window*);
	gbWindow(string title,int width,int height,Uint32 type,string iconpath = "");
	gbSize getSize();
	bool isFocus();
	const string getTitle();
	gbPoint getPosition();
	float getBrightness();
	Uint32 getMode();
	void setTitle(string);
	void setBrightness(float);
	void setIcon(string path);
	void setMode(MODE,bool);
	GB_GET_BASIC_SOURCE(SDL_Window*,window);
	~gbWindow();
private:
	bool loadIcon(string path);
	Uint32 WindowMode;
	SDL_Surface* icon;
	SDL_Window* window;
};

#endif
