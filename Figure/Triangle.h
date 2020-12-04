#pragma once
#include "Figure.h"

class Triangle : public Figure
{
private:
    double A;
    double B;
    double C;
public:
    Triangle(double a, double b, double c);
    double GetArea();
    double GetPerimeter();
};