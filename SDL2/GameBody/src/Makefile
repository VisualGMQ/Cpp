all: gbWindow geomentry GameBody
geomentry:geomentry.cpp
	g++ -c geomentry.cpp -o ../obj/geomentry.o -std=c++11
GameBody:GameBody.cpp
	g++ -c GameBody.cpp -o ../obj/GameBody.o -std=c++11
gbWindow:gbWindow.cpp
	g++ -c gbWindow.cpp -o ../obj/gbWindow.o -std=c++11
.PHONY:
clean:
	-rm -rf ../obj/*
