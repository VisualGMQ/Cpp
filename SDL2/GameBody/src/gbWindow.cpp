#include "gbWindow.hpp"
#include <cstdlib>
using namespace std;

gbWindow::gbWindow(SDL_Window* window){
	if(window == nullptr)
		abort();
	this->window = window;
}

gbWindow::gbWindow(string title,int width,int height,Uint8 flag){
	window = SDL_CreateWindow(title.c_str(),SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,width,height,flag);
	if(window == nullptr)
		abort();
}

SDL_Window* get(){
	return window;
}

gbWindow::~gbWindow(){
	SDL_DestroyWindow(window);
}
