#include "dataAnalys.h"



void generateNumbers(std::vector<int>& vectorForGenerateNumbers) //rand array
{
    int number = 0;
    for (int i = 0; i < vectorForGenerateNumbers.size(); ++i)
    {
        number = (-500) + rand() % 1001;
        vectorForGenerateNumbers[i] = number;
    }

}

void printArray(int number)
{
    std::cout << number << std::endl;

}

int main()
{
    srand(time(0));
    std::vector<int> myV(10);
    generateNumbers(myV);
    for_each(myV.begin(), myV.end(), printArray);
    DataAnalysisFunctor myF;
    for (auto it : myV)
        myF(it);
    myF.PrintDataAnalysis();
    return 0;
}
