#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
using namespace std;

int main(int argc,char** argv){
	cout<<"对于Surface,虽然对其的绘制函数基本上都不使用了，但是surface仍然可以做到一些texture做不到的东西（比如透明色），所以研究surface还是很有价值的"<<endl;
	cout<<"原生的SDL2采用SDL_LoadBMP()来载入图片，但是只能够载入bmp文件。这里使用SDL2_image库来获得各种格式的图片"<<endl;
	cout<<"SDL2开始废弃了一些SDL1的函数，这里我们采用将surface转化为texture的方法来绘制到窗口上"<<endl;
	SDL_Window* window;
	SDL_Renderer* render;
	SDL_CreateWindowAndRenderer(700,700,SDL_WINDOW_RESIZABLE,&window,&render);
	SDL_Surface* surface = SDL_LoadBMP("1.bmp");
	Uint32 color = SDL_MapRGB(surface->format, 0xff, 0xff, 0xff);
	SDL_SetColorKey(surface,SDL_TRUE,color);
	if(surface==nullptr)
		SDL_Log("can't load img");
	SDL_Event event;
	SDL_Rect rect1={0,0,surface->w,surface->h};
	SDL_Log("surface size:%d,%d",surface->w,surface->h);
	int isquit = false;
	while(!isquit){
		SDL_SetRenderDrawColor(render,0,0,0,255);
		SDL_RenderClear(render);
		SDL_Surface* windowsurface = SDL_GetWindowSurface(window);
		while(SDL_PollEvent(&event)){
			if(event.type == SDL_QUIT)
				isquit=true;	
		}
		SDL_Texture* tex = SDL_CreateTextureFromSurface(render,surface);
		SDL_RenderCopy(render,tex,nullptr,&rect1);
		SDL_RenderPresent(render);
		SDL_Delay(100);
	}
	SDL_FreeSurface(surface);
	return 0;
}
