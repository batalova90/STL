#include <stdio.h>
#include <list>
#include <random>
#include <ctime>
#include <iostream>
#include "PriorityList.h"

void randList(std::list<int>& list, int n)
{
    int number = 0;
    std::list<int>::iterator beg = list.begin();
    for (std::list<int>::iterator it = list.begin(); it != list.end(); ++it)
    {
        number = std::rand() % (20 + 1);
        *it = number;
    }

}

void printList(std::list<int>& list)
{
    int n = list.size() / 2;
    int count = 0;
    std::list<int>::iterator it_b = list.begin();
    std::list<int>::reverse_iterator it_en = list.rbegin();
    while (count < n)
    {
        std::cout << *it_b << " " << *it_en << " ";
        it_b++;
        it_en++;
        count++;
    }
    if (list.size() % 2 != 0)
    {
        std::cout << *it_b << " ";
    }
    std::cout << "\n";
}
void checkMemoryLeak()
{
    PriorityNode my("Kapec", normal);
}


int main()
{
    setlocale(LC_ALL, "ru");
    int size = 15;
    std::list<int> myList(15);
    std::srand(std::time(nullptr));

    randList(myList, size);
    for (auto iterator = myList.begin(); iterator != myList.end(); iterator++)
    {
        std::cout << *iterator << " ";
    }
    std::cout << "\n\nРазмер листа: " << myList.size() << "\n";

    printList(myList);

    PriorityNode myPriority("Normal1", normal);
    myPriority.pushElement("High1", high);
    myPriority.pushElement("Low1", low);
    myPriority.pushElement("Normal2", normal);
    myPriority.pushElement("High2", high);
    myPriority.pushElement("Normal3", normal);
    myPriority.pushElement("Low2", low);
    myPriority.pushElement("Low3", low);
    std::cout << "Top: "  << myPriority.frontPriority() << "\n";
    std::cout << "Back: " << myPriority.backPriority() << "\n";
    std::cout << myPriority << "\n\n";
    std::cout << "\tMethod Accelerate: \n";
    myPriority.Accelerate();
    std::cout << "Top: " << myPriority.frontPriority() << "\n";
    std::cout << "Back: " << myPriority.backPriority() << "\n";

    myPriority.pushElement("Low4", low);
   
    std::cout << myPriority;


    return 0;
}


