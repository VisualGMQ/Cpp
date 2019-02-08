all:constants.cpp wall_clock.cpp
	g++ constants.cpp -o constant `pkg-config --libs armadillo` -std=c++11
	g++ wall_clock.cpp -o wall_clock `pkg-config --libs armadillo` -std=c++11
.PHONY:clean
clean:
	-rm wall_clock constant Makefile~ wall_clock.cpp~ constant.cpp~

