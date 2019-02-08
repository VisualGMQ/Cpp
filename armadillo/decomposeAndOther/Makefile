all:decompose.cpp
	g++ decompose.cpp -o decompose `pkg-config --libs armadillo` -std=c++11
.PHONY:clean
clean:
	-rm Makefile~ decompose.cpp~ decompose
