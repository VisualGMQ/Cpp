exe: main.o
	g++ -o exe main.o `sdl2-config --libs --cflags` `pkg-config --libs SDL2_image`
main.o: main.cpp
	g++ -c main.cpp
.PHONY:clean
clean:
	-rm Makefle~ main.cpp~ exe main.o
