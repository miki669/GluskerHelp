namespace practica
{
    // П5-0-13 Напечатайте таблицу умножения
    int P5013()
    {
        const int size = 9;
        std::cout.width(4);
        std::cout << "X" << " | ";
        for (int i = 1; i <= size; i++)
        {
            std::cout.width(4);
            std::cout << i;
        }
        std::cout << std::endl;

        for (int i = 1; i <= size + 2; i++)
        {
            std::cout.width(4);
            std::cout << " - ";
        }
        std::cout << std::endl;

        for (int i = 1; i <= size; i++)
        {
            std::cout.width(4);
            std::cout << i << " | ";
            for (int j = 1; j <= size; j++)
            {
                std::cout.width(4);
                std::cout << i * j;
            }
            std::cout << std::endl;
        }

        std::cin.get();
        return 0;
    }
    int NOD(int i, int p)
    {
        while (i != p)
        {
            if (i > p)
            {
                i = i - p;
            }
            else
            {
                p = (p - i);
            }
        }
        return i;
    }
    //П5-1-3 Найти все натуральные числа, меньшие n и взаимно простые с p.(what a P??? Glusker)
    int p513()
    {
        int n, p, i, k = 0;
        printf("Input N>2: ");
        std::cin >> n;
        printf("Input P>1: ");
        std::cin >> p;
        if (n < 2 && p > 1)
        {
            printf("Error! N || P < 1 || 2");
            return 0;
        }
        printf("Int from 2 to %i ,mutually simple with %i\n", n - 1, p);
        for (i = 2; i != n - 1; i++)
        {
            if (NOD(i, p) == 1)
            {
                k = 1;
                printf("%i ", i);
            }
        }
        if (k == 0)
        {
            printf("There are no numbers that are mutually prime with %i", p);
        }
    }
}