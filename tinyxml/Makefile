all:main
main:main.cpp
	g++ main.cpp -o exe `pkg-config --libs --cflags tinyxml2` --std=c++11
.PHONY:
clean:
	-rm exe
