namespace practica
{
    //P-6-0-18 
    int P6018()
    {
        float border, summand;
        double f;
        printf("input border: ");
        scanf_s("%f", &border);
        float sum = 1 * 9 / 2 + 2 * 27 / 6;
        float fibprev = 2;
        float fibprevprev = 1;
        float part = 27;
        f = 3;
        double number = 6; //factorial
        do
        {
            float fib = fibprev + fibprevprev;
            fibprevprev = fibprev;
            fibprev = fib;
            f = f + 1;
            number = number * f;
            part = part * 3;
            summand = fib * part / number;
            sum = sum + summand;
        }
        while (summand > border);
        printf("%f", sum);
        return 0;
    }
}