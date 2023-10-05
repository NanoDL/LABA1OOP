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
        void gotoxy(int column, int line)
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
        int GetRandomNumber(int min, int max)
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

            // I don't know what system_clock returns
            // I think it's uint64_t nanoseconds since epoch
            // Either way this duration_cast will do the right thing
            auto millis = sc::duration_cast<sc::nanoseconds>(since_epoch);

            long now = millis.count(); // just like java (new Date()).getTime();

            std::random_device rd;
            std::mt19937 gen(now);
            std::uniform_real_distribution<double> dis(a, b);

            double c = dis(gen);

            return c;
        }

};


class cs
{
    int x;
    int y;

    public:
        cs() {
            
            CONSOLE_SCREEN_BUFFER_INFO csbi;

            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            GetConsoleScreenBufferInfo(hStdOut, &csbi);
            x = csbi.srWindow.Right - csbi.srWindow.Left + 1;
            y = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
        }
        int getConsoleX()
        {
            return x;
        };

        int getConsoleY() {
            return y;
        }

};




class Symbol {

    char symbol;
    int color = 2;
    int x;
    int y;
    Cursor cur;


    public:
        Symbol(){
                symbol = (char)cur.GetRandomNumber(33, 126);
                cur.SetColor(color, 0);
        } 
        void getSymbol() {
            printf_s("%c", symbol);
        }
};


class Line {



    std::vector<Symbol> line;
    Cursor cur;
    int length;
    double speed;
    /*clock_t start;
    clock_t end;*/

    std::chrono::time_point<std::chrono::system_clock> timeEnd, timeStart;


    bool deleting;
    bool deleted;
    public:
        int i = 0;
        int x;
        int y;

        int maxX;
        int maxY;
    public:
        Line(int _length, double _speed, int _maxX, int _maxY) : length(_length), speed(_speed), maxX(_maxX), maxY(_maxY) {
            speed = (double)(1.0 / speed);

            for (int i = 0; i < length; i++) {
                line.push_back(Symbol());
                /*Sleep(1);*/
            }
            x = 0;
            y = cur.GetRandomNumber(0,maxY);
            

        };

        void Move(){
            
            timeEnd = std::chrono::system_clock::now();

            /*cur.gotoxy(1, 1);
            std::cout << std::chrono::duration<double>(timeEnd - timeStart).count();*/

            if (std::chrono::duration<double>(timeEnd - timeStart).count() >= speed){

            /*if ( ( ((double)(end - start)) / CLOCKS_PER_SEC) >= speed) {*/
         
                std::vector<Symbol>::iterator begin = line.begin();
                std::vector<Symbol>::iterator end = line.end();

                if (x < maxX-2  && !deleting) {
                    
                    cur.gotoxy(x, y + (x % 2));
                    end--;
                    (*end).getSymbol();

                    line.erase(begin);
                    line.push_back(Symbol());

                    begin = line.begin();
                    end = line.end();
                    if (x >= length) {
                        cur.gotoxy(x - length, y + ((x - length) % 2));
                        printf_s(" ");
                    }
                    x += 1;
                }
                else {
                    if (!deleting) {
                        deleting = true;
                        x -= length + 1;
                    }
                    cur.gotoxy(x, y + (x % 2));
                    printf_s(" ");
                    
                    if (deleting && x == maxX-2)
                    {
                        deleted = true;
                    }
                    x++;
                }
                timeStart = std::chrono::system_clock::now();
            }
        };
        
        bool isDeleted() {
            return deleted;
        }
        ~Line() {
            
        }
};

class Manager {

   
   
    
    Cursor cur;
    int freq;
    int curFreq;
    double speed;

    double tmp;
    double chance;
    int length;
    int epileps;
    bool isDeleting;
    std::vector<Line*> vectLine;

    int leftLines;
  
    double curTmp;
    std::chrono::time_point<std::chrono::steady_clock> timeEnd, timeStart,time1,time2;


    std::vector<double> arrChances;
   /* auto timeStart;
    auto timeEnd;*/


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
                 sleep_for(milliseconds(1));
                 chance = cur.GetRandomDouble((double)0, (double)1);
                 arrChances.push_back(chance);
                 cout << " " <<arrChances[i];
                }
             std::sort(begin(arrChances), end(arrChances));
            

            while (true) {


         
                    std::chrono::duration<double> duration2 = std::chrono::duration_cast<std::chrono::milliseconds>(timeEnd-timeStart);
                    if (!arrChances.empty()) {
                        auto begin = arrChances.begin();
                        if (duration2.count() >= *begin) {

                            arrChances.erase(begin);
                            vectLine.push_back(new Line(length, speed, 100, 25));

                        }
                    }
                    timeEnd = std::chrono::steady_clock::now();
                    duration2 = std::chrono::duration_cast<std::chrono::milliseconds>(timeEnd - timeStart);
                    //time1 = std::chrono::steady_clock::now();
                    if (duration2.count() > 1) {
                        timeStart = std::chrono::steady_clock::now();
                        for (size_t i = 0; i < freq; i++)
                        {

                            chance = cur.GetRandomDouble((double)0, (double)1);

                            arrChances.push_back(chance);

                        }
                        std::sort(begin(arrChances), end(arrChances));
                    }
                    /*time2 = std::chrono::steady_clock::now();
                    duration2 = std::chrono::duration_cast<std::chrono::milliseconds>(time2 - time1);
                    cur.gotoxy(50, 1);
                    cout << "XUI  " << duration2.count();*/


                    duration2 = std::chrono::duration_cast<std::chrono::milliseconds>(timeEnd - timeStart);





                    

                    timeEnd = std::chrono::steady_clock::now();
                
                     cur.gotoxy(50, 1);
                     cout << "Размер вектора  " << vectLine.size();
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

                 /*   if (arrChances.size() == freq) {
                        vectLine.insert(vectLine.begin(), freq, new Line(length, speed, 100, 25));
                        arrChances.clear();
                    }*/


            }
        }
        void setSpeed() {
            std::cout << "Установите скорость: ";
            scanf_s("%lf", &speed);
        };
        void setLength() {
            std::cout << "Установите длину: ";
            scanf_s("%d", &length);
        };
        void setEpileps() {
            std::cout << "Установите режим эпилепсии: ";
            scanf_s("%d", &epileps);
        };
        void setFreq() {
            std::cout << "Установите частоту появления: ";
            scanf_s("%d", &freq);
            leftLines = freq;
        }

        Manager() {
  
        }
};

int main() {
    setlocale(LC_ALL, "Russian");
    Manager manag;
    manag.setLength();
    system("cls");
    manag.setSpeed();
    manag.setFreq();
    system("cls");
    manag.start();


    return 0;
};
