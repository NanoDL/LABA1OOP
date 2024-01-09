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

#define PI 3.14159265 

void Manager::start() {
	using namespace std;
	using namespace std::this_thread;
	using namespace std::chrono;


	timeStart = std::chrono::steady_clock::now();
	timeEnd = std::chrono::steady_clock::now();

	for (size_t i = 0; i < freq; i++)
	{

		chance = cur.GetRandomDouble((double)0, (double)1);
		arrChances.push_back(chance);

	}


	std::sort(begin(arrChances), end(arrChances));

	while (true) {


		timeEnd = std::chrono::steady_clock::now();
		std::chrono::duration<double> duration2 = std::chrono::duration_cast<std::chrono::milliseconds>(timeEnd - timeStart);
		if (!arrChances.empty()) {
			auto begin = arrChances.begin();
			if (duration2.count() >= *begin) {

				arrChances.erase(begin);
				vectLine.push_back(new Line(length, speed, epileps, conSize.getConsoleX(), conSize.getConsoleY() - 2, conSize));

			}
		}

		timeEnd = std::chrono::steady_clock::now();
		duration2 = std::chrono::duration_cast<std::chrono::milliseconds>(timeEnd - timeStart);

		if (duration2.count() > 1) {
			timeStart = std::chrono::steady_clock::now();
			arrChances.clear();
			for (size_t i = 0; i < freq; i++)
			{

				chance = cur.GetRandomDouble((double)0, (double)1);
				arrChances.push_back(chance);

			}
			std::sort(begin(arrChances), end(arrChances));
		}

		duration2 = std::chrono::duration_cast<std::chrono::milliseconds>(timeEnd - timeStart);



		timeEnd = std::chrono::steady_clock::now();


		if (!vectLine.empty()) {
			for (size_t i = 0; i < vectLine.size(); )
			{
				if (vectLine[i]->isDeleted()) {
					
					vectLine.erase(i);
				}
				else {

					if (vectLine[i]->isLineMove())
					{
						if (cur.GetRandomInt(1, 1000) <= freqExp && vectLine[i]->getX() < conSize.getConsoleX()) {
							vectExp.push_back(new Explosion(minRad, maxRad, vectLine[i]->getX(), vectLine[i]->getY(), conSize.getConsoleX(), conSize.getConsoleY() - 2, mode));
							countExp++;
							vectLine[i]->lineExp();
						}
						vectLine[i]->resetSuccess();
					}
					vectLine[i]->tryMove();

					i++;
					
				}
			}
			/*for (auto it = vectLine.begin(); it != vectLine.end();) {

				if ((*it).isDeleted()) {
					delete it;
					vectLine.erase(it);
				}
				else {

					if ((*it).isLineMove())
					{
						if (cur.GetRandomInt(1, 1000) <= freqExp && (*it).getX() < conSize.getConsoleX()) {
							vectExp.push_back(new Explosion(minRad, maxRad, (*it).getX(), (*it).getY(), conSize.getConsoleX(), conSize.getConsoleY() - 2,mode));
							countExp++;
							(*it).lineExp();
						}
						(*it).resetSuccess();
					}
					(*it).tryMove();


					++it;
				}
			}*/
		}
		//cur.gotoxy(0, 0);
		//printf_s("%d", vectExp.size());
		if (!vectExp.empty()) {									//пробежка по вектору из взрывов
			for (size_t i = 0; i < vectExp.size();) {

				if (vectExp[i]->isDeleted()) {
					
					vectExp.erase(i);
				}
				else {
					vectExp[i]->tryMove();
					i++;
				}
			}
			//for (auto at = vectExp.begin(); at != vectExp.end();) {

			//	if ((*at).isDeleted()) {
			//		delete at;
			//		//at = vectExp.erase(at);
			//	}
			//	else {
			//		(*at).tryMove();
			//		++at;
			//	}
			//}
		}

	}
}
Manager::Manager(int _speed, int _length, char _epileps, int _freq) : speed(_speed), length(_length), epileps(_epileps), freq(_freq) {
	chance = 0;
	mode = 1;
};
void Manager::setSpeed() {
	while (true) {
		std::cout << "Установите скорость(1-30): ";
		scanf_s("%lf", &speed);
		if (speed >= 1 && speed <= 30) {
			break;
		}
	}

};
void Manager::setLength() {
	while (true) {
		std::cout << "Установите длину: ";
		scanf_s("%d", &length);
		if (length >= 1 && length <= 30) {
			break;
		}
	}
};
void Manager::setEpileps() {
	while (true)
	{
		std::cout << "Установите режим эпилепсии (Y/n): ";
		scanf_s("%s", &epileps);
		if (epileps == 'Y' || epileps == 'y' || epileps == 'n' || epileps == 'N') {
			break;
		}
	}
};
void Manager::setFreq() {
	while (true)
	{
		std::cout << "Установите частоту появления: ";
		scanf_s("%d", &freq);
		if (freq >= 1 && freq <= 30) {
			break;
		}
	}
}



void Manager::setFreqExp() {
	while (true)
	{
		std::cout << "Установите вероятность взрывов: ";
		scanf_s("%d", &freqExp);
		if (freqExp >= 1 && freqExp <= 1000) {
			break;
		}
	}
}
void Manager::setMinRad() {
	while (true)
	{
		std::cout << "Установите минимальный радиус взрыва: ";
		scanf_s("%d", &minRad);
		if (minRad >= 1 && minRad <= 10) {
			break;
		}
	}
}
void Manager::setMaxRad() {
	while (true)
	{
		std::cout << "Установите максимальный радиус взрыва: ";
		scanf_s("%d", &maxRad);
		if (maxRad >= minRad && maxRad <= 10) {
			break;
		}
	}
}
void Manager::setMode() {
	while (true)
	{
		std::cout << "Установите режим рисования взрывов(1 - простой или 2 - в виде ромба): ";
		scanf_s("%d", &mode);
		if (mode >= 1 && mode <= 2) {
			break;
		}
	}
}
//std::vector<std::pair<int, int>> Manager::calculateCoordExp(int curRad ) {
	//double x = 0;
	//double y = 0;
	//int x_c = 0, y_c = 0;
	//std::vector<std::pair<int, int>> vectorCoord;
	//for (size_t i = 0; i < 90; i += 6)
	//{
	//	x = 2.1 * curRad * cos(i * PI / 180);
	//	y = curRad * sin(i * PI / 180);
	//	x_c = round(x);
	//	y_c = round(y);
	//	vectorCoord.push_back(std::make_pair(x_c,y_c));
	//}

//}


