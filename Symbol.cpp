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

	Symbol::Symbol(int _color) : color(_color) {
		symbol = (char)cur.GetRandomNumber(33, 126);
		cur.SetColor(color, 0);
	}
	void Symbol::getSymbol() {
		cur.SetColor(color, 0);
		printf_s("%c", symbol);
	}
