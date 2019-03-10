all:tgeomentry tgbWindow
tgeomentry:tgeomentry.cpp
	g++ tgeomentry.cpp ../obj/geomentry.o -o tgeomentry `sdl2-config --libs --cflags` -std=c++11
tgbWindow:tgbWindow.cpp
	g++ tgbWindow.cpp ../obj/geomentry.o ../obj/gbWindow.o -o tgbWindow  `sdl2-config --libs --cflags` -lSDL2_image -std=c++11
.PHONY:
clean:
	-rm tgbWindow tgeomentry
