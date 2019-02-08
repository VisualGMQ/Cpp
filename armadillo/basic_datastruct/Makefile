all: matrix.cpp
	g++ matrix.cpp `pkg-config --libs armadillo` -o matrix -std=c++11
.PHONY:clean
clean:
	-rm matrix.cpp~ Makefile~ matrix
