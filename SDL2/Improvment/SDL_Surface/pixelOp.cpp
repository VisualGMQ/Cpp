#include <SDL2/SDL.h>
#include <iostream>
#include "PixelFormat2String.hpp"
using namespace std;

int main(int argc, char** argv){
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Surface* img = SDL_LoadBMP("./1.bmp");
    if(!img || img->format->BitsPerPixel!=8){
        cerr<<"load 8 bits image failed"<<endl;
        return -1;
    }

    SDL_Surface* surface = SDL_CreateRGBSurface(img->format->format, img->w, img->h, 8, 0, 0, 0, 0);
    if(!surface){
        cerr<<"create surface failed"<<endl;
        return -1;
    }

    outputSurfaceInfo(surface);
    SDL_SetSurfacePalette(surface, img->format->palette);

    for(int i=0;i<img->w;i++){
        for(int j=0;j<img->h;j++){
            Uint8 index = *((Uint8*)img->pixels + j*img->pitch + i);
            if(i!=j)
                *((Uint8*)surface->pixels + j*surface->pitch + i) = index;
            else
                *((Uint8*)surface->pixels + j*surface->pitch +i) = 20;            
        }
    }

    SDL_SaveBMP(surface, "result.bmp");

    SDL_FreeSurface(img);
    SDL_FreeSurface(surface);
    SDL_Quit();
    return 0;
}