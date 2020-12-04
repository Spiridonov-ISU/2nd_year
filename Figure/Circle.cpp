#include "Figure.h"
#include "Circle.h"

Circle::Circle(double r)
{
    this->radius = r;
}

double Circle::GetArea()
{
    return radius * radius * 3.14;
}

double Circle::GetPerimeter()
{
    return 2 * 3.14 * radius;
}