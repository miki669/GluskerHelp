#include <filesystem>
#include <sstream>

namespace practica
{
    //П8-1-1 Дан квадратный двумерный массив, повернуть его на 90 градусов по часовой стрелке без использования второго массива.
    int P811()
    {
        int n;
        
        printf("Enter row of the matrix\n");
        scanf_s("%i",&n);
        // printf("Enter col of the matrix\n");
        // scanf_s("%i",&col);

        float** matrix = new float*[n];
        for(int i = 0; i < n; ++i)
            matrix[i] = new float[n];
        int p=0,q=0;
        
        for(unsigned i=0;i<n;i++) {
            for(unsigned j=0;j<n;j++) {
                std::cout<<"Enter the ["<<i+1<<"]*["<<j+1<<"] entry\n";
                std::cin>>matrix[i][j];
            }
        }
        printf("After:\n");
        for(auto i=0;i<n;i++)
            {
                for(auto j=0;j<n;j++)
                {
                    std::cout<<"|"<<matrix[i][j]<<"|";
                }
            std::cout<<std::endl;
        }
        printf("Before:\n");
        int tmp;
        for(int i = 0; i < n; i++)
        {
            //транспонирование
            //построчный обмен между элементами левой и правой частями матрицы 
            for(int j = i; j < n; j++)
                std::swap(matrix[i][j], matrix[j][i]);
            for(int j = 0; j < n / 2; j++)
                std::swap(matrix[i][j], matrix[i][n - j - 1]);
        }
        for(auto i=0;i<n;i++)
        {
            for(auto j=0;j<n;j++)
            {
                std::cout<<"|"<<matrix[i][j]<<"|";
            }
            std::cout<<std::endl;
        }
        system("pause");
        return 0;
    }
    


}
