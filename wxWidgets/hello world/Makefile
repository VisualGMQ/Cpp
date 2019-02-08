exe:main.cpp main2.cpp
	g++ -o exe main.cpp `wx-config --libs --cxxflags` -std=c++11
	g++ -o exe2 main2.cpp `wx-config --libs --cxxflags` -std=c++11
.PHONY:clean
clean:
	-rm exe main.cpp~ Makefile~ exe2
