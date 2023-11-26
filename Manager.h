#pragma once
#include "Cursor.h"
#include "Line.h"
#include "cs.h"
#include "Explosion.h"
class Manager
{


	Cursor cur;
	int freq;
	int freqExp;
	int minRad;
	int maxRad;
	int curRad;
	double speed;

	int countExp=0;
	double chance;
	int length;
	char epileps;

	std::vector<Line*> vectLine;
	std::vector<Explosion*> vectExp;
	std::chrono::time_point<std::chrono::steady_clock> timeEnd, timeStart;

	std::vector<double> arrChances;

	cs conSize;


public:
	int mode;
	Manager(int,int,char,int);
	void start();
	void setSpeed();
	void setLength();
	void setEpileps();
	void setFreq();
	void setFreqExp();
	void setMinRad();
	void setMaxRad();
	void setMode();
	//std::vector<std::pair<int,int>> calculateCoordExp(int);
};
