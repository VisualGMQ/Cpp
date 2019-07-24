all:main
main:main.cpp
	g++ main.cpp -o exe `sdl2-config --libs --cflags` -lGL -lGLEW -lGLU -std=c++11
.PHONY:
clean:
	-rm exe