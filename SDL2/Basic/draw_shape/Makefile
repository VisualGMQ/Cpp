exe: main.cpp GameBody.o
	g++ main.cpp GameBody.o -o exe `sdl2-config --libs --cflags` `pkg-config --libs sdl2_image` -std=c++11

GameBody.o:GameBody.cpp
	g++ -c GameBody.cpp
