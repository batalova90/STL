/*1.	Прочитать содержимое текстового файла.Файл может содержать :
.Слова – состоят из латинских строчных и заглавных букв, а также цифр, длинна слова должна быть не более 20 символов
.Знаки препинания – «.», «, » «!» « ? » « : » «; »
.Пробельные символы – пробел, табуляция, символ новой строки.

.	Отформатировать текст следующим образом :
.Не должно быть  пробельных символов отличных от пробела(else, все заменяем на пробелы) +
.Не должно идти подряд более одного пробела +
.Между словом и знаком препинания не должно быть пробела +
.После знака препинания всегда должен идти пробел +
.Слова длиной более 10 символов заменяются на слово «Vau!!!» +

.	Преобразовать полученный текст в набор строка, каждая из которых содержит целое количество строк
(слово должно целиком находиться в строке) и ее длинна не превышает 40 символов.
*/
#include <string>
#include "Header.h"
#include <iostream>

std::ostream& operator << (std::ostream& out, const std::vector<std::string> strings)
{

	for (int i = 0; i < strings.size(); i++)
	{
		if (!strings[i].empty())
			std::cout << "Строка [ " << i << " ] " << strings[i] <<  "\t\tДлина строки: "<< strings[i].length() <<std::endl;
		
	}
	return out;
}

int main()
{
	setlocale(LC_ALL, "ru");
	std::string fileName = "main.cpp";
	std::string str;
	
	readFile(fileName, str);
	//std::cout << "\n\nИсходная строка: \n" << str;
	formatting(str);

	//Проверка на форматируемость
	std::string formated("ie%rvgho dgrsdv ddssdvsdvvvegd navhivh i ,b vhjo0bgf nhnjsdcd\t\tdtnbt\ngnbdgnghtn\n,");
	std::cout << "\n\nПроверочная строка: \n" << formated << "\n";
	formatting(formated);
	std::cout << "\nНа выходе: \n" << formated << "\n";

	//добавление набора строк
	std::vector<std::string> setStrings(str.length(), "");
	
	std::cout << "\n\nИсходная строка: \n" << str;

	convertingStrings(str, setStrings);
	
	std::cout << "\n\nМассив строк: \n";
	std::cout << setStrings << std::endl;
	
	return 0;
}