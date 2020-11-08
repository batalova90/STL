#include <iostream>
#include <cstdlib>
#include "vector.h"


void CountingSort(std::vector<int>& sourceVector, int max)
{
    std::vector<int> buffer(max, 0);
    std::vector<int> sortedArray(sourceVector.size(), 0);

    for (int i = 0; i < sourceVector.size(); i++)
        buffer[sourceVector[i]]++;

    //Какое кол-во эл-тов не превышает max
    for (int i = 1; i < max; i++)
        buffer[i] = buffer[i] + buffer[i - 1];

    for (int i = (sourceVector.size() - 1); i >= 0; i--)
    {
        sortedArray[buffer[sourceVector[i]] - 1] = sourceVector[i];
        buffer[sourceVector[i]]--;
    }

    sortedArray.swap(sourceVector);

}

void CountingSortOperator(std::vector<int>& sourceVector, int maxElement)
{
    int size = sourceVector.size();
    int maxElementSourceVector{ sourceVector[0] };
    int index{ 0 };


    //Поиск максимального элемента в исходном массиве
    for (int i = 0; i < size; i++)
    {
        if (maxElementSourceVector < sourceVector[i])
        {
            maxElementSourceVector = sourceVector[i];
            index = i;
        }
    }
    //Устанавливаем максимальный эл-т в конец массива
    int tmp = sourceVector[index];
    sourceVector[index] = sourceVector[size - 1];
    sourceVector[size - 1] = tmp;

    //Вызов функции через поиск максимального эл-та в массиве
    CountingSort(sourceVector, maxElementSourceVector + 1);

}

void ChangeElements(std::vector<int>& array, int left, int right)
{
    int temp = array.at(left);
    array.at(left) = array.at(right);
    array.at(right) = temp;
}


int Partition(std::vector<int>& array, int left, int right)
{
    int x = array.at(right);
    int i = left;
    for (int j = left; j <= right - 1; j++)
    {
        if (array.at(j) <= x)
        {
            ChangeElements(array, i, j);
            i++;
        }
    }
    ChangeElements(array, i, right);

    return i;
}

void QuickSort(std::vector<int>& sourceArray, int left, int right)
{
    int q;

    if (left < right)
    {
        q = Partition(sourceArray, left, right);
        QuickSort(sourceArray, left, q - 1);
        QuickSort(sourceArray, q + 1, right);
    }
}


void QuickSortAt(std::vector<int>& sourceArray)
{

    QuickSort(sourceArray, 0, sourceArray.size() - 1);

}

int Partition1(std::vector<int>& array, int left, int right)
{
    int x = array[right];
    int i = left;
    for (int j = left; j <= right - 1; j++)
    {
        if (array[j] <= x)
        {
            ChangeElements(array, i, j);
            i++;
        }
    }
    ChangeElements(array, i, right);

    return i;
}

void QuickSort1(std::vector<int>& sourceArray, int left, int right)
{
    int q;

    if (left < right)
    {
        q = Partition1(sourceArray, left, right);
        QuickSort1(sourceArray, left, q - 1);
        QuickSort1(sourceArray, q + 1, right);
    }
}

void QuickSortOperator(std::vector<int>& sourceArray)
{
    QuickSort1(sourceArray, 0, sourceArray.size() - 1);
}

void ChangeElements(std::vector<double>& array, int left, int right)
{
    double temp = array.at(left);
    array.at(left) = array.at(right);
    array.at(right) = temp;
}


int Partition(std::vector<double>& array, int left, int right)
{
    double x = array.at(right);
    int i = left;
    for (int j = left; j <= right - 1; j++)
    {
        if (array.at(j) <= x)
        {
            ChangeElements(array, i, j);
            i++;
        }
    }
    ChangeElements(array, i, right);

    return i;
}

void QuickSort(std::vector<double>& sourceArray, int left, int right)
{
    int q;

    if (left < right)
    {
        q = Partition(sourceArray, left, right);
        QuickSort(sourceArray, left, q - 1);
        QuickSort(sourceArray, q + 1, right);
    }
}


void QuickSortAt(std::vector<double>& sourceArray)
{

    QuickSort(sourceArray, 0, sourceArray.size() - 1);

}




using vector = std::vector<int>;
void ChangeElementsIt(vector& array, vector::iterator left, vector::iterator right)
{
    int temp = *left;
    *left = *right;
    *right = temp;
}
vector::iterator PartitionIt(vector& sourceArray, vector::iterator left, vector::iterator right)
{
    int x = *right;
    vector::iterator i = left;
    for (vector::iterator it = left; it <= right - 1; it++)
        //for (int j = left; j <= right - 1; j++)
    {
        if (*it <= x)
        {
            ChangeElementsIt(sourceArray, i, it);
            i++;
        }
    }
    ChangeElementsIt(sourceArray, i, right);

    return i;
}

void QuickSortIt(vector& sourceArray, vector::iterator left, vector::iterator right)
{
    vector::iterator q;
    //std::cerr << right - left << "\n";
    //std::cerr << sizeof(sourceArray) << std::endl;
    if (left < right)
    {
        q = PartitionIt(sourceArray, left, right);
        QuickSortIt(sourceArray, left, q - 1);
        QuickSortIt(sourceArray, q + 1, right);
    }
}

void QuickSort2(vector& array)
{
    QuickSortIt(array, array.begin(), array.end() - 1);
}



