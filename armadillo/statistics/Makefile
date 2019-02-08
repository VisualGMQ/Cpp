all:statistics.cpp
	g++ statistics.cpp -o statistics `pkg-config --libs armadillo` -std=c++11
.PHONY:clean
clean:
	-rm statistics.cpp~ statistics Makefile~	
