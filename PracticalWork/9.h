#pragma once
#include <set>
#include <sstream>
#include <string>
#include <vector>

namespace practica
{
    //hello bbbb
    //bbbbb => cccc
    //П9-1-10 Выведите на экран в алфавитном порядке все слова строки, в которых есть четыре подряд идущие согласные буквы.
    void split(const std::string& str, std::vector<std::string>& v)
    {
        std::stringstream ss(str);
        ss >> std::noskipws;
        std::string field;
        char ws_delim;
        while (true)
        {
            if (ss >> field)
                v.push_back(field);
            else if (ss.eof())
                break;
            else
                v.push_back(std::string());
            ss.clear();
            ss >> ws_delim;
        }
    }

int p9110()
{
        std::string consonants = "bcdfghjlkmnpqrstvwxz";//Список согласных букв
        std::string _String;
        std::set <std::string> StringArray;
        std::cout << "Input string!" << std::endl;
        std::getline(std::cin, _String);// ввод строки
        
        int count = 0;
        bool flag = false;
        std::vector<std::string> _String1;
        split(_String, _String1);//разделение по словам
        for (auto& i : _String1) // проходим по каждому слову
            for (char k : i) // проходим по каждой буквк
            {               
                if(consonants.find(k) != std::string::npos)// ищем в списке соответсвующую букву
                {
                    flag = true;
                    count++;
                    if(count>=4 && flag)
                    {
                        StringArray.insert(i);
                    }
                }
                else
                {
                    flag = false;
                    count=0;
                }
            }
        std::cout << "After string!" << std::endl;
        for(auto& l : StringArray) //вывод множество(set)
            std:: cout << l << std::endl;
        return 0;
        
        
}       
        
        
}       