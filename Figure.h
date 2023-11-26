#pragma once
class Figure
{
protected:
	int x;
	int y;
	int maxX;
	int maxY;
	bool deleted;
public: 


	Figure(int _x, int _y, int _maxX, int _maxY);

	int getX();
	int getY();
};

