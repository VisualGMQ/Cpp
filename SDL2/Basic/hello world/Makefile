exe: main.o
	g++ -o exe main.o -std=c++11 `sdl2-config --libs --cflags` -lSDL2_image  -std=c++11
main.o: main.cpp
	g++ -c main.cpp -std=c++11
.PHONY:clean
clean:
	-rm  main.o Makefile~ main.cpp~ .main.cpp.un~ .Makfile.un~ exe .Makefile.un~
