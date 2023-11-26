#pragma once
#include "cs.h"
#include "Symbol.h"
#include "Cursor.h"
#include "Figure.h"
class Line : public Figure{
	bool success;
	int color = 2;
	char epileps;
	std::vector<Symbol> line;
	Cursor cur;
	int length;
	double speed;

	std::chrono::time_point<std::chrono::system_clock> timeEnd, timeStart;

	cs& console;
	bool deleting;
	bool deleted;

public:
	int i = 0;
	int _x;
	int _y;


public:
	Line(int , double , char , int, int , cs&);
	void tryMove();
	bool isDeleted();
	bool isDeleting();
	bool isLineMove();

	int getX();
	int getY();
	void resetSuccess();
	void lineExp();
};