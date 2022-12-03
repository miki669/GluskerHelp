namespace practica
{
    //П4-1-1 Заполните квадрат n на n по спирали в направлении часовой стрелки от наружной части квадрата к внутренней
    //цифрами от 0 до 9 (циклически)с последовательно меняющимися цветами, начиная с левого верхнего угла.
    int P411Matric()
    {
        setlocale(LC_ALL, "RU");
        while (true)
        {
            std::cout << "Input N count: (0 - Quit): ";

            size_t n = 0;
            std::cin >> n;
            if (!n) break;
            std::cout << std::endl;
            std::vector<std::vector<int>> v(n, std::vector<int>(n));

            size_t i = 0, j = n - 1;
            int value = n * n;
            while (n != 0)
            {
                size_t k = 0;
                do
                {
                    v[i][j--] = value--;
                }
                while (++k < n - 1);
                for (k = 0; k < n - 1; k++)
                    v[i++][j] = value--;
                for (k = 0; k < n - 1; k++)
                    v[i][j++] = value--;
                for (k = 0; k < n - 1; k++)
                    v[i--][j] = value--;

                ++i;
                --j;
                n = n < 2 ? 0 : n - 2;
            }

            for (const auto& row : v)
            {
                for (int x : row)
                {
                    // sleep_for(milliseconds(500)); FIX!
                    // cout << setw(2);                 
                    // SetConsoleTextAttribute(h, x); FIX!
                    std::cout << x << ' ';
                }
                std::cout << std::endl;
            }

            std::cout << std::endl;
        }
        return 0;
    }
    int P411()
{
    // clrscr();
    int mas[15][15];
    int n = 1, x = 6, y = 6, k = 1;
    int i, j;
    while (1)
    {
        mas[x][y] = k++;
        switch (n)
        {
        case 1: x++;
            break;
        case 2: y--;
            break;
        case 3: x--;
            break;
        case 4: y++;
            break;
        }
        if (x == 15) break;
        if (x == y && x < 6) n = 4;
        else if (x + y == 12 && x < 6) n = 1;
        else if (x + y == 12 && x > 6) n = 3;
        else if (x == y + 1 && x > 6) n = 2;
    }
    for (i = 0; i < 15; i++)
    {
        for (j = 0; j < 15; j++)
        {
            // textcolor(12);
            if (mas[j][i] > 2)
                for (k = 2; k < mas[j][i]; k++)
                    if (mas[j][i] % k == 0) /*textcolor(15);*/
                        std::cout << ("%3d ", mas[j][i]);
        }
        std::cout << ("\n");
    }
    return 0;
    // HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    // setlocale(LC_ALL, "Russian");
    // const int nmax = 20;
    // int x = 0, y = 0;//координаты
    // int increment = 1, cell = 1; //прирощение по +1 -1 , количество ячеек
    // int number = 0;//цифра от 0 до 9
    // int n;
    // metka:
    // cout << "Размер квадрата n= (MAX = 20)" << endl;
    // cin >> n;
    // if (n <= 0 || n > nmax) {
    //     goto metka;
    // }
    // system("cls");
    // SHORT countn = 1;
    // do
    // {
    //     gotoxy(x - 1, y);
    //
    //     SetConsoleTextAttribute(hConsole, countn);
    //     sleep_for(nanoseconds(5000));
    //     cout << number;
    //     x = x + increment;
    //     number += 1;
    //     cell += 1;
    //     if (number > 9) {
    //         number = 0;
    //     }
    //     else if (x > n) {
    //         x = n;
    //         increment = -increment;
    //         y += 1;
    //     }
    //     else if (x == 0) {
    //         x = 1;
    //         increment = -increment;
    //         y += 1;
    //     }
    //     countn++;
    // } while (cell <= n * n);
    // return 0;
}
}