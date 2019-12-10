#include "SDL.h"
#include "SDL_image.h"

int main(int argc, char** argv){
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_JPG|IMG_INIT_PNG);
    const SDL_version* version = IMG_Linked_Version();
    SDL_Log("your SDL2_image lib version is:%d.%d.%d", version->major, version->minor, version->patch);
    IMG_Quit();
    SDL_Quit();
}