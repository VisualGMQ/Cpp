all:main
main:main.cpp
	g++ main.cpp -c `pkg-config --cflags ode` -std=c++11
	g++ main.o `pkg-config --libs ode` -std=c++11
.PHONY:
clean:
	-rm exe main.o
