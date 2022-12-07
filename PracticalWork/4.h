
#include <conio.h>
#include <iostream>
#include <thread>
#include <windows.h>

namespace practica
{
#define PI 3.1415926535
#define DEG_TO_RAD(deg)((float(deg)/180.f)*PI)

    char GetChar(short x, short y)
    {
        CHAR_INFO ci;
        SMALL_RECT rect = { x, y, x, y };
        return ReadConsoleOutputA(GetStdHandle(STD_OUTPUT_HANDLE), &ci, { 1,1 }, { 0, 0 }, &rect)
            ? ci.Char.AsciiChar
            : '\0';
    }

    void SetPos(const COORD& pos) {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    }

    void P411()
    {
        int n = 0;
        std::cout << "Input N count:";
        std::cin >> n;
        if (n <= 0)
            return;

        system("cls");

        COORD current_pos{ 0,0 };
        COORD direction{ 1,0 };
        size_t distance{ 4 };
        float current_angle{ 90 };
        for (uint32_t i = 1; i <= n * n; i++)
            {
                SetPos(current_pos);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
                std::cout << (i - 1) % 10;
                auto abs_x_factor = abs(current_pos.X * direction.X);
                auto abs_y_factor = abs(current_pos.Y * direction.Y);
                auto prediction_char = GetChar(current_pos.X + direction.X * distance, current_pos.Y + direction.Y * distance);
                if (i > 1 &&
                        ((prediction_char != ' ') ||
                        ((direction.X && (abs_x_factor == 0 || (abs_x_factor == n * distance - distance))) ||
                        (direction.Y && (abs_y_factor == 0 || (abs_y_factor == n * distance - distance))))))
                        current_angle += 90;    
                direction.X = round(sin(DEG_TO_RAD(current_angle)));
                direction.Y = round(sin(DEG_TO_RAD(current_angle - 90)));
                current_pos = {
                    short(current_pos.X + (direction.X * distance)),
                    short(current_pos.Y + (direction.Y * distance))
                };
                Sleep(100);
        }
        Sleep(99999);
    }
}