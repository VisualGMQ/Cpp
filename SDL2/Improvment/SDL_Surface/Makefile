OBJS=surface pixelOp surfaceInfo
SDL2_CONFIG=`sdl2-config --libs --cflags`
SDL2_IMG_CONFIG=`pkg-config --libs --cflags sdl2_image`
CPP_OPTION=-std=c++11

surface:surface.cpp PixelFormat2String.hpp
	g++ surface.cpp -o surface ${SDL2_CONFIG} ${CPP_OPTION}
pixelOp:pixelOp.cpp
	g++ pixelOp.cpp -o pixelOp ${SDL2_CONFIG} ${CPP_OPTION}
surfaceInfo:surfaceInfo.cpp PixelFormat2String.hpp
	g++ surfaceInfo.cpp -o surfaceInfo ${SDL2_CONFIG} ${SDL2_IMG_CONFIG} ${CPP_OPTION}

.PHONY:clean all
all:${OBJS}
clean:
	-rm ${OBJS}
