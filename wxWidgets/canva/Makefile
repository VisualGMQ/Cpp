all:main
main:main.cpp
	g++ main.cpp -o exe `wx-config --libs --cflags` -std=c++11
.PHONY:
clean:
	-rm exe