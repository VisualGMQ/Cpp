OBJS=../obj/GameBody.o ../obj/gbWindow.o ../obj/geomentry.o ../obj/gbDrawTool.o
exe:test drawShape
test:test.cpp ${OBJS}
	g++ test.cpp ${OBJS} -o test `sdl2-config --libs --cflags` `pkg-config --libs --cflags sdl2_image sdl2_ttf` -std=c++11
drawShape:drawShape.cpp ${OBJS}
	g++ drawShape.cpp ${OBJS} -o drawShape `sdl2-config --libs --cflags` -lSDL2_image -lSDL2_ttf -std=c++11
.PHONY:clean
clean:
	-rm Makefile~ test.cpp~ test drawShape
