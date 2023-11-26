
#include <iostream>
#include "windows.h"
#include <stdio.h>
#include "conio.h"
#include <cstdlib>
#include <ctime>
#include <random>

#include <thread>
#include <vector>
#include <algorithm>
#include <chrono>
#include <stdlib.h> // нужен для вызова функций rand(), srand()
#include <time.h> // нужен для вызова функции time()


#include "Manager.h"
#include "Line.h"
#include "cs.h"
#include "Cursor.h"


int main() {
	setlocale(LC_ALL, "Russian");
	Manager manag = Manager(1,1,'N',1);
	Cursor cur;
	cur.hidecursor();
	manag.setLength();
	system("cls");
	manag.setSpeed();
	manag.setFreq();
	manag.setEpileps();
	manag.setFreqExp();
	manag.setMinRad();
	manag.setMaxRad();
	manag.setMode();
	system("cls");
	manag.start();


	return 0;
}