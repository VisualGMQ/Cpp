drawShape:drawShape.o 
	g++ drawShape.o -o drawShape `wx-config --libs` -std=c++11
drawShape.o:
	g++ drawShape.cpp -c `wx-config --cflags` -std=c++11
.PHONY:clean
clean:
	-rm drawShape *.o