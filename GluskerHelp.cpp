#include <iostream>
#include <chrono>
#include "Header.h"
using namespace std;

int main()
{
    practica::P811();
  
    return 0;
}

double my_asin(double x)
{
    int i = 0;
    double vypocet = x;
    double y = vypocet;
    for (i = 1; i <= 10000; i++)
    {
        vypocet *= ((x * x) * (2 * i - 1) * (2 * i - 1)) / ((2 * i) * (2 * i + 1));
        y += vypocet;
    }
    cout << ("my_asin = %.10e\n", y);
    return y;
}


