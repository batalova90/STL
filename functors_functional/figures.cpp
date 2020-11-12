#include "figures.h"



Shape::Shape() : X(0), Y(0) {};
Shape::Shape(int x, int y) : X(x), Y(y) {};
bool Shape::IsMoreLeft(Shape& otherShape)  //левее ли this фигура, чем переданная
{
    return this->X < otherShape.X;
}
//Попробовать вызвать методы в дочерних классах
bool Shape::IsUpper(Shape& otherShape) //выше ли this фигура, чем переданная
{
    return this->Y > otherShape.Y;
}

bool Shape::IsMoreLeft2(Shape* otherShape)
{
    return this->X < otherShape->X;
}

bool Shape::IsUpper2(Shape* otherShape)
{
    return this->Y > otherShape->Y;
}




//Circle.cpp


void Circle::Draw()
{
    std::cout << "Name of figure: circle\t" << "center of figure: (" << X << " , " << Y << " )\n\n";
}



void Triangle::Draw()
{
    std::cout << "Name of figure: triangle\t" << "center of figure: (" << X << " , " << Y << " )\n\n";
}



void Square::Draw()
{
    std::cout << "Name of figure: square\t" << "center of figure: (" << X << " , " << Y << " )\n\n";
}


