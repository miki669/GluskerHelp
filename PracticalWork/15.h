namespace practica
{
    //П15-1-4 Напишите функцию, которая в данном натуральном числе, входящим в диапазон типа longint
    //(или аналогичного типа для языков, отличных от Free Pascal),
    //оставляет только нечётные цифры.
    
    vector<long int> RemovingEvenNumbers(long int number)
    {
        vector<long> test;
        long int number1 =0;
        if (number%2 == 0) --number;
        // операция % находит остаток от деления одного числа на другое. если этот остаток равен нулю, то из переменной n вычитается 1
        // операция -- выитает единицу из переменной n (n изменяется)
 
        // в этом цикле нужно вывести все нечетные числа от 1 до n (n - нечетное число)
        for (int i=1; i<=number; i+=2)         // в конце каждого цикла переменная n увеличивается на 2
            test.push_back(i);                  // будет выведено 1 3 5 7 9 ... n     
        
        return test;
    }
    void ParseOddNumbers  (long long n, vector<int>& vec)
    {
        if(n%2 != 0)
            vec.push_back (n%10);
        int temp = n / 10;  
        if (temp == 0 ) return;
        ParseOddNumbers  (temp, vec);
    }
        
    int P1514()
    {
        long long n;
        printf("Enter number: ");
        cin >>n;
        vector <int> vec;
        ParseOddNumbers  (n, vec);
        copy (vec.rbegin(), vec.rend(), ostream_iterator <int> (cout));
        cout << endl;
        return 0;
    }
}
