#include <charconv>
#include <iostream>
#include <ostream>
#include "TextTable.h"

namespace practica
{
    using namespace std;
    void d_command(int number)
    {
        std::cout << number << endl;
    }
    int i_command(string s, int number)
    {
        s.erase (0,1);
        return stoi(s) + number;
    }
    int m_command(string s, int number)
    {
        s.erase (0,1);
        return stoi(s) * number;
       
    }
    int r_command(string s,int number)
    {
        s.erase (0,1);
        std::size_t pos{};
        const int count {std::stoi(s, &pos)};
        s.erase (0,pos);
        for(int i =0; i< count; i++)
        {
            switch (s[0])
            {
                case 'i':
                    {
                        
                        number= i_command(s,number);
                    }
                break;
                
                case 'm':
                    {
                       number = m_command(s,number);
                    }
                break;
                
                case 'd':
                {
                        d_command(number);
                }
                break;
                
            }
        }
        return number;
    }
    
    void P13210()
    {       
        {
            
        TextTable t( '-', '|', '+' );
        t.add("Command");
        t.add("Syntax");
        t.add("Semantics");
        t.endOfRow();
        t.add( "i" );
        t.add( "i<int>" );
        t.add( "increase the working number by <number>" );
        t.endOfRow();
        t.add( "m" );
        t.add( "m<int>" );
        t.add( "increase the working number by <number> times" );
        t.endOfRow();
        t.add( "r" );
        t.add( "r<int><command>" );
        t.add( "repeat the command <number> times (command - i, m or d)" );
        t.endOfRow();
        t.add( "d" );
        t.add( "d" );
        t.add( "output number" );
        t.endOfRow();
        t.setAlignment( 2, TextTable::Alignment::RIGHT );
        std::cout << t;
        }
        std::string line;
        std::vector<string> v;
        int n;
        ifstream infile("13.txt");
        while (std::getline(infile, line))
        {
            v.push_back(line);
        }
        int number = 0;        
        for ( auto& s : v )
        {
             switch (s[0])
             {                 
             case 'i':
                 {
                     number = i_command(s,number);
                     break;
                 }
             case 'm':
                 {
                     number = m_command(s,number);
                     break;
                 }
             case 'r':
                 {
                     number = r_command(s,number);
                     break;
                 }
             case 'd':
                 {
                     d_command(number);
                     break;
                 }           
             }
        } 
        
        
    }
   
    //i5
    //m5
    //d
    //r2m5
    //r2d
}
