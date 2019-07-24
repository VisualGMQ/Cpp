#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "SDL_Cache/SDL_FontCache.h"
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char** argv){
    SDL_Init(SDL_INIT_EVERYTHING);
    
    /*
    TTF_Init();
    TTF_Font* font = TTF_OpenFont("font.ttc", 24);
    if(font == nullptr){
        cout<<"can't find font";
        return -1;
    }
    */
    SDL_Window* window = SDL_CreateWindow("input text", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 100 ,0);
    SDL_Renderer* render = SDL_CreateRenderer(window, -1, 0);
    FC_Font* font = FC_CreateFont();
    FC_LoadFont(font, render, "font.ttc", 24, FC_MakeColor(0, 0, 0, 255), TTF_STYLE_OUTLINE);
    SDL_Event event;
    bool isquit = false;
    SDL_StartTextInput();
    string textinput = "";
    SDL_Rect rect;
    rect.x = 0;
    rect.y = 300;
    rect.w=100;
    rect.h=100;
    SDL_SetTextInputRect(&rect);
    while(!isquit){
        SDL_SetRenderDrawColor(render, 255, 255 ,255, 255);
        SDL_RenderClear(render);
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT)
                isquit = true;
            if(event.type == SDL_KEYDOWN){
                if(event.key.keysym.sym == SDLK_ESCAPE)
                    isquit = true;
                if(event.key.keysym.sym == SDLK_BACKSPACE)
                    textinput.pop_back();
                if(event.key.keysym.sym == SDLK_RETURN)
                    textinput += '\n';
            }
            if(event.type == SDL_TEXTINPUT){
                textinput += event.text.text;
            }
            if(event.type == SDL_TEXTEDITING){
                cout<<"text:"<<event.edit.text<<endl;
                cout<<"start:"<<event.edit.start<<endl;
                cout<<"length:"<<event.edit.length<<endl;
            }
        }
        /*
        SDL_Surface* surface = TTF_RenderUTF8_Blended(font, textinput.c_str(), color);
        if(surface != nullptr){
            SDL_Texture* texture = SDL_CreateTextureFromSurface(render, surface);
            SDL_Rect dstrect;
            dstrect.x = 0;
            dstrect.y = 0;
            dstrect.w = surface->w;
            dstrect.h = surface->h;
            SDL_RenderCopy(render, texture, nullptr, &dstrect);
            SDL_DestroyTexture(texture);
            SDL_FreeSurface(surface);
        }
        */
        FC_Draw(font, render, 0, 20, textinput.c_str());

        SDL_RenderPresent(render);
        SDL_Delay(30);
    }
    /*
    TTF_CloseFont(font);
    TTF_Quit();
    */
    FC_FreeFont(font);
    SDL_StopTextInput();
    //cout<<"you inputed "<<textinput<<endl;
    SDL_Quit();
    return 0;
}