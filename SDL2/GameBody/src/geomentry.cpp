#include "geomentry.hpp"

gbRect::gbRect(int x,int y,int w,int h){
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
}

bool gbRect::operator==(gbRect r) const{
	return (rect.x == r.getX()) && (rect.y == r.getY()) && (rect.w == r.getWidth()) && (rect.h == r.getHeight());
}

bool gbRect::operator!=(gbRect r) const{
	return !(*this == r);
}

gbPoint::gbPoint(int x,int y){
	point.x = x;
	point.y = y;
}

bool gbPoint::operator==(gbPoint p) const{
	return (point.x == p.getX()) && (point.y == p.getY());
}

bool gbPoint::operator!=(gbPoint p) const{
	return !(*this == p);
}

gbSize::gbSize(int w,int h){
	size.x = w;
	size.y = h;
}

bool gbSize::operator==(gbSize s) const{
	return (size.x == s.getWidth()) && (size.y == s.getHeight());
}

bool gbSize::operator!=(gbSize s) const{
	return !(*this == s);
}

gbColor::gbColor(int r,int g,int b){
		color.r = r;
		color.g = g;
		color.b = b;
}
