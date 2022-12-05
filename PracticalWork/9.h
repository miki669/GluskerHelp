#include <list>
#include <sstream>
#include <string>
#include <vector>
namespace practica
{
    //П9-1-10 Выведите на экран в алфавитном порядке все слова строки, в которых есть четыре подряд идущие согласные буквы.
    void split(const std::string& str, std::vector<std::string>& v)
    {
        std::stringstream ss(str);
        ss >> std::noskipws;
        std::string field;
        char ws_delim;
        while (1)
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
        std::string _String;
        std::string s;
        std::string consonants = "bcdfghjlkmnpqrstvwxz";
        std::cout << "Input string!" << std::endl;
        std::getline(std::cin, _String);
        std::vector<std::string> stringlist;
        split(_String, stringlist);
        //std::copy(stringlist.begin(), stringlist.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
        //std::cout << "\n";
        std::vector<std::string>::value_type variableString;
        // std::vector<std::string>::value_type variableList;
        std::list<std::string> variableList;
        
        int count = 1;
        for (auto& i : stringlist)
            for (char j : i)
                for (const char consonant : consonants)
                     if (j == consonant)
                     {                                      
                         if(variableString == i)
                         {
                             count++;
                             if(count >= 4)
                             {                                 
                                 printf("Good\n");
                                 variableList.push_back(variableString);                                 
                             }
                         }
                         else
                         {
                             count = 1;
                         }
                         variableString = i;                             
                     }
        
        for (auto& i : variableList)
        {
            std::cout << i;
        }
        return 0;
}       
        
        
}       