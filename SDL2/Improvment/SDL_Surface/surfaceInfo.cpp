#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "PixelFormat2String.hpp"

int main(int argc, char** argv){
   SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_JPG|IMG_INIT_PNG|IMG_INIT_TIF|IMG_INIT_WEBP);
    for(int i=1;i<argc;i++){
        cout<<argv[i]<<endl;
        SDL_Surface* surface = IMG_Load(argv[i]);
        if(!surface){
            return -1;
        }
        outputSurfaceInfo(surface);
        SDL_FreeSurface(surface);
    }
    IMG_Quit();
    SDL_Quit();
}