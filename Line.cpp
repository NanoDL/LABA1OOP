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

#include "Cursor.h"
#include "Symbol.h"
#include "cs.h"
#include "Line.h"

	Line::Line(int _length, double _speed, char _epileps, int _maxX, int _maxY, cs& _console) : length(_length), speed(_speed), epileps(_epileps), maxX(_maxX), maxY(_maxY), console(_console) {
		speed = (double)(1.0 / speed);
		//deleting = 0;
		deleted = false;
		x = 0;
		y = cur.GetRandomNumber(0, maxY);
		_x = 0;
		_y = 0;
		if (epileps == 'Y' or epileps == 'y') {
			color = cur.GetRandomDouble2(1, 15);
		}
		for (int i = 0; i < length; i++) {
			line.push_back(Symbol(color));
			/*Sleep(1);*/
		}


	};

	void Line::tryMove() {  //TryMove
		timeEnd = std::chrono::system_clock::now();

		if (std::chrono::duration<double>(timeEnd - timeStart).count() >= speed && !deleted) {

			std::vector<Symbol>::iterator begin = line.begin();
			std::vector<Symbol>::iterator end = line.end();

			if (x >= length) {
				_x = x - length;
				_y = y + ((x - length) % 2);

				//if (x < maxX) {
				console.matr[_x][_y]--;
				//}


				if (console.matr[_x][_y] == 0) {
					cur.gotoxy(_x, _y);
					printf_s(" ");
				}
			}




			cur.gotoxy(x, y + (x % 2));

			if (x < maxX)
			{
				console.matr[x][y + (x % 2)]++;
				--end;
				(*end).getSymbol();
			}
			line.erase(begin);
			line.push_back(Symbol(color));
			x++;
			if (x - length >= maxX) {
				deleted = true;
			}
			begin = line.begin();
			end = line.end();


			timeStart = std::chrono::system_clock::now();
		}
	};


	bool Line::isDeleted() {
		return deleted;
	}
	bool Line::isDeleting() {
		return deleting;
	}
	int Line::getX() {
		return x;
	}
	int Line::getY() {
		return y;
	}

