FixedVHDWriter:FixedVHDWriter.cpp VHD.o
	g++ FixedVHDWriter.cpp VHD.o -o FixedVHDWriter -std=c++11
test:test.o VHD.o
	g++ test.o VHD.o -o test -std=c++11
test.o:VHD.o
	g++ test.cpp -c -std=c++11
VHD.o:VHD.hpp VHD.cpp
	g++ VHD.cpp -c -std=c++11
.PHONY:clean
clean:
	-rm *.o test