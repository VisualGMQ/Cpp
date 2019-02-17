all:hello_world param
hello_world:hello_world.cpp
	g++ hello_world.cpp -o hello_world -std=c++11
param:param.cpp
	g++ param.cpp -o param -std=c++11
.PHONY:clean
clean:
	-rm hello_world param
