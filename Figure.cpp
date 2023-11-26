#include "Figure.h"

Figure::Figure( int _x,int _y, int _maxX, int _maxY) : x(_x),y(_y), maxX(_maxX),maxY(_maxY) {

}

int Figure::getX() {
	return x;
}

int Figure::getY() {
	return y;
}