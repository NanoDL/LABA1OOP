#pragma once
#include "Cursor.h"
class Symbol {
	char symbol;
	int color = 2;
	Cursor cur;

	public:
		Symbol(int);
		void getSymbol();
};

