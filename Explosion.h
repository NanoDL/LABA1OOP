#pragma once
#include "Figure.h"
#include <chrono>
#include <vector>
#include "Cursor.h"
#include "cs.h"
#include "Symbol.h"
#define PI 3.14159265 
using namespace std;
class Explosion : public Figure
{
public:
	int mode;
	Symbol* sym;
	int minRad;
	int curRad;
	int maxRad;
	int predRad;
	bool deleted;

	double x_buf, y_buf;
	int x_c, y_c;
	chrono::time_point<chrono::system_clock> timeEnd, timeStart;
	vector<int> xPrev;
	vector<int> yPrev;

	Cursor cur;
	
	Explosion(int _minRad, int _maxRad, int _x, int _y, int _maxX, int _maxY, int _mode);
	void tryMove();
	bool isDeleted();
};


