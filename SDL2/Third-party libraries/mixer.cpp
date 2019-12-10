#include "SDL.h"
#include "SDL_mixer.h"

int main(int argc, char** argv){
    SDL_Init(SDL_INIT_AUDIO|SDL_INIT_TIMER);
    Mix_Init(MIX_INIT_MID|MIX_INIT_MP3|MIX_INIT_OGG);
    
    Mix_Quit();
    SDL_Quit();
    return 0;
}