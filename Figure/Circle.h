#pragma once
#include "Figure.h"

class Circle : public Figure
{
private:
    double radius;
public:
    Circle(double r);
    double GetArea();
    double GetPerimeter();
};