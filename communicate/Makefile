all:fork fifo
fork:fork.cpp
	g++ fork.cpp -o fork -std=c++11
fifo:rdfifo.cpp wrfifo.cpp
	g++ rdfifo.cpp -o rdfifo -std=c++11
	g++ wrfifo.cpp -o wrfifo -std=c++11
.PHONY:
clean:
	-rm rdfifo wrfifo fork