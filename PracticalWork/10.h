#include <set>

namespace practica
{
    //P -10 Дана строка. Есть ли в ней совпадающие символы?
    void P10023()
    {
        std::string _string;
        std::cout << "Input string! " << std::endl;
        std::getline(std::cin, _string);   
        for (int i = 0; i < _string.length(); i++)
            for (int j = 0; j < _string.length(); j++)
                if (_string[i] == _string[j] && i != j)
                {
                    std::cout << "YES" << std::endl;
                    return;
                }
        std::cout << "NO" << std::endl;
    }

    std::set<char> f(std::string n)
    {
        std::set<char> s;
        for (char& i : n)
        {
            s.insert(i);
        }
        
        return s;
    }
    int main12() {
        std::string _string;
        std::set<char> x, y, result;
        std::cout << "Input String: ";
        std::cin >> _string;
        int a = 4;
        x = f(_string);
        set_intersection(
            x.begin(),
            x.end(),
            y.begin(),
            y.end(), inserter(result, result.begin()));//Создает отсортированный диапазон, начинающийся с сопоставления элементов, которые находятся в обоих отсортированных диапазонах

        if (!result.empty())
            {
                std::cout << "Общие цифры:\n";
                copy(result.begin(), result.end(), std::ostream_iterator<int>(std::cout, " "));
            }
        else
            {
                std::cout << "Одинаковые цифры в числе не найдены\n";
            }
        system("pause");
        return 0;
    }
}
