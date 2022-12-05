#include <algorithm>

namespace practica
{
    void P716()
    {
        const std::pmr::string s = "[Sum items] ------------- [Replay  items]";
        int n;
        int const size = 10;
        int Array1[size], swap, Array2[size];
        int countDigit = 0;
        int countIdentic = 0;
        std::cout << "input size array: " << std::endl;
        std::cin >> n;
        std::cout << "input " << n << " count for array: " << std::endl;
        for (int i = 0; i < n; i++)
        {
            std::cout << "i[" << i + 1 << "]: ";
            std::cin >> Array1[i];
            Array2[i] = Array1[i];
        }
        //count
        for (int i = 0; i < 10; i++)
        {
            countDigit = 0;
            for (; Array1[i] > 0; countDigit++)
            {
                Array1[i] /= 10;
            }
            Array2[i] = countDigit;
        }
        std::sort(Array1, Array1 + n);
        for (int i = n - 1; i >= 0; i--)
        {
            std::cout << i << "- [" << Array2[i] << "]" << std::endl;
        }
        std::cout<< std::endl << s; 
        for (int i = n - 1; i >= 0; i--)
        {
            countIdentic = 0;
            for (int j = 0; j < n; j++)
            {
                if (Array2[i] == Array2[j])
                {
                    countIdentic++;
                }
            }
            std::cout << "\n|" << Array2[i] << "        |               |            " << countIdentic << "|";
        }
        std::cout << std::endl << s << std::endl;
        system("pause");
    }
}
