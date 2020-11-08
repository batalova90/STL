#include <cstddef>
#include "Header.h"
#include <iostream>


std::string punctuationMarks{ ".,!?:;" };
std::string spaceSymbol{ 9, 10, 32 };
std::string alphabet{ "abcdefghijklmnopqarstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789" };



bool letter(const char str) //���������� ��� ����� � ��������
{
    if (alphabet.find(str) == std::string::npos)
        return 0;
    else
        return 1;
}

void changeString(std::string& sourceString, int& counter, int& number)
{
    std::string change("Vau!!!");
    std::string::iterator start = sourceString.begin();

    std::size_t found = sourceString.find_first_of(spaceSymbol, (number - counter));
    //counterSymbol++;
    if (found != std::string::npos) //���� ����� ���������� ������ �� ����� ������
    {
        sourceString.replace(start + number - counter, start + found, change); //������ � ���-�� ��������!!!
        number = number - counter + change.length() - 1;
        counter = 0;
    }
    else
    {
        sourceString.replace((number - counter), sourceString.length() - 1, change);
        counter = 0;

    }
}

void checkPunctuation(std::string& sourceString, int& i)
{
    //������� ������ �����
    std::string::iterator start = sourceString.begin();
    std::size_t found = sourceString.find_first_of(alphabet, i + 1);
    std::string change{ sourceString[i] };
    
    if (found != std::string::npos) //���� ���������� �� ����� � ����� ������
        sourceString.replace(start + i, start + found, change + " ");
    else if (sourceString[i + 1] == '\0' && sourceString[i] == ',') //���� ��������� ���� � ������ ","
        sourceString[i] = '.';

    //�������� �� ��, ��� ����� ����� ���������� �� ����� ���������� ������
    change = sourceString[i];
    if (i != 0 && spaceSymbol.find(sourceString[i - 1]) != std::string::npos)
        sourceString.replace(sourceString.begin() + i - 1, sourceString.begin() + i + 1, change);
    i++;
    //std::cerr << sourceString << std::endl;

}

void checkSpace(std::string& sourceString, int& i)
{
    //�� ����� ������ �������
    std::string::iterator start = sourceString.begin();
    std::string change{ sourceString[i] };
    if (sourceString[i + 1] != ' ')
    {
        std::size_t found_symbol = sourceString.find_first_of(alphabet, i + 1); //������� ������ �����
        std::size_t found_punctuation = sourceString.find_first_of(punctuationMarks, i + 1); //���� ������� ���� ����������
        if (found_punctuation != std::string::npos or found_symbol != std::string::npos) //�.� ����� ������
        {
            if (found_symbol < found_punctuation) //���� ������ ����������� �����, �� �������� �� ������ �� �����
                sourceString.replace(start + i, start + found_symbol, change);
            else //����� �� ����� ����������
                sourceString.replace(start + i, start + found_punctuation, change);
        }
        /*else
        /{
           / sourceString.replace(start + i, start + i + 2, change);
        }*/
       
    }
}

void changeSpace(std::string& sourceString, int i)
{
    sourceString[i] = ' ';
}

void formatting(std::string& sourceString)
{
    int counterSymbol(0);

    for (int i = 0; i < sourceString.length(); i++)
    {
        if (letter(sourceString[i])) //"������ �����"
        {
            if (counterSymbol < 10)
            {
                counterSymbol++;
            }

            else //�������� ��������� �� "Vau!!!"
            {
                changeString(sourceString, counterSymbol, i);
            }

        }
        else if (punctuationMarks.find(sourceString[i]) != std::string::npos && spaceSymbol.find(sourceString[i + 1]) == std::string::npos) //"������ ���� ����������", ��������� ������ �� ����������
        {
            counterSymbol = 0;
            checkPunctuation(sourceString, i);

        }
        else if (spaceSymbol.find(sourceString[i]) != std::string::npos) //������ ������!
        {
            counterSymbol = 0;
            checkSpace(sourceString, i);
        }
        //else //������ ������������ ������
        //{
           // counterSymbol = 0;
            //changeSpace(sourceString, i);
        //}


    }
    //std::cerr << sourceString << std::endl;
}

void convertingStrings(std::string& sourceString, std::vector<std::string>& setStrings)
{
    int counterSymbol(1);
    std::string::iterator saveIterator = sourceString.begin();
    std::size_t found_space;
    //int size = sourceString.size() / 39;
    //nt size_modulo = sourceString.size() % 39;
    int j = 0;
    //std::cout << "������ �����: " << std::endl;
    for (int i = 0; i < sourceString.size(); i++)
    {
    //    if (spaceSymbol.find(sourceString[39 + i * 39]) != std::string::npos) // ���� 40-�� ������ ����������
    //    {
    //        setStrings[j].push_back(sourceString[i]);
    //        counterSymbol = 1;
    //        j++;
    //    }
    //    else 
    //    {
    //        found_space = sourceString.find_last_of(spaceSymbol, i*39);
    //        setStrings[j].push_back(sourceString[found_space + 1]);
    //        j++;
    //        i = i - (i - found_space); //???????????????????
    //        counterSymbol = 1;
    //    }
        if (counterSymbol <= 40)
        {
            setStrings[j].push_back(sourceString[i]);
            counterSymbol++;
        }
        else if (spaceSymbol.find(sourceString[counterSymbol - 1]) != std::string::npos)
        {
            j++;
            setStrings[j].push_back(sourceString[i]);
            counterSymbol = 1;
        }
        else
        {
            found_space = setStrings[j].find_last_of(spaceSymbol);
            setStrings[j].erase(found_space + 1, counterSymbol - found_space);
            j++;
            i = i - (counterSymbol - found_space); //???????????????????
            counterSymbol = 1;
        }
        
    }
    

}
