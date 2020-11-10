#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <time.h>

struct DataAnalysis
{
    int max{ 0 };
    int min{ 0 };
    int averageInSequence{ 0 }; //среднее число в полсдовательности
    int numberOfPositive{ 0 };
    int numberOfNegative{ 0 };
    int sumOfOdd{ 0 }; //сумма нечетных
    int sumOfEven{ 0 }; //сумма четных
    int last{ 0 };
    int first{ 0 };
    int sum{ 0 };
    int counter{ 0 };
};

class DataAnalysisFunctor
{
    DataAnalysis data;
    bool firstNumber;
public:
    DataAnalysisFunctor() : data(),//data.max(0), data.min(0), data.averageInSequence(0),
                            //data.numberOfPositive(0), data.numberOfNegative(0),
                            //data.sumOfOdd(0), data.sumOfEven(0), data.last(0),
                            //data.first(0), data.sum(0), data.counter(0),
        firstNumber(1) {};
    void PrintDataAnalysis();
    void operator()(int x);

};
