all:main.cpp
	g++ main.cpp -o exe `pkg-config --libs --cflags SDL2_image` `SDL2-config --libs --cflags` -std=c++11
.PHONY:clean
clean:
	-rm exe Makefile~ main.cpp~
