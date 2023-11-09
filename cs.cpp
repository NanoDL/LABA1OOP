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


#include "cs.h"
    //попробовать динамически измнять консоль WinAPI

	cs::cs() {

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
	int cs::getConsoleX()
	{
		return x;
	};

	int cs::getConsoleY() {
		return y;
	}

	void cs::drawMatr() {
		for (size_t i = 0; i < y - 1; i++)
		{
			for (size_t j = 0; j < x - 1; j++)
			{
				std::cout << matr[j][i];

			}
			std::cout << std::endl;
		}
	}

