#include <conio.h>
#include <iostream>
#include <thread>
#include <vector>
#include <windows.h>
namespace practica
{
    //П4-1-1 Заполните квадрат n на n по спирали в направлении часовой стрелки от наружной части квадрата к внутренней
    //цифрами от 0 до 9 (циклически)с последовательно меняющимися цветами, начиная с левого верхнего угла.

    // Untested, but simple enough it should at least be close to reality...
    void gotoxy(short x, short y) { 
        COORD pos = {x, y};
        HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleCursorPosition(output, pos);
    }
    
    int P411()
    {
       
        std::cout << "Input N count: (0 - Quit): ";
        int n = 0;
        scanf_s("%i", &n);
        if (!n) return 1;
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        const int nmax = 20;
        int x = 1, y = 0;//координаты
        int increment = 1, cell = 1; //прирощение по +1 -1 , количество ячеек
        int number = 0;//цифра от 0 до 9
        if (n <= 0 || n > nmax) {
            return 1;
        }
        system("cls");
        short countn = 1;
        bool flag = false;
        do
        {
            SetConsoleTextAttribute(hConsole, countn);
            gotoxy(x - 1, y);
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << number;
            x = x + increment;
            cell += 1;
            number += 1;
            if (number > 9) {
                number = 0;
            }
            else if (x > n)
            {
                x = n;
                y += 1;
                if(flag){
                    increment = -increment;
                    flag = false;
                    
                }
                flag = true;
            }
            else if (x == 0)
                {
                x = 1;
                increment = -increment;
                y -= 1;
               
            }
            
            countn++;
        } while (cell <= n*n);
        printf("\n\n\n\n");
        system("pause");
        return 0;
    }
}
