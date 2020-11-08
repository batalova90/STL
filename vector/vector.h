#pragma once
#include <vector>
#include <string>

void CountingSortOperator(std::vector<int>& sourceVector, int maxElement);
void QuickSortAt(std::vector<double>& sourceArray);
void QuickSortAt(std::vector<int>& sourceArray);
void QuickSortOperator(std::vector<int>& sourceArray);

void readFile(const std::string& filename, std::string& buffer);

void PrintConsoleVector(const std::vector<int>& vector, const std::string& nameVector);
void PrintConsoleVector(const std::vector<double>& vector, const std::string& nameVector);
void QuickSort2(std::vector<int>& array);
