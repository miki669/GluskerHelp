namespace practica
{
    int p3017()
    {
        int b;
        double a;
        printf("Input B: ");
        std::cin >> b;
        printf("Input a: ");
        std::cin >> a;
        double c; //катет
        double result[4];
        if (a <= 0)
        {
            std::cout << "a < 0";
            return 0;
        }
        if (b == 1) //а - периметр
            {
            c = a / (2 + sqrt(2));
            std::cout << "Perimetr: " << c;
            std::cout << "Mediana: " << sqrt(1.25) * c; //медиана
            std::cout << "Ploshad: " << c * c / 2; // площадь
            std::cout << "Gipotenuza: " << sqrt(2) * c; // гипотенуза
            }    

        else if (b == 2) //медиана
            {
            c = a / (2 + sqrt(2));
            std::cout << "Mediana: " << c << std::endl;
            std::cout << "Perimetr: " << (2 + sqrt(2)) * c << std::endl; //периметр
            std::cout << "Ploshad: " << c * c / 2 << std::endl; // площадь
            std::cout << "Gipotenuza: " << sqrt(2) * c << std::endl; // гипотенуза
            }

        else if (b == 3) //площадь
            {
            c = a / (2 + sqrt(2));
            std::cout << "Ploshad: " << c << std::endl;
            std::cout << "Perimetr: " << (2 + sqrt(2)) * c << std::endl; //периметр
            std::cout << "Mediana: " << sqrt(1.25) * c << std::endl; // медиана
            std::cout << "Gipotenuza: " << sqrt(2) * c << std::endl; // гипотенуза
            }    

        else if (b == 4) //гипотенуза
            {
            c = a / (2 + sqrt(2));
            std::cout << "Gipotenuza: " << c << std::endl;
            std::cout << "Perimetr: " << (2 + sqrt(2)) * c << std::endl; //периметр
            std::cout << "Mediana: " << sqrt(1.25) * c << std::endl; // медиана
            std::cout << "Ploshad: " << c * c / 2 << std::endl; // площадь
            }
    return 0;
    }
}