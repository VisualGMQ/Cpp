#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "PixelFormat2String.hpp"
using namespace std;

int main(int argc,char** argv){
	cout<<"对于Surface,虽然对其的绘制函数基本上都不使用了，但是surface仍然可以做到一些texture做不到的东西（比如透明色），所以研究surface还是很有价值的"<<endl;
	cout<<"原生的SDL2采用SDL_LoadBMP()来载入图片，但是只能够载入bmp文件。这里使用SDL2_image库来获得各种格式的图片"<<endl;
	cout<<"这里我们采用将surface转化为texture的方法来绘制到窗口上"<<endl;
	SDL_Window* window;
	window = SDL_CreateWindow("surface window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 400, 400, SDL_WINDOW_SHOWN);
	SDL_Event event;
	bool isquit = false;
	SDL_Surface* win_surface = SDL_GetWindowSurface(window);
	SDL_Surface* image = SDL_LoadBMP("./1.bmp");	//一般会使用拓展库IMG_Load()函数来加载
	SDL_SetSurfaceRLE(image, 1);	//通过这个函数来开启游程编码
	if(image==nullptr)
		cerr<<"there is no image"<<endl;
	outputSurfaceInfo(image);
	while(!isquit){
		SDL_FillRect(win_surface, nullptr, 0x00FF00);	//在Surface时需要使用这个函数来清屏（其实就是绘制实心矩形）
		while(SDL_PollEvent(&event)){
			if(event.type == SDL_QUIT)
				isquit=true;	
		}
		SDL_Rect img_rect = {
			/*x*/
			100, 
			/*y*/
			0, 
			/*w*/
			image->w,
			/*h*/
			image->h
		};
		SDL_BlitSurface(image, nullptr, win_surface, &img_rect);	//使用这个函数来绘制Surface
		SDL_UpdateWindowSurface(window);	//在Surface时需要使用这个函数来更新窗体
		SDL_Delay(100);
	}
	SDL_FreeSurface(image);
	SDL_Quit();
	return 0;
}