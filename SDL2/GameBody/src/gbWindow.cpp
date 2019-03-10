#include "gbWindow.hpp"
#include <cstdlib>
using namespace std;

gbWindow::gbWindow(SDL_Window* window){
	if(window == nullptr)
		abort();
	this->window = window;
}

gbWindow::gbWindow(const string title,int width,int height,Uint32 flag,string iconpath){
	this->window = SDL_CreateWindow(title.c_str(),SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,width,height,flag);
	WindowMode = flag;
	if(window == nullptr)
		abort();
	loadIcon(iconpath);
}

bool gbWindow::loadIcon(string path){
    if(path == "")
        return false;
    icon = IMG_Load(path.c_str());
    if(window!=nullptr){
        SDL_SetWindowIcon(window,icon);
        return true;
    }
    SDL_Log("window is nullptr");
    return false;
}

gbSize gbWindow::getSize(){
	int w,h;
	SDL_GetWindowSize(window,&w,&h);
	return gbSize(w,h);
}

bool gbWindow::isFocus(){
	return SDL_GetWindowGrab(window);
}

const string gbWindow::getTitle(){
	return string(SDL_GetWindowTitle(window));
}

gbPoint gbWindow::getPosition(){
	int x,y;
	SDL_GetWindowPosition(window,&x,&y);
	return gbPoint(x,y);
}

Uint32 gbWindow::getMode(){
	return WindowMode;
}

void gbWindow::setTitle(string title){
	SDL_SetWindowTitle(window,title.c_str());
}

float gbWindow::getBrightness(){
	float brightness = SDL_GetWindowBrightness(window);
	return brightness;
}

void gbWindow::setBrightness(float b){
	SDL_SetWindowBrightness(window,b);
}

void gbWindow::setIcon(string path){
	SDL_Surface* surface  = nullptr;
	if(icon != nullptr)
		surface = icon;
	if(loadIcon(path)){
		if(surface != nullptr)
			SDL_FreeSurface(surface);
	}else
		icon = surface;
}

void gbWindow::setMode(MODE mode,bool enable){
	SDL_bool sdlbool;
	if(enable)
		sdlbool = SDL_TRUE;
	else
		sdlbool = SDL_FALSE;
	switch(mode){
		case MODE::WINDOW_BORDERED:
			SDL_SetWindowBordered(window,sdlbool);
			break;
		case MODE::WINDOW_FULLSCREEN:
			SDL_SetWindowFullscreen(window,SDL_WINDOW_FULLSCREEN);
			break;
	}
}

gbWindow::~gbWindow(){
    if(window!=nullptr){
        SDL_DestroyWindow(window);
        window = nullptr;
    }
}
