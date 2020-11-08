#include "Header.h"
//#include <string>
#include <fstream>
#include <iostream>



void readFile(const std::string& filename, std::string& buffer)
{
    std::ifstream fin(filename);
    std::string str;
    if (!fin.is_open())
        std::cout << "The file cannot be opened! " << "\n";
    else
    {
        while (!fin.eof())
        {
            getline(fin, str);
            buffer += str + "\n";
           
        }
    }
    //std::cerr << buffer;
}




