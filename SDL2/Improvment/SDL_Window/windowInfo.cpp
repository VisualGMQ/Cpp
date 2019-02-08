#include <iostream>
#include <SDL2/SDL.h>
using namespace std;

int main(int argc,char** argv){
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("window",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,300,300,SDL_WINDOW_RESIZABLE);
	cout<<"is window grabed input focus?"<<SDL_GetWindowGrab(window)<<endl;
	float opacity;
	SDL_GetWindowOpacity(window,&opacity);
	cout<<"the window opacity is:"<<opacity<<endl;
	cout<<"this window ID is:"<<SDL_GetWindowID(window)<<endl;
	int width,height;
	SDL_GetWindowSize(window,&width,&height);
	cout<<"window size:"<<width<<","<<height<<endl;
	cout<<"widow flag:"<<SDL_GetWindowFlags(window)<<endl;
	cout<<"window title:"<<SDL_GetWindowTitle(window)<<endl;
	int x,y;
	SDL_GetWindowPosition(window,&x,&y);
	cout<<"the window position:"<<x<<","<<y<<endl;
	cout<<"window brightness:"<<SDL_GetWindowBrightness(window)<<endl;	
	SDL_DestroyWindow(window);
	return 0;
}
