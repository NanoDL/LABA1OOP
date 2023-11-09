#pragma once
#include "Cursor.h"
#include "Line.h"
#include "cs.h"
class Manager
{


	Cursor cur;
	int freq;

	double speed;

	
	double chance;
	int length;
	char epileps;
	
	std::vector<Line*> vectLine;

	std::chrono::time_point<std::chrono::steady_clock> timeEnd, timeStart;

	std::vector<double> arrChances;

	cs conSize;


public:
	Manager(int,int,char,int);
	void start();
	void setSpeed();
	void setLength();
	void setEpileps();
	void setFreq();
};
