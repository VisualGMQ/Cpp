all:main windowinfo windowfunc
main:main.cpp
	g++ main.cpp `sdl2-config --libs --cflags` -o windows -std=c++11
windowinfo:windowInfo.cpp
	g++ windowInfo.cpp -o windowinfo `sdl2-config --libs --cflags`
windowfunc:windowfunc.cpp
	g++ windowfunc.cpp -o windowfunc `sdl2-config --libs --cflags` `pkg-config --libs --cflags SDL2_image` -std=c++11
.PHONY:clean
clean:
	-rm windows windowinfo windowfunc
