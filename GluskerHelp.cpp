#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
#include <cstdlib>
#include <cmath>
#include <string> 
#include <conio.h>
#include <windows.h>
#include <chrono>
#include <thread>
#include <cstdio>
#include <cstdlib>
#include <clocale>
#include <ctime>
#include <time.h>
#include <vector>
#include <io.h>
#include <fcntl.h>
#include <algorithm>
using namespace std;
//P -1
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
    cout<< quad;

}
//P -3
void p3017()
{    
    int b;
    double a;
    printf("Input B: ");
    cin >> b;
    printf("Input a: ");
    cin >> a;
    double c; //катет
    double result[4];
    
    if(b == 1) //а - периметр
    {
        c = a/(2 + sqrt(2));
        cout << "Perimetr: " << c;
        cout << "Mediana: " << sqrt(1.25)*c; //медиана
        cout << "Ploshad: " << c*c/2; // площадь
        cout << "Gipotenuza: " << sqrt(2)*c; // гипотенуза
        
    }
    
    else if(b == 2) //медиана
    {
        c = a/(2 + sqrt(2));
        cout << "Mediana: " <<c << endl;
        cout << "Perimetr: " << (2 + sqrt(2))*c << endl; //периметр
        cout << "Ploshad: " << c*c/2 << endl; // площадь
        cout << "Gipotenuza: " << sqrt(2)*c << endl; // гипотенуза
    }
    
    else if(b == 3) //площадь
    {
        c = a/(2 + sqrt(2));
        cout << "Ploshad: " <<c << endl;
        cout << "Perimetr: " << (2 + sqrt(2))*c << endl; //периметр
        cout << "Mediana: " << sqrt(1.25)*c << endl; // медиана
        cout << "Gipotenuza: " << sqrt(2)*c << endl; // гипотенуза
    }
    
    else if(b == 4) //гипотенуза
    {
        c = a/(2 + sqrt(2));
        cout << "Gipotenuza: " <<c << endl;
        cout << "Perimetr: " << (2 + sqrt(2))*c << endl; //периметр
        cout << "Mediana: " << sqrt(1.25)*c << endl; // медиана
        cout << "Ploshad: " << c*c/2 << endl; // площадь
    }    
}
//P -4
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
        vector<std::vector<int>> v(n, std::vector<int>(n));
    
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
    
            ++i; --j; n = n < 2 ? 0 : n - 2;
        }
    
        for (const auto& row : v)
        {
            for (int x : row) {
                // sleep_for(milliseconds(500)); FIX!
                // cout << setw(2);                 
                // SetConsoleTextAttribute(h, x); FIX!
                cout << x << ' ';
    
            }
            cout << endl;
        }
    
        cout << endl;
    }
    return 0;
}

