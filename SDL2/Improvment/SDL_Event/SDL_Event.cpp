#include <SDL2/SDL.h>
#include <iostream>
using namespace std;

int eventFilter(void* userdata, SDL_Event* event){
    SDL_Rect* rect = (SDL_Rect*)userdata;
    if(event->type == SDL_MOUSEBUTTONDOWN){
        SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "mouse down");
        if(event->button.button == SDL_BUTTON_LEFT)
            rect->x += 5;
    }
    if(event->type == SDL_MOUSEBUTTONUP){
        SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "mouse up");
    }
    return -1;
}

Uint32 eventTimer(Uint32 interval, void* param){
    SDL_Event event;
    event.type = SDL_MOUSEBUTTONDOWN;
    event.button.button = SDL_BUTTON_LEFT;
    event.button.clicks = 1;
    event.button.type = SDL_MOUSEBUTTONDOWN;
    SDL_PushEvent(&event);
    return interval;
}

int main(int argc, char** argv){
    SDL_Init(SDL_INIT_EVENTS);
    SDL_Window* window = SDL_CreateWindow("event", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, SDL_WINDOW_SHOWN);
    SDL_Renderer* render = SDL_CreateRenderer(window, -1, 0);
    SDL_Event event;
    bool isquit = false;

    SDL_Rect rect;
    rect.x = 0;
    rect.y = 0;
    rect.w = 50;
    rect.h = 50;

    //set event listner to handle event
    SDL_SetEventFilter(eventFilter, &rect);

    //use this function to ignore some event
    SDL_EventState(SDL_MOUSEBUTTONUP, SDL_DISABLE);

    //use this timer to push event intervally
    SDL_TimerID tid = SDL_AddTimer(100, eventTimer, nullptr);

    while(!isquit){
        SDL_SetRenderDrawColor(render, 200, 200, 200, 255);
        SDL_RenderClear(render);
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT)
                isquit = true;
        }
        SDL_SetRenderDrawColor(render, 0, 255, 0, 255);
        SDL_RenderDrawRect(render, &rect);
        SDL_RenderPresent(render);
        SDL_Delay(60);
    }
    SDL_RemoveTimer(tid);
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(render);
    SDL_Quit();
    return 0;
}