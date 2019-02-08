all:getKeycode.cpp
	g++ getKeycode.cpp -o getKeycode `sdl2-config --libs --cflags` -std=c++11
.PHONY:clean
clean:
	-rm getKeycode.cpp~ getKeycode Makefile~
