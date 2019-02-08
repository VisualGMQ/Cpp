all:surface
surface:surface.cpp
	g++ surface.cpp -o surface `sdl2-config --libs --cflags` -std=c++11
.PHONY:clean
clean:
	-rm surface
