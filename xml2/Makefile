all:main
main:main.cpp
	g++ main.cpp -o exe `xml2-config --libs --cflags`
.PHONY:
clean:
	-rm exe
