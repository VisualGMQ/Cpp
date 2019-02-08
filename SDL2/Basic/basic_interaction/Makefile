exe: main.o
	g++ -o exe main.o -std=c++11 `sdl2-config --libs --cflags` `pkg-config --libs sdl2_image`
main.o: main.cpp
	g++ -c main.cpp
.PHONY:clean
clean:
	-rm  main.o Makefile~ main.cpp~ .main.cpp.un~ .Makfile.un~ exe .Makefile.un~
