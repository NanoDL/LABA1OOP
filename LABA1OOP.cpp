// LABA1OOP.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

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

class Cursor {

public:


	void hidecursor()
	{
		HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO info;
		info.dwSize = 100;
		info.bVisible = FALSE;
		SetConsoleCursorInfo(consoleHandle, &info);
	}

	void gotoxy(int column, int line)
	{
		COORD coord;
		coord.X = column;
		coord.Y = line;
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		// Finally, call the SetConsoleCursorPosition function.



	}
	int GetRandomNumber(int min, int max)
	{
		namespace sc = std::chrono;
		auto time = sc::system_clock::now(); // get the current time

		auto since_epoch = time.time_since_epoch(); // get the duration since epoch

		auto millis = sc::duration_cast<sc::nanoseconds>(since_epoch);

		long now = millis.count(); // just like java (new Date()).getTime();
		// Установить генератор случайных чисел
		srand(now);

		// Получить случайное число - формула
		int num = min + rand() % (max - min + 1);

		return num;
	}


	enum ConsoleColor
	{
		Black = 0, Blue = 1, Green = 2, Cyan = 3,
		Red = 4, Magenta = 5, Brown = 6, LightGray = 7, DarkGray = 8, LightBlue = 9, LightGreen = 10,
		LightCyan = 11, LightRed = 12, LightMagenta = 13,
		Yellow = 14, White = 15
	};

	void SetColor(int text, int background)
	{
		HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
	}

	double GetRandomDouble(double a, double b) {

		namespace sc = std::chrono;
		auto time = sc::system_clock::now(); // get the current time

		auto since_epoch = time.time_since_epoch(); // get the duration since epoch
		auto millis = sc::duration_cast<sc::nanoseconds>(since_epoch);

		long now = millis.count(); // just like java (new Date()).getTime();

		std::random_device rd;
		std::mt19937 gen(now);
		std::uniform_real_distribution<double> dis(a, b);

		double c = dis(gen);

		return c;
	}

	int GetRandomDouble2(double a, double b) {

		namespace sc = std::chrono;
		auto time = sc::system_clock::now(); // get the current time

		auto since_epoch = time.time_since_epoch(); // get the duration since epoch

		auto millis = sc::duration_cast<sc::nanoseconds>(since_epoch);

		long now = millis.count(); // just like java (new Date()).getTime();

		std::random_device rd;
		std::mt19937 gen(now);
		std::uniform_int_distribution<int> dis(a, b);

		int c = dis(gen);

		return c;
	}

};


class cs
{
	int x;
	int y;

public:
	std::vector < std::vector< unsigned short> > matr;
public:
	cs() {

		CONSOLE_SCREEN_BUFFER_INFO csbi;

		HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		GetConsoleScreenBufferInfo(hStdOut, &csbi);
		x = csbi.srWindow.Right - csbi.srWindow.Left + 1;
		y = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
			
		for (int i = 0; i <= x; i++) {
			std::vector<unsigned short> new_arr(y + 1, 0);
			matr.push_back(new_arr);
		}

		//printf_s("%d %d", x, y);
	}
	int getConsoleX()
	{
		return x;
	};

	int getConsoleY() {
		return y;
	}

	void drawMatr() {
		for (size_t i = 0; i < y-1; i++)
		{
			for (size_t j = 0; j < x-1; j++)
			{
				std::cout << matr[j][i];

			}
			std::cout << std::endl;
		}
	}


};




class Symbol {

	char symbol;
	int color = 2;
	int x;
	int y;
	Cursor cur;


public:
	Symbol(int _color) : color(_color) {
		symbol = (char)cur.GetRandomNumber(33, 126);
		cur.SetColor(color, 0);
	}
	void getSymbol() {
		cur.SetColor(color, 0);
		printf_s("%c", symbol);
	}
};


class Line {


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
	int x, _x;
	int y, _y;

	int maxX;
	int maxY;
public:
	Line(int _length, double _speed, char _epileps, int _maxX, int _maxY, cs& _console) : length(_length), speed(_speed), epileps(_epileps), maxX(_maxX), maxY(_maxY), console(_console) {
		speed = (double)(1.0 / speed);
		deleting = 0;
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

	void Move() {
		/*cur.gotoxy(0, 0);
		console.drawMatr();*/
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


	bool isDeleted() {
		return deleted;
	}
	bool isDeleting() {
		return deleting;
	}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	~Line() {

	}
};

class Manager {

	int x, y;

	Cursor cur;
	int freq;
	int curFreq;
	double speed;

	double tmp;
	double chance;
	int length;
	char epileps;


	std::vector<Line*> vectLine;



	int leftLines;

	double curTmp;
	std::chrono::time_point<std::chrono::steady_clock> timeEnd, timeStart;


	std::vector<double> arrChances;

	cs conSize;




public:

	void start() {
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



			std::chrono::duration<double> duration2 = std::chrono::duration_cast<std::chrono::milliseconds>(timeEnd - timeStart);
			if (!arrChances.empty()) {
				auto begin = arrChances.begin();
				if (duration2.count() >= *begin) {

					arrChances.erase(begin);
					vectLine.push_back(new Line(length, speed, epileps, conSize.getConsoleX(), conSize.getConsoleY() - 2,conSize));

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
			
			

			cur.gotoxy(0, 0);
			printf_s("%d", vectLine.size());
			
			if (!vectLine.empty()) {
				for (auto it = vectLine.begin(); it < vectLine.end();) {
					if ((*it)->isDeleted()) {
						delete* it;
						it = vectLine.erase(it);
					}
					else {

						(*it)->Move();
						++it;
					}
				}
			}


		}
	}
	void setSpeed() {
		while (true) {
			std::cout << "Установите скорость(1-30): ";
			scanf_s("%lf", &speed);
			if (speed >= 1 && speed <= 30) {
				break;
			}
		}

	};
	void setLength() {
		while (true) {
			std::cout << "Установите длину: ";
			scanf_s("%d", &length);
			if (length >= 1 && length <= 30) {
				break;
			}
		}
	};
	void setEpileps() {
		while (true)
		{
			std::cout << "Установите режим эпилепсии (Y/n): ";
			scanf_s("%s", &epileps);
			if (epileps == 'Y' || epileps == 'y' || epileps == 'n' || epileps == 'N') {
				break;
			}
		}
	};
	void setFreq() {
		while (true)
		{
			std::cout << "Установите частоту появления: ";
			scanf_s("%d", &freq);
			leftLines = freq;
			if (freq >= 1 && freq <= 30) {
				break;
			}
		}
	}

	Manager() {
	}
};

int main() {
	setlocale(LC_ALL, "Russian");
	Manager manag;
	Cursor cur;
	cur.hidecursor();
	manag.setLength();
	system("cls");
	manag.setSpeed();
	manag.setFreq();
	manag.setEpileps();
	system("cls");
	manag.start();


	return 0;
};
