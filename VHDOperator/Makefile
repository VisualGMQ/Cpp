exe:main.o VHD.o
	g++ main.o VHD.o -o exe -std=c++11
main.o:VHD.o
	g++ main.cpp -c -std=c++11
VHD.o:
	g++ VHD.cpp -c -std=c++11
.PHONY:clean
clean:
	-rm *.o exe