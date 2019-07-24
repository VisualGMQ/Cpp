#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <GL/gl.h>
#include <GL/glew.h>
#include <GL/glu.h>

int main(int argc, char** argv){
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* window = SDL_CreateWindow("SDL2 for opengl", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, SDL_WINDOW_RESIZABLE|SDL_WINDOW_OPENGL);
    SDL_Event event;
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}