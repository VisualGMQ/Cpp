all:main windowinfo
main:main.cpp
	g++ main.cpp `sdl2-config --libs --cflags` -o windows -std=c++11
windowinfo:windowInfo.cpp
	g++ windowInfo.cpp -o windowinfo `sdl2-config --libs --cflags`
.PHONY:clean
clean:
	-rm windows windowinfo
