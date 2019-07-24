#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
using namespace std;

void drawShapes(SDL_Texture* texture, SDL_Renderer* render){
    SDL_SetRenderTarget(render, texture);
    SDL_SetRenderDrawColor(render, 0, 255, 0, 255);
    SDL_Rect rect;
    rect.x = 0;
    rect.y = 0;
    rect.w = 100;
    rect.h = 100;
    SDL_RenderFillRect(render, &rect);
    SDL_SetRenderDrawColor(render, 255, 255, 255, 255);
    rect.w=100;
    rect.h=100;
    SDL_RenderDrawRect(render, &rect);
    SDL_SetRenderDrawColor(render, 0, 0, 255, 100);
    SDL_RenderDrawLine(render, 0, 0, 100, 100);
    SDL_SetRenderTarget(render, nullptr);
}

void updateTexture(SDL_Texture* texture){
    void* pixels;
    int pitch;
    int w, h;
    SDL_QueryTexture(texture, nullptr, nullptr, &w, &h);
    SDL_LockTexture(texture, nullptr, &pixels, &pitch);
    SDL_PixelFormat* format = SDL_AllocFormat(SDL_PIXELFORMAT_RGBA8888);
    Uint32 color = SDL_MapRGBA(format, 255, 0, 0, 255);
    cout<<hex<<color<<endl;
    cout<<"pitch:"<<pitch<<endl;
    for(int i=0;i<pitch*h;i++)
        ((unsigned char*)pixels)[i] = 255;
    SDL_FreeFormat(format);
    SDL_UnlockTexture(texture);
}

SDL_Rect getRect(SDL_Texture* texture){
    int w, h;
    SDL_QueryTexture(texture, nullptr, nullptr, &w, &h);
    SDL_Rect rect;
    rect.x = 0;
    rect.y = 0;
    rect.w = w;
    rect.h = h;
    return rect;
}

int main(int argc,char** argv){
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_JPG|IMG_INIT_PNG);
    SDL_Window* window = SDL_CreateWindow("texture", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, SDL_WINDOW_RESIZABLE);
    SDL_Renderer* render = SDL_CreateRenderer(window, -1, 0);
    SDL_Event event;
    bool isquit = false;

    SDL_Texture* texture = SDL_CreateTexture(render, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 100, 100);
    SDL_SetRenderDrawBlendMode(render, SDL_BLENDMODE_BLEND);
    SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
    drawShapes(texture, render);
    SDL_Rect rect1 = getRect(texture);

    //use this function to set window opacity ,value in [0, 1];
    SDL_SetWindowOpacity(window, 0.5);

    Uint8 alphamod;
    //SDL_GetTextureAlphaMod(texture, &alphamod);
    cout<<"alphamode:"<<alphamod<<endl;
    Uint8 r, g, b;
    SDL_GetTextureColorMod(texture, &r, &g, &b);
    cout<<"r:"<<r<<" g:"<<g<<" b:"<<b<<endl;

    //updateTexture(texture); //have bug
    //use this function to set all 'R' value to 0
    SDL_SetTextureColorMod(texture, 0, g, b);

    int alpha = 255;

    while(!isquit){
        SDL_SetRenderDrawColor(render, 100, 100, 100, 255);
        SDL_RenderClear(render);
        //use this function to let window front of all window
        SDL_RaiseWindow(window);
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT)
                isquit = true;
            if(event.type == SDL_WINDOWEVENT)
                if(event.window.event == SDL_WINDOWEVENT_RESIZED){
                    //use this function to fit image to screen
                    SDL_RenderSetScale(render, event.window.data1/500.0f, event.window.data2/500.0f);
                }
        }

        alpha -= 5;
        if(alpha < 0 )
            alpha = 255;

        //SDL_SetTextureAlphaMod(texture, alpha);
        SDL_RenderCopy(render, texture, nullptr, &rect1);
        SDL_RenderPresent(render);
        SDL_Delay(30);
    }
    IMG_Quit();
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(render);
    SDL_Quit();
    return 0;
}