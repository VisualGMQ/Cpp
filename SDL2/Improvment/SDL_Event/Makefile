all:windowevent.cpp keyevent.cpp mouseevent.cpp
	g++ windowevent.cpp -o windowevent `sdl2-config --libs --cflags` `pkg-config --libs SDL2_image` -std=c++11
	g++ keyevent.cpp -o keyevent `sdl2-config --libs --cflags` `pkg-config --libs SDL2_image` -std=c++11
	g++ mouseevent.cpp -o mouseevent `sdl2-config --libs --cflags` `pkg-config --libs SDL2_image` -std=c++11
.PHONY:clean
clean:
	-rm Makefile~ windowevent.cpp~ windowevent keyevent.cpp~ keyevent mouseevent mouseevent.cpp~
