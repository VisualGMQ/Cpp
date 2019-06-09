all:main
main:main.cpp
	g++ main.cpp -o exe `mysql_config --libs --cxxflags` -std=c++11
.PHONY:clean
clean:
	-rm exe