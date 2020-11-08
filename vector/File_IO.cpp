#include "vector.h"
//#include <string>
#include <fstream>
#include <iostream>
#include <cmath>
#include <iomanip>
 
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
            //std::cerr << buffer;
        }
    }
   
}


void PrintConsoleVector(const std::vector<int>& vector, const std::string& nameVector)
{
    std::cout << nameVector << std::endl;
    for (auto temp : vector)
    {
        std::cout << temp << " ";
    }

    std::cout << std::endl << " ----------------------------- " << std::endl;
}

void PrintConsoleVector(const std::vector<double>& vector, const std::string& nameVector)
{
    std::cout << nameVector << std::endl;
    for (auto temp : vector)
    {
        std::cout << std::fixed << std::setprecision(3) << temp << " ";
    }

    std::cout << std::endl << " ----------------------------- " << std::endl;
}
