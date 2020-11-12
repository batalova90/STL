#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <functional>
#include <list>

class Shape
{
public:
	Shape();
	Shape(int x, int y);

	bool IsMoreLeft(Shape& othreShape);
	bool IsMoreLeft2(Shape* otherShape);
	bool IsUpper(Shape& otherShape);
	virtual void Draw() = 0;
	int XShapeGet() { return X; }
	bool IsUpper2(Shape* otherShape);
	int X{0};
	int Y{0}; //центр фигуры

};

class Circle : public Shape
{

public:
	Circle() : Shape() {};
	Circle(int X, int Y) : Shape(X, Y) {};
	void Draw();
};

class Triangle : public Shape
{

public:
	Triangle() : Shape() {};
	Triangle(int X, int Y) : Shape(X, Y) {};
	void Draw();
};

class Square : public Shape
{

public:
	Square() {};
	Square(int X, int Y) : Shape(X, Y) {};
	void Draw();
};

