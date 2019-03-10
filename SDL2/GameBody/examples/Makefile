OBJS=../obj/GameBody.o ../obj/gbWindow.o ../obj/geomentry.o ../obj/gbInput.o
exe:test
test:test.cpp ${OBJS}
	g++ -o test test.cpp ${OBJS} `sdl2-config --libs --cflags` -lSDL2_image -std=c++11
.PHONY:clean
clean:
	-rm Makefile~ test.cpp~ test
