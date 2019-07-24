all:windowevent.cpp keyevent.cpp mouseevent.cpp textinput.cpp SDL_Event.cpp
	g++ windowevent.cpp -o windowevent `sdl2-config --libs --cflags` `pkg-config --libs SDL2_image` -std=c++11
	g++ keyevent.cpp -o keyevent `sdl2-config --libs --cflags` `pkg-config --libs SDL2_image` -std=c++11
	g++ mouseevent.cpp -o mouseevent `sdl2-config --libs --cflags` `pkg-config --libs SDL2_image` -std=c++11
	gcc ./SDL_Cache/SDL_FontCache.c -c `sdl2-config --libs --cflags` `pkg-config --libs --cflags SDL2_ttf`
	g++ textinput.cpp  SDL_FontCache.o -o textinput `sdl2-config --libs --cflags` `pkg-config --libs --cflags SDL2_ttf` -std=c++11
	g++ SDL_Event.cpp -o event `sdl2-config --libs --cflags` -std=c++11
	-rm SDL_FontCache.o
.PHONY:clean
clean:
	-rm Makefile~ windowevent.cpp~ windowevent keyevent.cpp~ keyevent mouseevent mouseevent.cpp~ textinput event
