#include "figures.h"

class NumberPi
{
public:
	double operator()(double x)
	{
		return x * 3.14;
	}
};

double Rand()
{
	double out = rand() % 1000 * 0.1;

	return out;
}

void Print(double number)
{
	std::cout << number << std::endl;
}

void MultiplicationByPi()
{

	std::vector <double> mainVector(10);
	generate(mainVector.begin(), mainVector.end(), Rand);
	std::cout << "\nSource array: \n";
	for_each(mainVector.begin(), mainVector.end(), Print);

	NumberPi pi; //????
	std::cout << "\nMultiplication by Pi :\n";
	transform(mainVector.begin(), mainVector.end(), mainVector.begin(), pi);
	for_each(mainVector.begin(), mainVector.end(), Print);
}


Shape* randShapePointer()
{
	int numberOfShape = rand() % 3;
	int x = rand() % 100;
	int y = rand() % 100;


	if (numberOfShape == 0) //circle
	{
		Shape* current = new Circle(x, y);
		return current;
	}
	else if (numberOfShape == 1) //triangle
	{
		Shape* current = new Triangle(x, y);
		return current;
	}
	else //square
	{
		Shape* current = new Square(x, y);
		return current;
	}
}

bool predicatLeft(Shape* b, Shape* a)
{
	return a->IsMoreLeft(*b);
}



int main()
{
	srand(time(0));
	MultiplicationByPi();

	//generate pointer shape

	std::cout << "----------------Second Task----------------\n";
	std::list<Shape*> myShape(4);
	generate(myShape.begin(), myShape.end(), randShapePointer);
	std::cout << "Source list:\n";
	for_each(myShape.begin(), myShape.end(), std::mem_fun(&Shape::Draw)); //mem_fun - > Shape::Draw

		//Sort

	myShape.sort(std::mem_fun(&Shape::IsMoreLeft2));

	std::cout << "--------------Sorted List--------------\n from left to right: \n";

	for_each(myShape.begin(), myShape.end(), std::mem_fun(&Shape::Draw));
	std::cout << "\n\n from right to left: \n";
	for_each(myShape.rbegin(), myShape.rend(), std::mem_fun(&Shape::Draw));

	std::cout << "\n\n from top to down: \n";
	myShape.sort(std::mem_fun(&Shape::IsUpper2));
	for_each(myShape.begin(), myShape.end(), std::mem_fun(&Shape::Draw));

	std::cout << "\n\n from down to top: \n";
	myShape.sort(std::mem_fun(&Shape::IsUpper2));
	for_each(myShape.rbegin(), myShape.rend(), std::mem_fun(&Shape::Draw));

	return 0;
}
