EXES+=helloworld
helloworld: main.cpp
	g++ -o helloworld main.cpp -std=c++11 `sdl2-config --libs --cflags` -lSDL2_image  -std=c++11
.PHONY:clean
clean:
	-rm helloworld
