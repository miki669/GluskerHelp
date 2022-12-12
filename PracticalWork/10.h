#include <set>

namespace practica
{
    //П10-0-16 Даны две строки, вывести на экран символы, которые встречаются в обоих.
    void P10016()
    {
        std::string s;
        std::cout<< "Input 1 string " << std::endl;
        std::getline(std::cin,s);
        std::set<char> a(s.begin(),s.end());
        std::cout<< "Input 2 string " << std::endl;
        std::getline(std::cin,s);
        std::set<char> b(s.begin(),s.end());
        std::cout << "repeated letters" << std::endl;
        set_intersection(a.begin(), a.end(),
                         b.begin(), b.end(),
                         std::ostream_iterator<char>(std::cout, "\n"));
    }
}
