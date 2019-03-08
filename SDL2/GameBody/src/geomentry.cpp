#include "geomentry.hpp"

gbRect::gbRect(int x,int y,int w,int h){
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
}


gbPoint::gbPoint(int x,int y){
	point.x = x;
	point.y = y;
}

gbSize::gbSize(int w,int h){
	size.x = w;
	size.y = h;
}
