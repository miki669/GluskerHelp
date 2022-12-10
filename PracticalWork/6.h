namespace practica
{
    //P-6-0-18 
    int P6018()
    {
        float border,sum,summand,fib,fibprev,fibprevprev,part;
        double number,f;
        setlocale(0, "rus");
        printf("input border: ");
        scanf_s("%f", &border);
        sum = 1 * 9 / 2 + 2 * 27 / 6;//считаем первые два столбца
        fibprev = 2;
        fibprevprev = 1;
        part = 27; 
        f = 3;//факториал
        number = 6 ; 
        do {
            fib = fibprev + fibprevprev;// фибонначи 
            fibprevprev = fibprev;
            fibprev = fib;
            f = f + 1;//факториал
            number = number * f;
            part = part * 3;// степень 
            summand = fib * part / number; //третий столбец
            sum = sum + summand; // считает дальнейшие столбцы
        }
        while (summand > border);
        printf("%f\n",sum);
        system("pause");
        return 0;
    }
}