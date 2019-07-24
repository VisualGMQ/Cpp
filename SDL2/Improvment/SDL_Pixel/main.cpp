#include <SDL2/SDL.h>

int main(int argc, char** argv){
    SDL_Init(SDL_INIT_EVERYTHING);

    Uint32 color = 0xFFEE99AA;
    Uint8 r, g, b, a;
    SDL_PixelFormat format = {SDL_PIXELFORMAT_RGBA8888, nullptr, 32, 1, 0xFF, 0xFF, 0xFF, 0xFF};

    SDL_GetRGBA(color, &format, &r, &g, &b, &a);

    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "r:%d g:%d b:%d a:%d", r, g, b, a);

    SDL_Quit();
    return 0;
}