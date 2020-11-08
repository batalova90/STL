/*1.	��������� ���������� ���������� �����.���� ����� ��������� :
.����� � ������� �� ��������� �������� � ��������� ����, � ����� ����, ������ ����� ������ ���� �� ����� 20 ��������
.����� ���������� � �.�, �, � �!� � ? � � : � �; �
.���������� ������� � ������, ���������, ������ ����� ������.

.	��������������� ����� ��������� ������� :
.�� ������ ����  ���������� �������� �������� �� �������(else, ��� �������� �� �������) +
.�� ������ ���� ������ ����� ������ ������� +
.����� ������ � ������ ���������� �� ������ ���� ������� +
.����� ����� ���������� ������ ������ ���� ������ +
.����� ������ ����� 10 �������� ���������� �� ����� �Vau!!!� +

.	������������� ���������� ����� � ����� ������, ������ �� ������� �������� ����� ���������� �����
(����� ������ ������� ���������� � ������) � �� ������ �� ��������� 40 ��������.
*/
#include <string>
#include "Header.h"
#include <iostream>

std::ostream& operator << (std::ostream& out, const std::vector<std::string> strings)
{

	for (int i = 0; i < strings.size(); i++)
	{
		if (!strings[i].empty())
			std::cout << "������ [ " << i << " ] " << strings[i] <<  "\t\t����� ������: "<< strings[i].length() <<std::endl;
		
	}
	return out;
}

int main()
{
	setlocale(LC_ALL, "ru");
	std::string fileName = "main.cpp";
	std::string str;
	
	readFile(fileName, str);
	//std::cout << "\n\n�������� ������: \n" << str;
	formatting(str);

	//�������� �� ���������������
	std::string formated("ie%rvgho dgrsdv ddssdvsdvvvegd navhivh i ,b vhjo0bgf nhnjsdcd\t\tdtnbt\ngnbdgnghtn\n,");
	std::cout << "\n\n����������� ������: \n" << formated << "\n";
	formatting(formated);
	std::cout << "\n�� ������: \n" << formated << "\n";

	//���������� ������ �����
	std::vector<std::string> setStrings(str.length(), "");
	
	std::cout << "\n\n�������� ������: \n" << str;

	convertingStrings(str, setStrings);
	
	std::cout << "\n\n������ �����: \n";
	std::cout << setStrings << std::endl;
	
	return 0;
}