exe: test.o gamebody.o geomentry.o
	g++ -o exe test.o geomentry.o GameBody.o `sdl2-config --libs --cflags` `pkg-config --libs sdl2_image` -std=c++11
test.o: test.cpp
	g++ -c test.cpp
gamebody.o: GameBody.cpp
	g++ -c GameBody.cpp
geomentry.o:
	g++ -c geomentry.cpp
.PHONY:clean
clean:
	-rm Makefile~ test.cpp~ GameBody.o test.o exe geomentry.cpp
