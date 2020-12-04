#include "Figure.h"
#include "Rectangle.h"

Rectangle::Rectangle(double w, double h)
{
    this->width = w;
    this->height = h;
}

double Rectangle::GetArea()
{
    return width * height;
}

double Rectangle::GetPerimeter()
{
    return width * 2 + height * 2;
}