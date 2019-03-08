OBJS=../obj/Gamebody.o ../obj/gbWindow.o ../obj/geomentry.o
exe:test
test:test.cpp ${OBJS}
	g++ -o test -g test.cpp ${OBJS} `sdl2-config --libs --cflags` `pkg-config --libs --cflags sdl2_image` -std=c++11
.PHONY:clean
clean:
	-rm Makefile~ test.cpp~ test
