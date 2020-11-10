#include "dataAnalys.h"


void DataAnalysisFunctor::PrintDataAnalysis()
{
    std::cout << "Maximum: " << data.max << "\n";
    std::cout << "Minimum: " << data.min << "\n";
    std::cout << "Average in sequence: " << data.averageInSequence << "\n";
    std::cout << "Number of Positive: " << data.numberOfPositive << "\n";
    std::cout << "Number of negative: " << data.numberOfNegative << "\n";
    std::cout << "Sum of odds: " << data.sumOfOdd << "\n";
    std::cout << "Sum of even: " << data.sumOfEven << "\n";
    std::cout << "First number equals last: " << (data.last == data.first) << "\n";

}

void DataAnalysisFunctor::operator()(int x)
{
    if (x > data.max)
        data.max = x;
    if (x < data.min)
        data.min = x;
    if (x > 0)
        data.numberOfPositive++;
    if (x < 0)
        data.numberOfNegative++;

    //четность нечетность
    if (x % 2 == 0)
        data.sumOfEven += x;
    else
        data.sumOfOdd += x;

    //первый, последний   
    if (firstNumber)
    {
        data.first = x;
        firstNumber = 0;
    }

    data.last = x;


    //сумма и среднее значение    
    data.counter++;
    data.sum += x;
    data.averageInSequence = data.sum / data.counter;


}
