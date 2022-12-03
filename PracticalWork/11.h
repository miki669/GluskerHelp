#include <fstream>
#include <stack>

namespace practica
{
    //П11-2-5 Выведите на экран список всех глобальных переменных, использованных в программе.
    int P1125()
    {
        std::vector<std::string> keywords = {"namespace", "enum", "int", "char", "string"};
        std::ifstream ifs("1.cpp");
        std::string s;
        std::stack<char> scopes;
        while (std::getline(ifs, s))
        {
            if (s.find("{") != std::string::npos)
            {
                scopes.push('{');
            }
            else if (s.find("}") != std::string::npos)
            {
                scopes.pop();
            }
            if (!scopes.empty())
            {
                continue;
            }
            bool is_global = true;
            for (auto iter = keywords.begin(); iter != keywords.end(); ++iter)
            {
                size_t idx = s.find(*iter);
                if (idx != std::string::npos)
                {
                    size_t end_idx = idx + iter->length();
                    if (s[end_idx] != ' ')
                    {
                        continue;
                    }
                    else
                    {
                        is_global = false;
                        break;
                    }
                }
            }
            if (s.find(";") != std::string::npos && s.find("(") == std::string::npos && s.find("#") == std::string::npos
                && s.find("{") == std::string::npos && s.find("}") == std::string::npos)
            {
                if (!is_global)
                {
                    std::cout << "Global: " << s << std::endl;
                }
           
            }
        }
        system("pause");
        return 0;
    }
}
