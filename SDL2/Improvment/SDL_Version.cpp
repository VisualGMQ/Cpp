#include <SDL2/SDL.h>

int main(int argc, char** argv){
    SDL_version version;
    SDL_VERSION(&version);
    //SDL_versoin(version);
    SDL_Log("%d.%d.%d", version.major, version.minor, version.patch);
    return 0;
}
