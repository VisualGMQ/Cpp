all:
	g++ main.cpp -o exe `pkg-config --libs --cflags jsoncpp` -std=c++11
.PHONY:
clean:
	-rm exe ret1.json