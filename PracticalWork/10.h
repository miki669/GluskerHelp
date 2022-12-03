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
}