OBJS=image gfx
image:image.cpp
	g++ image.cpp -o image `pkg-config --libs --cflags SDL2_image` -std=c++11
gfx:gfx.cpp
	g++ gfx.cpp -o gfx `pkg-config --libs --cflags SDL2_gfx` -std=c++11
.PHONY:clean
clean:
	-rm ${OBJS}
all:${OBJS}