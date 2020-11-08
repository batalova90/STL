#include <iostream>
#include "vector.h"
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include "Profile.h"


template <typename T>
void RandomVector(std::vector<T>& array, T maxElement)
{
    //srand(time_t(NULL));
    for (int i = 0; i < array.size(); i++)
        array[i] = rand() % (maxElement + 1);
}

void doubleRandom(std::vector<double>& array, int size)
{
    double temp(0);
    for (int i = 0; i < size; i++)
    {
        temp = -1.0 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (1.0 + 1.0)));
        array.push_back(temp);
    }
}
//написать класс для расчета объема памяти для counting Sort

void checkCopyString(const std::vector<char>& copyString)
{
    std::cout << "Check copy in vector: " << std::endl;
    for (auto temp : copyString)
        std::cout << temp;
    std::cout << std::endl;
}

inline void addOne(const std::vector<int>& sourceArray, std::vector<int>& copyArray)
{
    for (std::vector<int>::const_iterator it = sourceArray.begin(); it != sourceArray.end(); it++)
    {
        if (*it % 3 == 0)
        {
            copyArray.push_back(*it);
            for (int i = 0; i < 3; i++)
                copyArray.push_back(1);
        }
        else
            copyArray.push_back(*it);
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int maxElement = 1000;
    int sizeVector = 10000;
    std::vector<int> sourceVector(sizeVector, 0);
    srand(time_t(NULL));

    RandomVector(sourceVector, maxElement);
    //PrintConsoleVector(sourceVector, "Source array: ");
    {
        LOG_DURATION("Counting Sort:");
        CountingSortOperator(sourceVector, maxElement);
    }
    //PrintConsoleVector(sourceVector, "Sorted array(countingSort): ");

    
    //QuickSort(at())
    RandomVector(sourceVector, maxElement);
    //PrintConsoleVector(sourceVector, "Source vector(quickSortAt): ");
    {
        LOG_DURATION("Quick Sort At:");
        try
        {
            QuickSortAt(sourceVector);  // throws a bad_typeid exception
        }
        catch (std::exception& e)
        {
            std::cout << "exception caught: " << e.what() << '\n';
        }
        
    }
    //PrintConsoleVector(sourceVector, "Sorted vector(quickSortAt): ");
    
    //QuickSortOperator
    RandomVector(sourceVector, maxElement);
    //PrintConsoleVector(sourceVector, "Source vector(quickSortOperator): ");
    {
        LOG_DURATION("Quick Sort Operator:");
        QuickSortOperator(sourceVector);
    }
    //PrintConsoleVector(sourceVector, "Sorted vector(quickSortOperator): ");
    
    //Iterator
    RandomVector(sourceVector, maxElement);
    //PrintConsoleVector(sourceVector, "Source vector(quickSortIterator): ");
    {
        LOG_DURATION("Quick Sort Iterator: ");
        //QuickSort2(sourceVector);
    }
    //PrintConsoleVector(sourceVector, "Sorted vector(quickSortIterator): ");

    //ReadFile
    std::string fileForRead("text.txt");
    std::string fileContents("");
    readFile(fileForRead, fileContents);
    std::vector<char> copyString(fileContents.begin(), fileContents.end());
    checkCopyString(copyString);

    
    //Ввод чисел, удаление четных, добавление единиц
    std::cout << "Enter the numbers:  ";
    int num;
    std::vector<int> addNumbers;
    std::vector<int> copyAddNumbers;
    std::cin >> num;
    //ввод массива
    while (num)
    {
        addNumbers.push_back(num);
        std::cin >> num;
    }
   
    if (!addNumbers.empty())
    {
        if (addNumbers[addNumbers.size() - 1] == 1)
        {
            for (std::vector<int>::iterator it = addNumbers.begin(); it != addNumbers.end(); it++)
            {
                if (*it % 2 != 0)
                    copyAddNumbers.push_back(*it);
            }
        }
        else if (addNumbers[addNumbers.size() - 1] == 2)
        {
            addOne(addNumbers, copyAddNumbers);
        }
        else
        {
            for (std::vector<int>::iterator it = addNumbers.begin(); it != addNumbers.end(); it++)
            {
                copyAddNumbers.push_back(*it);
            }
        }
        PrintConsoleVector(copyAddNumbers, "Массив: ");
    }
    
    //+exeption
    //Генератор случайных чисел с плавающей запятой
    {
        LOG_DURATION("Sorted double array: ")
        std::vector<double> doubleRandomVector;
        doubleRandom(doubleRandomVector, 10);
        PrintConsoleVector(doubleRandomVector, "Double Random: ");
        QuickSortAt(doubleRandomVector);
        PrintConsoleVector(doubleRandomVector, "Sorted double array: ");
    }

    
    
    return 0;

}