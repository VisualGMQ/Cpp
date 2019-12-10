#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
using namespace std;

int main(int argc, char** argv){
    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_EVENTS);
    IMG_Init(IMG_INIT_PNG);
    SDL_Window* window = nullptr;
    SDL_Renderer* render = nullptr;
    SDL_CreateWindowAndRenderer(400, 400, SDL_WINDOW_SHOWN, &window, &render);
    SDL_Event event;
    SDL_Surface* surface = IMG_Load("image.png");
    //下面两行相当于使用SDL_CreateTextureFromSurface()
    SDL_Texture* texture = SDL_CreateTexture(render, surface->format->format, SDL_TEXTUREACCESS_TARGET|SDL_TEXTUREACCESS_STATIC, surface->w, surface->h);
    SDL_UpdateTexture(texture, nullptr, surface->pixels, surface->pitch);
    SDL_FreeSurface(surface);
    //SDL_SetTextureColorMod(texture, 255, 0, 0);

    bool isquit = false;
    while(!isquit){
        SDL_RenderClear(render);
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT)
                isquit = true;
        }
        SDL_RenderCopy(render, texture, nullptr, nullptr);
        SDL_Delay(30);
        SDL_RenderPresent(render);
    }
    SDL_DestroyTexture(texture);
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(render);
    IMG_Quit();
    SDL_Quit();
    return 0;
}