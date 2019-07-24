#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
using namespace std;
SDL_TimerID tid;

Uint32 TimerCallback(Uint32 interval, void* param){
    SDL_ShowWindow((SDL_Window*)param);
    SDL_RemoveTimer(tid);
    return interval;
}

void showMessageBox(){
    SDL_MessageBoxButtonData msgbuttons[] = {
        {0, 1, "button1"},
        {SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, 2, "button return default"},
        {SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT, 3, "button escape default"}
    };

    //don't influent MacOS
    SDL_MessageBoxColorScheme colorscheme = {
        {
            {255, 0, 0},
            {0, 0, 255},
            {0, 0, 0},
            {0, 255, 0},
            {255, 255, 0}
        }
    };

    SDL_MessageBoxData msgdata = {
        SDL_MESSAGEBOX_INFORMATION,
        nullptr,
        "customer designed box",
        "this is a user define messagebox",
        3,
        msgbuttons,
        &colorscheme
    };

    int buttonid;
    if(SDL_ShowMessageBox(&msgdata, &buttonid) < 0){
        SDL_LogError(SDL_LOG_CATEGORY_VIDEO, "messagebox failed");
    }
}

int main(int argc, char** argv){
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_JPG);
    SDL_Window* window = SDL_CreateWindow("window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 500, SDL_WINDOW_RESIZABLE);
    SDL_Renderer* render = SDL_CreateRenderer(window, -1, 0);
    SDL_Event event;
    bool isquit = false;

    //use this function to limite mouse in window
    //SDL_SetWindowGrab(window, SDL_TRUE);

    //set window opacity and no border
    SDL_SetWindowOpacity(window, 0.5);
    SDL_SetWindowBordered(window, SDL_FALSE);
    //SDL_RaiseWindow(window); //let window in front of all windows

    SDL_Surface* icon = SDL_LoadBMP("./icon.bmp");
    //use this function to set window icon
    SDL_SetWindowIcon(window, icon);
    SDL_FreeSurface(icon);

    SDL_Surface* surface = IMG_Load("./JOJO.jpg");
    SDL_Texture* texture = SDL_CreateTextureFromSurface(render, surface);
    SDL_FreeSurface(surface);

    //use this function to show user define messagebox
    showMessageBox();

    //use this function to show a single button message box
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_WARNING, "warning box", "this is a warning", nullptr);

    SDL_EventState(SDL_DROPFILE, SDL_DISABLE);

    while(!isquit){
        SDL_SetRenderDrawColor(render, 200, 200, 200, 255);
        SDL_RenderClear(render);
        while(SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_QUIT:
                    isquit = true;
                    break;
                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym){
                        case SDLK_ESCAPE:
                            isquit = true;
                            break;
                        case SDLK_h:
                            //use this function to get the state of window
                            if(SDL_GetWindowFlags(window)|SDL_WINDOW_SHOWN){
                                SDL_HideWindow(window); //hide window
                                tid = SDL_AddTimer(2000, TimerCallback, window);
                            }
                            break;
                        case SDLK_m:
                            SDL_MaximizeWindow(window); //maxmize window
                            SDL_RestoreWindow(window);
                            break;
                        case SDLK_n:
                            SDL_MinimizeWindow(window); //minmize window
                            break;
                        case SDLK_f:
                            SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP); //fullscreen ,full of all desktop screen and scale
                            break;
                    }
                    break;
                case SDL_WINDOWEVENT:
                    switch(event.window.event){
                        case SDL_WINDOWEVENT_RESIZED:
                            SDL_RenderSetScale(render, event.window.data1/800.0f, event.window.data2/500.0f);
                            break;
                    }
                    break;
                case SDL_MOUSEMOTION:
                    if(SDL_GetMouseState(nullptr, nullptr) == SDL_BUTTON(1)){
                        int x, y;
                        SDL_GetWindowPosition(window, &x, &y);
                        x += event.motion.xrel;
                        y += event.motion.yrel;
                        SDL_SetWindowPosition(window, x, y);
                    }
                    break;
                case SDL_DROPFILE:
                    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "drop file", event.drop.file, nullptr);
                    SDL_free(event.drop.file);
                    break;
                case SDL_DROPTEXT:
                    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "drop text", event.drop.file, nullptr);
                    SDL_free(event.drop.file);
                    break;
            }
        }

        SDL_RenderCopy(render, texture, nullptr, nullptr);
        SDL_RenderPresent(render);
        SDL_Delay(60);
    }

    SDL_DestroyTexture(texture);
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(render);
    IMG_Quit();
    SDL_Quit();
    return 0;
}