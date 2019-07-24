all:main
main:main.cpp
	g++ main.cpp -o exe `sdl2-config --libs --cflags` `pkg-config --libs --cflags SDL2_image` -std=c++11
.PHONY:
clean:
	-rm exe