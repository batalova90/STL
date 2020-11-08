#include <vector>
#include <algorithm>
#include <conio.h>
#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>

struct DataStruct
{
private:
    int key1{ 0 };
    int key2{ 0 };
    std::string str{ "" };
public:
    //generateData(); //внешней функцией!
    void setKeys(int key1_, int key2_);
    void setString(const std::string& str_);
    bool operator < (const DataStruct& data) const;
    friend std::ostream& operator << (std::ostream& out, std::vector<DataStruct>& myV);


};

void DataStruct::setKeys(int key1_, int key2_)
{
    key1 = key1_;
    key2 = key2_;
}

void DataStruct::setString(const std::string& str_)
{
    str = str_;
}

bool DataStruct::operator < (const DataStruct& data) const
{
    if (key1 == data.key1)
    {
        if (key2 == data.key2)
        {
            return str.size() < data.str.size();
        }
        else
            return key2 < data.key2;
    }
    else
        return key1 < data.key1;

}

void addData(std::vector<DataStruct>& myV)
{

    std::vector<std::string> arrayStr{ "movie", "music", "books", "sport", "swimming", "painting",
                                        "dancing", "singing", "basketball", "volleyball" };
    int temp1, temp2, numberStr;
    for (int i = 0; i < myV.size(); i++)
    {
        temp1 = (std::rand() % 11) - 5;
        temp2 = (std::rand() % 11) - 5;
        myV[i].setKeys(temp1, temp2);
        numberStr = (std::rand() % arrayStr.size());
        myV[i].setString(arrayStr[numberStr]);

    }



}

std::ostream& operator << (std::ostream& out, std::vector<DataStruct>& myV)
{
    for (int i = 0; i < myV.size(); i++)
    {
        out << "Key 1: " << myV[i].key1 << "\tKey 2: " << myV[i].key2 << "\tData: " << myV[i].str << "\n";
    }

    return out;
}



int main()
{
    srand(time(0));
    int size = 20;
    std::vector<DataStruct> myVector(20);
    addData(myVector);
    std::cout << "Source array: \n";
    std::cout << myVector;
    std::cout << "Sorted array: \n";
    std::sort(myVector.begin(), myVector.end());
    std::cout << myVector;

    return 0;
}