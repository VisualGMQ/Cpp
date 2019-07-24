#include <SDL2/SDL.h>

int main(){
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Log("this is a log %d", 10);

    SDL_LogSetPriority(SDL_LOG_CATEGORY_TEST, SDL_LOG_PRIORITY_DEBUG);

    SDL_LogCritical(SDL_LOG_CATEGORY_TEST, "this is critical");
    SDL_LogDebug(SDL_LOG_CATEGORY_TEST, "this is debug");
    SDL_LogError(SDL_LOG_CATEGORY_TEST, "this is error");
    SDL_LogInfo(SDL_LOG_CATEGORY_TEST, "this is info");
    SDL_LogVerbose(SDL_LOG_CATEGORY_TEST, "this is verbose");
    SDL_LogWarn(SDL_LOG_CATEGORY_TEST, "this is warn");
    SDL_Quit();
    return 0;
}