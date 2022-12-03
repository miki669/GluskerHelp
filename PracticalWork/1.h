#include <iostream>

namespace practica
{
    
    void p1()
    {
        int number;
        int quad = 0;
        int rem = 0;
        std::cout << "Input int \n";
        std::cin >> number;
        rem = number % 4;
        number = number / 4;
        quad += (pow(10, 0) * rem);
        rem = number % 4;
        number = number / 4;
        quad += (pow(10, 1) * rem);
        rem = number % 4;
        number = number / 4;
        quad += (pow(10, 2) * rem);
        rem = number % 4;
        number = number / 4;
        quad += (pow(10, 3) * rem);
        rem = number % 4;
        number = number / 4;
        quad += (pow(10, 4) * rem);
        rem = number % 4;
        number = number / 4;
        quad += (pow(10, 5) * rem);
        std::cout << quad;
    }
}
