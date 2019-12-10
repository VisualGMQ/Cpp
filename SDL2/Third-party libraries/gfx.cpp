#include "SDL.h"
#include "SDL2_gfxPrimitives.h"
#include "SDL2_framerate.h"

int main(int argc, char** arhv){
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* window = SDL_CreateWindow("SDL2_gfx", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, SDL_WINDOW_SHOWN);
    SDL_Renderer* render = SDL_CreateRenderer(window, -1, 0);
    SDL_Event event;
    bool isquit = false;
    FPSmanager fpsmanager;
    SDL_initFramerate(&fpsmanager);     //初始化帧率管理器结构体
    SDL_setFramerate(&fpsmanager, 60);  //设置帧率为60（默认为30）
    int x = 0;
    int y = 0;
    while(!isquit){
        SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
        SDL_RenderClear(render);
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT)
                isquit = true;
        }
        if(hlineRGBA(render, 0, 800, 100, 255, 255, 255, 255) == -1){
            SDL_Log("draw line failed");
        }
        stringRGBA(render, 400, 400, "I am VisualGMQ", 0, 255, 0, 255);
        x+=2;
        rectangleRGBA(render, x, y, x+100, y+100, 255, 0, 0, 255);
        SDL_RenderPresent(render);
        SDL_framerateDelay(&fpsmanager);
        //SDL_Delay(60);
    }
    SDL_Quit();
    return 0;
}