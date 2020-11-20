/*�������� ��������� � ����������� ������.
������(��� � �������) ������ �������� � ����� - ���� STL - ����������(vector ��� list), ������ ������ ����������,
����� �� ���� ���������� �� �������� ������, ����� ����� ������ � ��������� � ���������� ����� ����������(��������: ����������� typedef).*/
#include <vector>
#include <algorithm>
#include <string>
#include <iterator>
#include <iostream>

//��������� �� List
class PhoneBook
{
private:
    std::string name{ "empty" };
    std::string phoneNumber{ "empty" };
public:
    PhoneBook() : name("empty"), phoneNumber("empty") {};
    PhoneBook(const PhoneBook& record) : name(record.getName()), phoneNumber(record.getNumber()) {};
    PhoneBook(const std::string& name_, const std::string& number) : name(name_), phoneNumber(number) {};
    PhoneBook& operator = (const PhoneBook& record)
    {
        setName(record.getName());
        setPhone(record.getNumber());
        return *this;
    }
    std::string getName() const { return name; }
    void setName(const std::string& name_) { name = name_; }
    std::string getNumber() const { return phoneNumber; }
    void setPhone(const std::string& number_) { phoneNumber = number_; }
    std::string getPhoneBook() const { return ("Name: " + getName() + "\t Phone number: " + getNumber() + "\n"); }

};

//������ phoneBook!!!!!
typedef std::vector<PhoneBook> PhoneBookArray;
PhoneBookArray::iterator iteratorPhoneBook; //������� static??��� �������� global
PhoneBookArray dataBase;
std::string help()
{
    return "help, 0 - show help.\n"
        "reset, 1 - retern to first recorn in phonebook.\n"
        "curr, 2 - show current record\n"
        "next, 3 - move to next record\n"
        "prev, 4 - move to previous record\n"
        "nextn, 5 - skip several records\n"
        "prevn, 6 - skip several records backwards\n"
        "before, 7 - insert a record before the current\n"
        "after, 8 - insert a record after the current\n"
        "back , 9 - insert a record at the end of the database\n"
        "change , 10 - change the current record\n";
}

template<class T> std::string modifyRecord(T iter) //�������� ������, �� ������� ��������� ��������
{
    std::string name_;
    std::string phoneNumber_;
    std::cout << "Enter name and number of phone: \n";
    std::cin >> name_ >> phoneNumber_;
    PhoneBook record(name_, phoneNumber_);
    *iter = record;
    //������� �������� �� ������ �������
    iteratorPhoneBook = dataBase.begin();

    return "New note: " + record.getPhoneBook();

}

std::string reset() //������� ��������� � ������ ������
{
    iteratorPhoneBook = dataBase.begin();
    return iteratorPhoneBook->getPhoneBook();
}

std::string curr() //������� �������� ��������
{
    return iteratorPhoneBook->getPhoneBook();
}

std::string next() //��������� ������
{
    ++iteratorPhoneBook;
    if (iteratorPhoneBook != dataBase.end())
        return iteratorPhoneBook->getPhoneBook();
    else
        return "It was last note!\n";
}

std::string prev() //���������� ������
{
    if (iteratorPhoneBook != dataBase.begin())
    {
        --iteratorPhoneBook;
        return iteratorPhoneBook->getPhoneBook();
    }
    else
        return "It was first note!\n";

}

std::string nextn() //������ �� n
{
    int position;
    std::cout << "Enter position: \n";
    std::cin >> position;

    //��������� �� ����� �� �������
    std::advance(iteratorPhoneBook, position);
    return iteratorPhoneBook->getPhoneBook();
}

std::string prevn() //����� �� n
{
    int position;
    std::cout << "Enter position: \n";
    std::cin >> position;
    if (position > 0)
        return "Position must be negative";
    std::advance(iteratorPhoneBook, position);
    //��������� �� ����� �� �������
    std::advance(iteratorPhoneBook, position);
    return iteratorPhoneBook->getPhoneBook();
}

std::string cmdHandler(std::string cmd)
{
    try {
        if (cmd == "help") {
            return help();
        }
        else if (cmd == "reset") {
            return reset();
        }
        else if (cmd == "curr") {
            return curr();
        }
        else if (cmd == "next") {
            return next();
        }
        else if (cmd == "prev") {
            return prev();
        }
        else if (cmd == "nextn") {
            return nextn();
        }
        else if (cmd == "prevn") {
            return prevn();
        }
        else if (cmd == "before") {
            // ������� ����� �������
            return modifyRecord(std::inserter(dataBase, --iteratorPhoneBook));
        }
        else if (cmd == "after") {
            // ����� ��������
            return modifyRecord(std::inserter(dataBase, iteratorPhoneBook));
        }
        else if (cmd == "back") {
            // � ����� ����������
            return modifyRecord(std::back_inserter<PhoneBookArray>(dataBase));
        }
        else if (cmd == "change") {
            // �������� ������, �� ������� ��������� ��������
            return modifyRecord(iteratorPhoneBook);
        }
        else {
            return "Invalid command! Type 'help' for a list of commands\n";
        }
    }
    catch (...) {
        return "Past-end iterator dereferenced!\n";
    }
}



int main()
{
    std::string temp[6][2] = { "Petrov", "123",
    "Ivanov", "456",
    "Sidorov", "789",
    "Pogodin", "234",
        "Baranov", "897",
        "Pomorova", "354" };
    //����������� ����������
    for (int i = 0; i < 6; ++i)
    {
        PhoneBook record(temp[i][0], temp[i][1]);
        dataBase.push_back(record);

    }

    std::cout << help();
    iteratorPhoneBook = dataBase.begin();

    std::transform(std::istream_iterator<std::string>(std::cin), std::istream_iterator<std::string>(), std::ostream_iterator<std::string>(std::cout), cmdHandler);
    return 0;
}
