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


	void Cursor::hidecursor()
	{
		HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO info;
		info.dwSize = 100;
		info.bVisible = FALSE;
		SetConsoleCursorInfo(consoleHandle, &info);
	}

	void Cursor::gotoxy(int column, int line)
	{
		// Create a COORD structure and fill in its members.
		// This specifies the new position of the cursor that we will set.
		COORD coord;
		coord.X = column;
		coord.Y = line;
		// Obtain a handle to the console screen buffer.
		// (You're just using the standard console, so you can use STD_OUTPUT_HANDLE
		// in conjunction with the GetStdHandle() to retrieve the handle.)
		// Note that because it is a standard handle, we don't need to close it.
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		// Finally, call the SetConsoleCursorPosition function.
		if (!SetConsoleCursorPosition(hConsole, coord))
		{
			// Uh-oh! The function call failed, so you need to handle the error.
			// You can call GetLastError() to get a more specific error code.
			// ...
		}


	}
	int Cursor::GetRandomNumber(int min, int max)
	{
		namespace sc = std::chrono;
		auto time = sc::system_clock::now(); // get the current time

		auto since_epoch = time.time_since_epoch(); // get the duration since epoch

		// I don't know what system_clock returns
		// I think it's uint64_t nanoseconds since epoch
		// Either way this duration_cast will do the right thing
		auto millis = sc::duration_cast<sc::nanoseconds>(since_epoch);

		long now = millis.count(); // just like java (new Date()).getTime();
		// Установить генератор случайных чисел
		srand(now);

		// Получить случайное число - формула
		int num = min + rand() % (max - min + 1);

		return num;
	}


	void Cursor::SetColor(int text, int background)
	{
		HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
	}

	double Cursor::GetRandomDouble(double a, double b) {

		namespace sc = std::chrono;
		auto time = sc::system_clock::now(); // get the current time

		auto since_epoch = time.time_since_epoch(); // get the duration since epoch

		auto millis = sc::duration_cast<sc::nanoseconds>(since_epoch);

		long now = millis.count(); 

		std::random_device rd;
		std::mt19937 gen(now);
		std::uniform_real_distribution<double> dis(a, b);

		double c = dis(gen);

		return c;
	}

	int Cursor::GetRandomInt(int a, int b) {

		namespace sc = std::chrono;
		auto time = sc::system_clock::now(); // get the current time

		auto since_epoch = time.time_since_epoch(); // get the duration since epoch

		auto millis = sc::duration_cast<sc::nanoseconds>(since_epoch);

		long now = millis.count();

		std::random_device rd;
		std::mt19937 gen(now);
		std::uniform_int_distribution<int> dis(a, b);

		int c = dis(gen);

		return c;
	}
