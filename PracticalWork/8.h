namespace practica
{
    //П8-1-1 Дан квадратный двумерный массив, повернуть его на 90 градусов по часовой стрелке без использования второго массива.
    void out(const char* s, int n, int** a)
    {
        printf("\n%s", s);
        for (int i = 0; i < n; i++)
        {
            printf("\n");
            for (int j = 0; j < n; j++) printf("%d ", a[i][j]);
        }
    }
    int** turn90(int n, int** a)
    {
        int i, j;
        int** b;
        b = new int*[n];
        for (i = 0; i < n; i++) b[i] = new int [n];
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
            {
                b[j][n - i - 1] = a[i][j];
            }
        return b;
    }    
    int P811()
    {
        int n;
        printf("Input size array ( N x N !>10)\n");
        scanf_s("%i", &n);
        if (n > 10)
        {
            printf("N !> 10");
            return 0;
        }

        int i, k = 1;
        auto a = new int*[n];
        for (i = 0; i < n; i++)
        {
            // printf("input element\n");
            // scanf_s("%i",&a[i]);   
            a[i] = new int [n];
        }
        for (i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                a[i][j] = k++;
        out("Before array", n, a);
        int** b = turn90(n, a);
        out("After array", n, b);

        return 0;
    }

}