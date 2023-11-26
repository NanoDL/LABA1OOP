#include "Explosion.h"


Explosion::Explosion(int _minRad, int _maxRad, int _x, int _y, int _maxX, int _maxY, int _mode) : minRad(_minRad), maxRad(_maxRad), Figure(_x, _y, _maxX, _maxY), mode(_mode) {
	deleted = false;
	timeEnd = chrono::system_clock::now();
	timeStart = chrono::system_clock::now();
	curRad = minRad;
	sym = new Symbol(1);
}


void Explosion::tryMove() {
	timeEnd = chrono::system_clock::now();

	if (chrono::duration<double>(timeEnd - timeStart).count() >= 0.5 && curRad <= maxRad) {

		if (curRad > minRad) {
			if (mode == 1) {
				if (x + predRad > 0 && x + predRad <= maxX && y + predRad > 0 && y + predRad <= maxY)
				{
					cur.gotoxy(x + predRad, y + predRad);
					printf_s(" ");
				}
				if (x + predRad > 0 && x + predRad <= maxX && y - predRad > 0 && y - predRad <= maxY)
				{
					cur.gotoxy(x + predRad, y - predRad);
					printf_s(" ");
				}
				if (x - predRad > 0 && x - predRad <= maxX && y + predRad > 0 && y + predRad <= maxY)
				{
					cur.gotoxy(x - predRad, y + predRad);
					printf_s(" ");
				}
				if (x - predRad > 0 && x - predRad <= maxX && y - predRad > 0 && y - predRad <= maxY)
				{
					cur.gotoxy(x - predRad, y - predRad);
					printf_s(" ");
				}

				if (x + predRad > 0 && x + predRad < maxX) {
					cur.gotoxy(x + predRad, y);
					printf_s(" ");
				}
				if (y + predRad > 0 && y + predRad < maxY) {
					cur.gotoxy(x, y + predRad);
					printf_s(" ");
				}
				if (y - predRad > 0 && y - predRad < maxY) {
					cur.gotoxy(x, y - predRad);
					printf_s(" ");
				}
				if (x - predRad > 0 && x - predRad < maxX) {
					cur.gotoxy(x - predRad, y);
					printf_s(" ");
				}

			}


			if (mode == 2)
			{
				for (size_t i = 0; i < xPrev.size(); i++) {
					x_c = xPrev[i];
					y_c = yPrev[i];


					if (x + x_c <= maxX && y + y_c <= maxY && x + x_c >= 0 && y + y_c >= 0) {

						cur.gotoxy(x + x_c, y + y_c);
						printf_s(" ");


					}

					if (x - x_c <= maxX && y + y_c <= maxY && x - x_c >= 0 && y + y_c >= 0) {
						cur.gotoxy(x - x_c, y + y_c);
						printf_s(" ");


					}

					if (x + x_c <= maxX && y - y_c <= maxY && x + x_c >= 0 && y - y_c >= 0) {

						cur.gotoxy(x + x_c, y - y_c);
						printf_s(" ");


					}
					if (x - x_c <= maxX && y - y_c <= maxY && x - x_c >= 0 && y - y_c >= 0) {

						cur.gotoxy(x - x_c, y - y_c);
						printf_s(" ");


					}
				}
			}

		}
		if (curRad == maxRad) {
			deleted = true;
		}
		xPrev.clear();
		yPrev.clear();

		if (curRad < maxRad) {
			//for (size_t i = 0; i < 90; i += 6)
			x_c =0;
			y_c = curRad;
			if (mode == 1) {
				if (x + curRad > 0 && x + curRad <= maxX && y + curRad > 0 && y + curRad <= maxY)
				{
					cur.gotoxy(x + curRad, y + curRad);

					sym->randColor();
					sym->getSymbol();
					//delete sym;
				}
				if (x + curRad > 0 && x + curRad <= maxX && y - curRad > 0 && y - curRad <= maxY)
				{
					cur.gotoxy(x + curRad, y - curRad);
					sym->randColor();
					sym->getSymbol();
					//delete sym;
				}
				if (x - curRad > 0 && x - curRad <= maxX && y + curRad > 0 && y + curRad <= maxY)
				{
					cur.gotoxy(x - curRad, y + curRad);
					sym->randColor();
					sym->getSymbol();
					//delete sym;
				}
				if (x - curRad > 0 && x - curRad <= maxX && y - curRad > 0 && y - curRad <= maxY)
				{
					cur.gotoxy(x - curRad, y - curRad);
					sym->randColor();
					sym->getSymbol();
					//delete sym;
				}

				if (x + curRad > 0 && x + curRad < maxX) {
					cur.gotoxy(x + curRad, y);
					sym->randColor();
					sym->getSymbol();
					//delete sym;
				}
				if (y + curRad > 0 && y + curRad < maxY) {
					cur.gotoxy(x, y + curRad);
					sym->randColor();
					sym->getSymbol();
					//delete sym;
				}
				if (y - curRad > 0 && y - curRad < maxY) {
					cur.gotoxy(x, y - curRad);
					sym->randColor();
					sym->getSymbol();
					//delete sym;
				}
				if (x - curRad > 0 && x - curRad < maxX) {
					cur.gotoxy(x - curRad, y);
					sym->randColor();
					sym->getSymbol();
					//delete sym;
				}
			}


			if (mode == 2) {
				for (size_t i = 0; i <= curRad; i++) {
					//x_buf = curRad * cos(i * PI / 180);
					//y_buf = curRad * sin(i * PI / 180);
					//x_c = round(x_buf);
					//y_c = round(y_buf);

					//if (!xPrev.empty()) {
						//if (yPrev.back() != y_c) {

					xPrev.push_back(x_c);
					yPrev.push_back(y_c);

					if (x + x_c <= maxX && y + y_c <= maxY && x + x_c >= 0 && y + y_c >= 0) {

						cur.gotoxy(x + x_c, y + y_c);
						sym->randColor();
						sym->getSymbol();
						//delete sym;


					}

					if (x - x_c <= maxX && y + y_c <= maxY && x - x_c >= 0 && y + y_c >= 0) {

						cur.gotoxy(x - x_c, y + y_c);
						sym->randColor();
						sym->getSymbol();
						//delete sym;


					}

					if (x + x_c <= maxX && y - y_c <= maxY && x + x_c >= 0 && y - y_c >= 0) {

						cur.gotoxy(x + x_c, y - y_c);
						sym->randColor();
						sym->getSymbol();
						//delete sym;;

					}

					if (x - x_c <= maxX && y - y_c <= maxY && x - x_c >= 0 && y - y_c >= 0) {

						cur.gotoxy(x - x_c, y - y_c);
						sym->randColor();
						sym->getSymbol();
						//delete sym;

					}

					x_c++;
					y_c--;




				}
			}

		}
		predRad = curRad;
		curRad++;
		timeStart = chrono::system_clock::now();
	}
}

bool Explosion::isDeleted()
{
	return deleted;
}
