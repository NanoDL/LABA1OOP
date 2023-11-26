#pragma once

class Cursor {
public:
	void hidecursor();
	void gotoxy(int, int);
	int GetRandomNumber(int, int);
	void SetColor(int, int);
	double GetRandomDouble(double, double);
	int GetRandomInt(int, int);
};