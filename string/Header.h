#pragma once
#include <string>
#include <vector>
#include <iostream>



void readFile(const std::string& filename, std::string& buffer);


bool letter(const char str);

void changeString(std::string& sourceString, int& counter, int& number);

void checkPunctuation(std::string& sourceString, int& i);

void checkSpace(std::string& sourceString, int& i);


void changeSpace(std::string& sourceString, int i);


void formatting(std::string& sourceString);

void convertingStrings(std::string& sourceString, std::vector<std::string>& setStrings);
