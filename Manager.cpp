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
				for (auto it = vectLine.begin(); it < vectLine.end();) {

					if ((*it)->isDeleted()) {
						delete* it;
						it = vectLine.erase(it);
					}
					else {

						(*it)->tryMove();
						++it;
					}
				}
			}


		}
	}
	Manager::Manager(int _speed, int _length, char _epileps, int _freq) : speed(_speed), length(_length), epileps(_epileps), freq(_freq) {
		chance = 0;
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



