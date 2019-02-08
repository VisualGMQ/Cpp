all:attris_eles.cpp fill.cpp resize.cpp subObject.cpp specialop.cpp
	g++ attris_eles.cpp -o attris_eles -std=c++11 `pkg-config --libs armadillo`
	g++ fill.cpp -o fill -std=c++11 `pkg-config --libs armadillo`
	g++ resize.cpp -o resize -std=c++11 `pkg-config --libs armadillo`
	g++ subObject.cpp -o subObject -std=c++11 `pkg-config --libs armadillo`
	g++ specialop.cpp -o specialop -std=c++11 `pkg-config --libs armadillo`
.PHONY:clean
clean:
	-rm Makefile~ attris_eles attris_eles.cpp~ fill.cpp~ fill resize.cpp~ resize subObject.cpp~ subObject specialop.cpp~ specialop m_armaAscii.bin	m_csvAscii.bin	m_rawAscii.bin