int NOD(int i, int p)
{
    while (i != p)
    {
        if(i>p)
        {
            i = i-p;
        }
        else
        {
            p = (p-i);
        }
    }
    return i;
}
int P411() {
    // clrscr();
    int mas[15][15];
    int n=1,x=6,y=6,k=1;
    int i,j;
    while(1){
        mas[x][y]=k++;
        switch(n){
        case 1: x++;break;
        case 2: y--;break;
        case 3: x--;break;
        case 4: y++;break;
        }
        if(x==15) break;
        if(x==y && x<6) n=4;
        else if(x+y==12 && x<6) n=1;
        else if(x+y==12 && x>6) n=3;
        else if(x==y+1 && x>6) n=2;
    }
    for(i=0;i<15;i++)
    {
        for(j=0;j<15;j++)
        {
            // textcolor(12);
            if(mas[j][i]>2)
                for(k=2;k<mas[j][i];k++)
                    if(mas[j][i]%k==0) /*textcolor(15);*/
                        std::cout <<("%3d ",mas[j][i]);
        }
        std::cout<<("\n");
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
//P -5
// П5-0-13 Напечатайте таблицу умножения
int P5013()
{
    const int size = 9; 
    cout.width(4);
    cout << "X" << " | ";    
    for (int i=1; i <= size; i++)
    {
        cout.width(4);
        cout << i;
    }
    cout << endl;
 
    for (int i=1; i <= size+2; i++)
    {
        cout.width(4);
        cout << " - ";
    }
    cout << endl;
 
    for (int i=1; i <=size; i++)
    {
        cout.width(4);
        cout << i << " | ";
        for (int j=1; j <= size; j++)
        {
            cout.width(4);
            cout << i*j;
        }
        cout << endl;
    }
 
    cin.get();
    return 0;
}

//П5-1-3 Найти все натуральные числа, меньшие n и взаимно простые с p.(what a P??? Glusker)
int p513()
{
    int n, p,i,k=0;
    printf("Input N>2: ");
    cin >> n;
    printf("Input P>1: ");
    cin >> p;
    if(n<2 && p>1)
    {
        printf("Error! N || P < 1 || 2");
        return 0;
    }
    printf("Int from 2 to %i ,mutually simple with %i\n",n-1, p);
    for (i = 2; i!=n-1; i++)
    {
        if(NOD(i,p) ==1)
        {
            k =1;
            printf("%i ",i);
        }
    }
    if(k==0)
    {
        printf("There are no numbers that are mutually prime with %p",p);
    }
    
}


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
    do {
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
    printf("%f",sum);
    return 0;
}
//P -П7-1-6 Дан одномерный массив натуральных чисел. Выведите на экран таблицу, в которой перечислены сумма цифр элемента массива (без повторений, в порядке убывания) и сколько раз элементы с такой суммой цифр встречаются в массиве.
void P716()
{      
    setlocale(LC_ALL, "Ru");
   
    const string s = "[Sum items] ------------- [Replay  items]";
    int n;
    int const size = 999;
    
    int Array1[size], swap, Array2[size];
    int countDigit = 0;
    int countIdentic = 0;    
    
    cout << "input size array: " << endl;
    cin >> n;
    cout << "input " << n <<" count for array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "i[" << i+1 << "]: ";
        cin >> Array1[i];
        Array2[i] = Array1[i];
    }
    //count
    for (int i = 0; i < 10; i++) {
        countDigit = 0;
        for (;Array1[i] > 0;countDigit++) {
            Array1[i] /= 10;
        }
        Array2[i] = countDigit;
    }
    sort(Array1, Array1 + n);
    for (int i =  n -1; i>=0; i--)
    {
        cout << i << "- [" << Array2[i] << "]" << endl;
    }
    cout << s;
    for (int i =  n -1; i>=0; i--) {
        countIdentic = 0;
        for (int j = 0; j < n;j++) {
            if (Array2[i] == Array2[j]) {
                countIdentic++;
            }
        }
        cout << "\n|" << Array2[i] << "                 |                   " << countIdentic << "|";
    }
    cout <<endl<< s << endl;   
}
double my_asin(double x)
{
    int i = 0;
    double vypocet = x;
    double y = vypocet;
    for(i=1;i<=10000;i++)
    {
        vypocet*=((x*x)*(2*i-1)*(2*i-1))/((2*i)*(2*i+1));
        y+=vypocet;

    }
    cout << ("my_asin = %.10e\n", y);
    return y;
}
int P7LevelTwo()
{
    int b;
    double a;
    cout << "b" << endl;
    cin >> b;
    cout << "a" << endl;
    cin >> a;
    double c; //катет
    double result[4];

    if (a <= 0)
    {
        cout << "a < 0";
        return 0;
    }
    switch (b)
    {
    case 1:
        c = a / (2 + sqrt(2));
        result[1] = sqrt(1.25) * c; //медиана
        result[2] = c * c / 2; // площадь
        result[3] = sqrt(2) * c; // гипотенуза
        cout << "Mediana = " << result[1] << endl
             << "S = " << result[2] << endl
             << "Gipotenuza = " << result[3];
        break;
    case 2:
        c = a / sqrt(1.25);
        result[1] = (2 + sqrt(2)) * c; //периметр
        result[2] = c * c / 2; // площадь
        result[3] = sqrt(2) * c; // гипотенуза
        cout << "Perimetr = " << result[1] << endl
            << "S = " << result[2] << endl
            << "Gipotenuza = " << result[3];
        break;
    case 3:
        c = sqrt(2 * a);
        result[1] = (2 + sqrt(2)) * c; //периметр
        result[2] = sqrt(1.25) * c; // медиана
        result[3] = sqrt(2) * c; // гипотенуза
        cout << "Perimetr = " << result[1] << endl
            << "Mediana = " << result[2] << endl
            << "Gipotenuza = " << result[3];
        break;
    case 4:
        c = a / sqrt(2);
        result[1] = (2 + sqrt(2)) * c; //периметр
        result[2] = sqrt(1.25) * c; // медиана
        result[3] = c * c / 2; // площадь
        cout << "Perimetr = " << result[1] << endl
            << "Mediana = " << result[2] << endl
            << "S = " << result[3];
        break;
    default:
        cout << "Error!\nB = {1,2,3,4}";
        break;
    }
    return 0;
        
        
}

//П8-1-1 Дан квадратный двумерный массив, повернуть его на 90 градусов по часовой стрелке без использования второго массива.
int ** turn90 (int n, int **a) {
    int i,j;
    int **b;
    b = new int * [n];
    for (i=0; i<n; i++) b[i]= new int [n];
    for (i=0; i<n; i++)
        for (j=0; j<n; j++) {
            b[j][n-i-1]=a[i][j];
        }
    return b;
}
 
void out (const char *s, int n, int **a) {
    int i,j;
    printf ("\n%s",s);
    for (i=0; i<n; i++) {
        printf ("\n");
        for (j=0; j<n; j++) printf ("%d ",a[i][j]);
    }
}

int P811()
{
    int n;
    printf("Input size array ( N x N !>10)\n");
    scanf_s("%i",&n);
    if(n>10)
    {
        printf("N !> 10");
        return 0;      
    }
    
    int i, k=1;
    auto a = new int*[n];
    for (i=0; i<n; i++)
    {
        printf("input element\n");
        scanf_s("%i",&a[i]);   
        // a[i]= new int [n];
    
    }
    for (i=0; i<n; i++)
        for (int j = 0; j<n; j++)
            a[i][j]=k++;
    out ("Before array",n,a);
    int **b=turn90(n,a);
    out ("After array",n,b);
    
    return 0;
}
//P -9

//P -10 Дана строка. Есть ли в ней совпадающие символы?
void P10023()
{
    string _string;
    cout << "Input string! " << endl;
    cin >>  _string;
     for (int i = 0; i < _string.length(); i++)
         for (int j = 0; j < _string.length(); j++)
             if(_string[i] ==  _string[j] && i != j)                
             {
                 cout << "YES" << endl;
                 return;
             }
    cout << "NO" << endl;
   
}
//P -11

//P -12




int main()
{

    P811();


    
return 0;
}
